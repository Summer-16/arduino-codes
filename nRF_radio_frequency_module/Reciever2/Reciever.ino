/* 
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 7
   4 - CSN to Arduino pin 8
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED

   */

/*-----( Import needed libraries )-----*/
#include <SPI.h>  // Comes with Arduino IDE
#include "RF24.h" // Download and Install (See above)
/*-----( Declare Constants and Pin Numbers )-----*/
//None yet
/*-----( Declare objects )-----*/
// (Create an instance of a radio, specifying the CE and CS pins. )
RF24 myRadio(7, 8); // "myRadio" is the identifier you will use in following methods
/*-----( Declare Variables )-----*/
byte addresses[][6] = {"1Node"}; // Create address for 1 pipe.
int dataReceived;                // Data that will be received from the transmitter

void setup() /****** SETUP: RUNS ONCE ******/
{
  // Use the serial Monitor (Symbol on far right). Set speed to 115200 (Bottom Right)
  Serial.begin(115200);
  delay(1000);
  Serial.println(F("RF24/Simple Receive data Test"));
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  myRadio.begin();         // Start up the physical nRF24L01 Radio
  myRadio.setChannel(108); // Above most Wifi Channels
  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  myRadio.setPALevel(RF24_PA_MIN);
  //  myRadio.setPALevel(RF24_PA_MAX);  // Uncomment for more power

  myRadio.openReadingPipe(1, addresses[0]); // Use the first entry in array 'addresses' (Only 1 right now)
  myRadio.startListening();

} //--(end setup )---

void loop() /****** LOOP: RUNS CONSTANTLY ******/
{

  if (myRadio.available()) // Check for incoming data from transmitter
  {
    while (myRadio.available()) // While there is data ready
    {
      myRadio.read(&dataReceived, sizeof(dataReceived)); // Get the data payload (You must have defined that already!)
    }
    // DO something with the data, like print it

    if (dataReceived == 3)
    {
      digitalWrite(6, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      Serial.println(dataReceived);
      Serial.print("F");
    }
    if (dataReceived == 6)
    {
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      Serial.println(dataReceived);
      Serial.print("B");
    }
    if (dataReceived == 7)
    {
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      Serial.println(dataReceived);
      Serial.print("R");
    }
    if (dataReceived == 8)
    {
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      Serial.println(dataReceived);
      Serial.print("L");
    }
    if (dataReceived == 0)
    {
      digitalWrite(6, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      Serial.println(dataReceived);
      Serial.print("S");
    }
    //Serial.print("Data received = ");
    //Serial.println(dataReceived);
  } //END Radio available

} //--(end main loop )---

/*-----( Declare User-written Functions )-----*/

//None yet
//*********( THE END )***********
