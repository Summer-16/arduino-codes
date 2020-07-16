
#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);

void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  //pervious code or the code to get the value send is the function to update or send data using gsm
  Send();
}
void Send()
{
  mySerial.println("AT");
  delay(1000);
  mySerial.println("AT+CPIN?");
  delay(1000);
  mySerial.println("AT+CREG?");
  delay(1000);
  mySerial.println("AT+CGATT?");
  delay(1000);
  mySerial.println("AT+CIPSHUT");
  delay(1000);
  mySerial.println("AT+CIPSTATUS");
  delay(2000);
  mySerial.println("AT+CIPMUX=0");
  delay(2000);
  mySerial.println("AT+CSTT=\"airtelgprs.com\"");
  delay(1000);
  mySerial.println("AT+CIICR");
  delay(3000);
  mySerial.println("AT+CIFSR");
  delay(2000);
  mySerial.println("AT+CIPSPRT=0");
  delay(3000);
  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
  delay(6000);
  mySerial.println("AT+CIPSEND");
  delay(4000);
  String str = "GET http://api.thingspeak.com/update?api_key=xxxxxxxxxx&field1=50";
  mySerial.println(str);
  delay(4000);
  mySerial.println((char)26);
  delay(5000);
  mySerial.println();
  mySerial.println("AT+CIPSHUT");
  delay(100);
}
