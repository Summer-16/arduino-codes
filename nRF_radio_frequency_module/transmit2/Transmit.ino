/* Uses the RF24 Library by TMRH2o here:
  https://github.com/TMRh20/RF24
   1 - GND
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
#include <Keypad.h>
/*-----( Declare Constants and Pin Numbers )-----*/
//None yet
/*-----( Declare objects )-----*/
// (Create an instance of a radio, specifying the CE and CS pins. )
RF24 myRadio(7, 8); // "myRadio" is the identifier you will use in following methods
/*-----( Declare Variables )-----*/
byte addresses[][6] = {"1Node"}; // Create address for 1 pipe.
int dataTransmitted;             // Data that will be Transmitted from the transmitter

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
    {'*', '0', '#', 'D'},
    {'7', '8', '9', 'C'},
    {'4', '5', '6', 'B'},
    {'1', '2', '3', 'A'}};
byte rowPins[ROWS] = {6, 5, 4, 3};     //connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() /****** SETUP: RUNS ONCE ******/
{
  // Use the serial Monitor (Symbol on far right). Set speed to 115200 (Bottom Right)
  Serial.begin(115200);
  delay(1000);
  dataTransmitted = 0;     // Arbitrary known data to transmit. Change it to test...
  myRadio.begin();         // Start up the physical nRF24L01 Radio
  myRadio.setChannel(108); // Above most Wifi Channels
  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  myRadio.setPALevel(RF24_PA_MIN);
  //  myRadio.setPALevel(RF24_PA_MAX);  // Uncomment for more power

  myRadio.openWritingPipe(addresses[0]); // Use the first entry in array 'addresses' (Only 1 right now)
  delay(1000);
} //--(end setup )---

void loop() /****** LOOP: RUNS CONSTANTLY ******/
{
  char customkey = customKeypad.getKey();
  if (customkey == '3')
  {
    dataTransmitted = 3;
  }
  if (customkey == '6')
  {
    dataTransmitted = 6;
  }
  if (customkey == '7')
  {
    dataTransmitted = 7;
  }
  if (customkey == '8')
  {
    dataTransmitted = 8;
  }
  if (customkey == '0')
  {
    dataTransmitted = 0;
  }
  //myRadio.write(customKey); //  Transmit the data
  //myRadio.write( &customKey ); //  Transmit the data
  myRadio.write(&dataTransmitted, sizeof(dataTransmitted));
  //myRadio.write( &dataTransmitted, sizeof(dataTransmitted) );

  //  Serial.print(F("Data Transmitted = "));
  Serial.print(dataTransmitted);
  //  Serial.println(F(" No Acknowledge expected"));
  //  dataTransmitted = dataTransmitted + 1;  // Send different data next time
  //  delay(500);

} //--(end main loop )---

/*-----( Declare User-written Functions )-----*/
