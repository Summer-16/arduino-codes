#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>

SoftwareSerial espPort(10, 11); // RX, TX
ESP esp(&espPort, &Serial, 9);
REST rest(&esp);
boolean wifiConnected = false;

const int ESP8266_CHPD = 9;

const int relay1 = 2;
const int relay2 = 4;
const int relay3 = 7;
const int relay4 = 8;

boolean data1 = false;

char response[266];
char buff[64];
String strId, strData, strCode;
String strData_Last1;

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

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);

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

  esp.wifiConnect("xxxxx", "xxxxx");
  Serial.println("ARDUINO: system started");
}

void loop()
{

loop_start:

  esp.process();

  if (wifiConnected)
  {

    //char str_field1[6] , str_field2[6], str_field3[6], str_field4[6], str_field5[6] ;

    sprintf(buff, "/channels/142811/fields/1/last"); // field x last Data
    Serial.println(buff);

    rest.get((const char *)buff);
    //Serial.println("ARDUINO: send get");

    if (rest.getResponse(response, 266) == HTTP_STATUS_OK)
    {

      Serial.println("ARDUINO: GET successful");
      Serial.println(response);

      strId = "";
      strData = "";
      strCode = "";
      getData(); //GET DATA

      //Control OutPut
      if (strId == "0")
      {
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        data1 = true;
        Serial.println("ALL OFF");
      }

      if (strId == "1")
      {
        digitalWrite(relay1, LOW);
        data1 = true;
        Serial.println("1 ON");
      }

      if (strId == "2")
      {
        digitalWrite(relay1, HIGH);
        data1 = true;
        Serial.println("0010");
      }

      if (strId == "3")
      {
        digitalWrite(relay2, LOW);
        data1 = true;
        Serial.println("2 ON");
      }

      if (strId == "4")
      {
        digitalWrite(relay2, HIGH);
        data1 = true;
        Serial.println("2 OFF");
      }

      if (strId == "5")
      {
        digitalWrite(relay3, LOW);
        data1 = true;
        Serial.println("3 ON");
      }

      if (strId == "6")
      {
        digitalWrite(relay3, HIGH);
        data1 = true;
        Serial.println("3 OFF");
      }

      if (strId == "7")
      {
        digitalWrite(relay4, LOW);
        data1 = true;
        Serial.println("4 ON");
      }

      if (strId == "8")
      {
        digitalWrite(relay4, HIGH);
        data1 = true;
        Serial.println("4 OFF");
      }
    }

  } //if WifiConnected
}

void getData()
{
  int i = 0, j = 0, k = 0;

  for (i = 0; i < 10; i++)
  {

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
