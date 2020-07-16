

#include <Servo.h>

Servo myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to store the servo position

void setup()
{
  Serial.begin(9600);
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop()
{

  tservo(0, 360);
}

void tservo(int x, int y)
{
  if (x == 0 && y == 45)
  {
    myservo.write(0);
    delay(250);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 90)
  {
    myservo.write(0);
    delay(500);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 135)
  {
    myservo.write(0);
    delay(750);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 180)
  {
    myservo.write(0);
    delay(1000);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 225)
  {
    myservo.write(0);
    delay(1250);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 270)
  {
    myservo.write(0);
    delay(1500);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 315)
  {
    myservo.write(0);
    delay(1750);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 360)
  {
    myservo.write(0);
    delay(2000);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 0 && y == 0)
  {
    Serial.println("90");
    myservo.write(90);
  }

  if (x == 180 && y == 45)
  {
    myservo.write(0);
    delay(250);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 90)
  {
    myservo.write(0);
    delay(500);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 135)
  {
    myservo.write(0);
    delay(750);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 180)
  {
    myservo.write(0);
    delay(1000);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 225)
  {
    myservo.write(0);
    delay(1250);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 270)
  {
    myservo.write(0);
    delay(1500);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 315)
  {
    myservo.write(0);
    delay(1750);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 360)
  {
    myservo.write(0);
    delay(2000);
    Serial.println("90");
    myservo.write(90);
  }
  if (x == 180 && y == 0)
  {
    Serial.println("90");
    myservo.write(90);
  }
}
