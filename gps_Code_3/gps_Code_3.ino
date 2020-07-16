#include <SoftwareSerial.h>
#include <TinyGPS.h>

long lat, lon; // create variable for latitude and longitude object
long lat1, lat2, lon1, lon2;
SoftwareSerial gpsSerial(2, 3); // create gps sensor connection rx,tx
TinyGPS gps;                    // create gps object

void setup()
{
  Serial.begin(9600);    // connect serial
  gpsSerial.begin(9600); // connect gps sensor
}

void loop()
{
  while (gpsSerial.available())
  { // check for gps data
    if (gps.encode(gpsSerial.read()))
    {                               // encode gps data
      gps.get_position(&lat, &lon); // get latitude and longitude
      // display position
      lat1 = lat / 1000000;
      lat2 = lat % 1000000;
      lon1 = lon / 1000000;
      lon2 = lon % 1000000;
      Serial.print("Position: ");
      Serial.print("lat: ");
      Serial.print(lat1);
      Serial.print(".");
      Serial.print(lat2);
      Serial.print(" "); // print latitude
      Serial.print("lon: ");
      Serial.print(lon1);
      Serial.print(".");
      Serial.println(lon2); // print longitude
    }
  }
}
