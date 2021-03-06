
#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>

SoftwareSerial espPort(10, 11); // RX, TX
ESP esp(&espPort, &Serial, 9);
REST rest(&esp);
boolean wifiConnected = false;

const int ESP8266_CHPD = 9;

const int relay1 = 13;
const int relay2 = 3;
const int relay3 = 4;
const int relay4 = 5;

boolean data1 = false;
boolean data2 = false;
int loop_count = 0;

char response[266];
char buff[64];
String strId, strData, strCode;
String strData_Last1, strData_Last2;

void (*resetFunc)(void) = 0; //declare reset function at address 0

void clearBuffer(void)
{
  for (int i = 0; i < 266; i++)
  {
    response[i] = 0;
  }
}

void wifiCb(void *response)
{
  uint32_t status;
  RESPONSE res(response);

  if (res.getArgc() == 1)
  {
    res.popArgs((uint8_t *)&status, 4);
    if (status == STATION_GOT_IP)
    {
      Serial.println("WIFI CONNECTED");

      wifiConnected = true;
    }
    else
    {
      wifiConnected = false;
    }
  }
}

void setup()
{

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);

  Serial.begin(19200);
  espPort.begin(19200);

  esp.enable();
  delay(500);
  esp.reset();
  delay(500);
  while (!esp.ready())
    ;

  Serial.println("ARDUINO: setup rest client");
  if (!rest.begin("api.thingspeak.com"))
  {
    Serial.println("ARDUINO: failed to setup rest client");
    while (1)
      ;
  }

  /*setup wifi*/
  Serial.println("ARDUINO: setup wifi");
  esp.wifiCb.attach(&wifiCb);

  //esp.wifiConnect("SHIVAM","panditji9818228256@@%#$$");
  esp.wifiConnect("xxxx", "xxxxx");
  Serial.println("ARDUINO: system started");
}

void loop()
{

loop_start:

  esp.process();

  if (wifiConnected)
  {

    sprintf(buff, "/channels/129726/fields/1/last"); // field x last Data
    Serial.println(buff);

    rest.get((const char *)buff);
    //Serial.println("ARDUINO: send get");

    if (rest.getResponse(response, 266) == HTTP_STATUS_OK)
    {

      //Serial.println("ARDUINO: GET successful");
      //Serial.println(response);

      strId = "";
      strData = "";
      strCode = "";
      getData(); //GET DATA

      //Control OutPut
      if (strId == "1" || strId == "1.0" || strId == "1.00" || strId == "10")
      {
        digitalWrite(relay1, HIGH);
        data1 = true;
        Serial.println("HIGH");
      }

      if (strId == "0" || strId == "-1" || strId == "0.1" || strId == "0.10")
      {
        digitalWrite(relay1, LOW);
        data1 = false;
        Serial.println("LOW");
      }
    }

    sprintf(buff, "/channels/106223/fields/2/last"); // field x last Data
    Serial.println(buff);

    rest.get((const char *)buff);
    // Serial.println("ARDUINO: send get");

    if (rest.getResponse(response, 266) == HTTP_STATUS_OK)
    {

      //Serial.println("ARDUINO: GET successful");
      //Serial.println(response);

      strId = "";
      strData = "";
      strCode = "";
      getData(); // GET DATA

      //Control OutPut
      if (strData == "1" || strData == "1.0" || strData == "1.00")
      {
        digitalWrite(relay2, HIGH);
        data2 = true;
      }

      if (strData == "0" || strData == "-1" || strData == "0.1" || strData == "0.10")
      {
        digitalWrite(relay2, LOW);
        data2 = false;
        Serial.println("LOW");
      }
    }

    sprintf(buff, "/channels/129726/fields/1/last"); // field x last Data
    Serial.println(buff);

    rest.get((const char *)buff);
    //Serial.println("ARDUINO: send get");

    if (rest.getResponse(response, 266) == HTTP_STATUS_OK)
    {

      //Serial.println("ARDUINO: GET successful");
      //Serial.println(response);

      strId = "";
      strData = "";
      strCode = "";
      getData(); //GET DATA

      //Control OutPut
      if (strId == "1" || strId == "1.0" || strId == "1.00" || strId == "10")
      {
        digitalWrite(relay3, HIGH);
        data1 = true;
        Serial.println("HIGH");
      }

      if (strId == "0" || strId == "-1" || strId == "0.1" || strId == "0.10")
      {
        digitalWrite(relay3, LOW);
        data1 = false;
        Serial.println("LOW");
      }
    }

    sprintf(buff, "/channels/129726/fields/1/last"); // field x last Data
    Serial.println(buff);

    rest.get((const char *)buff);
    //Serial.println("ARDUINO: send get");

    if (rest.getResponse(response, 266) == HTTP_STATUS_OK)
    {

      //Serial.println("ARDUINO: GET successful");
      //Serial.println(response);

      strId = "";
      strData = "";
      strCode = "";
      getData(); //GET DATA

      //Control OutPut
      if (strId == "1" || strId == "1.0" || strId == "1.00" || strId == "10")
      {
        digitalWrite(relay4, HIGH);
        data1 = true;
        Serial.println("HIGH");
      }

      if (strId == "0" || strId == "-1" || strId == "0.1" || strId == "0.10")
      {
        digitalWrite(relay4, LOW);
        data1 = false;
        Serial.println("LOW");
      }
    }

  } //if WifiConnected

  else
  {

    hardReset();
    resetFunc();
  }
}

void getData()
{
  int i = 0, j = 0, k = 0;

  for (i = 0; i < 10; i++)
  {
    //          Serial.print("Data");
    //          Serial.print(i);
    //          Serial.print(" : ");
    //          Serial.print(response[i]);
    //          Serial.println("");

    if ((response[i] == '\r') || (response[i] == '\n'))
    {
    }
    else
    {
      strId += response[i];
    }

    if (response[i] == '\n')
    {
      i++;
      break;
    }
  }

  Serial.println("");
  Serial.print("ID : ");
  Serial.print(strId);

  for (j = i; j < (i + 20); j++)
  {

    if ((response[j] == '\r') || (response[j] == '\n'))
    {
    }
    else
    {
      strData += response[j];
    }

    if (response[j] == '\n')
    {
      j++;
      break;
    }
  }

  Serial.println("");
  Serial.print("Data : ");
  Serial.print(strData);
  //strData_Last = strData ;
  //Serial.println(strData.length());

  for (k = j; k < (j + 10); k++)
  {

    if ((response[k] == '\r') || (response[k] == '\n'))
    {
    }
    else
    {
      strCode += response[k];
    }

    if (response[k] == '\n')
    {
      break;
    }
  }

  Serial.println("");
  Serial.print("Code : ");
  Serial.print(strCode);
  Serial.println("");
}

boolean hardReset()
{
  String tmpData;

  digitalWrite(ESP8266_CHPD, LOW);
  delay(2000);
  digitalWrite(ESP8266_CHPD, HIGH);
  //delay(1000);
}
