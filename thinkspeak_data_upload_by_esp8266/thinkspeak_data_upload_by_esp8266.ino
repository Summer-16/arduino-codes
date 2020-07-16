
#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>

SoftwareSerial espPort(10, 11); // RX, TX
ESP esp(&espPort, &Serial, 9);
REST rest(&esp);
boolean wifiConnected = false;

const int ESP8266_CHPD = 9;

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
//unsigned long myChannelNumber = 230601;
//const char * myWriteAPIKey = "5HB9M1VA4AK42YKA";
void setup()
{

  Serial.begin(9600);
  espPort.begin(9600);

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

  esp.wifiConnect("esp", "00000000");
  Serial.println("ARDUINO: system started");
}

void loop()
{

loop_start:

  esp.process();

  if (wifiConnected)
  {

    //char str_field1[6],str_field2[6],str_field3[6],str_field4[6],str_field5[6];
    int a = analogRead(A0);
    int b = analogRead(A1);
    int c = analogRead(A2);
    int d = analogRead(A3);
    int e = analogRead(A4);

    sprintf(buff, "https://api.thingspeak.com/update.json?api_key=xxxxxxxxxxx&field1=%d", a); // field x last Data
    Serial.println(buff);
    rest.get((const char *)buff);
    Serial.println("ARDUINO: send Update Data");
    delay(15000);
  } //if WifiConnected
}
