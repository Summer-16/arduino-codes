//  VARIABLES
int pulsePin = 0;  // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13; // pin to blink led at each beat
int fadePin = 5;   // pin to do fancy classy fading blink at each beat
int fadeRate = 0;  // used to fade LED on with PWM on fadePin

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;               // used to hold the pulse rate
volatile int Signal;            // holds the incoming raw data
volatile int IBI = 600;         // holds the time between beats, the Inter-Beat Interval
volatile boolean Pulse = false; // true when pulse wave is high, false when it's low
volatile boolean QS = false;    // becomes true when Arduoino finds a beat.

void setup()
{
  pinMode(blinkPin, OUTPUT); // pin that will blink to your heartbeat!
  pinMode(fadePin, OUTPUT);  // pin that will fade to your heartbeat!
  Serial.begin(9600);        // we agree to talk fast!
  interruptSetup();          // sets up to read Pulse Sensor signal every 2mS
                             // UN-COMMENT THE NEXT LINE IF YOU ARE POWERING The Pulse Sensor AT LOW VOLTAGE,
                             // AND APPLY THAT VOLTAGE TO THE A-REF PIN
                             //analogReference(EXTERNAL);
}

void loop()
{
  int a = BPM;
  Serial.println(a);
  delay(20);
}
