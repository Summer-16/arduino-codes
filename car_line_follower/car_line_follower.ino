/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = A0;
int pushButton1 = A1;

int M1_P = 3;
int M1_N = 4;
int M2_P = 5;
int M2_N = 6;

// the setup routine runs once when you press reset:
void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(pushButton1, INPUT);
  pinMode(M1_P, OUTPUT);
  pinMode(M1_N, OUTPUT);
  pinMode(M2_P, OUTPUT);
  pinMode(M2_N, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop()
{
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  int buttonState1 = digitalRead(pushButton1);

  // print out the state of the button:
  Serial.print(buttonState);
  Serial.print('/');
  Serial.println(buttonState1);
  //forware
  if (buttonState == 1 && buttonState1 == 1)
  {
    analogWrite(M1_P, 127);
    digitalWrite(M1_N, LOW);
    analogWrite(M2_P, 127);
    digitalWrite(M2_N, LOW);
  }
  else
      //left
      if (buttonState == 1 && buttonState1 == 0)
  {
    analogWrite(M1_P, 127);
    digitalWrite(M1_N, LOW);
    digitalWrite(M2_P, HIGH);
    digitalWrite(M2_N, HIGH);
  }
  //right
  else if (buttonState == 0 && buttonState1 == 1)
  {
    digitalWrite(M1_P, HIGH);
    digitalWrite(M1_N, HIGH);
    digitalWrite(M2_P, 127);
    analogWrite(M2_N, LOW);
  }
  //stop
  else if (buttonState == 0 && buttonState1 == 0)
  {
    digitalWrite(M1_P, HIGH);
    digitalWrite(M1_N, HIGH);
    digitalWrite(M2_P, HIGH);
    digitalWrite(M2_N, HIGH);
  }
  delay(1); // delay in between reads for stability
}
