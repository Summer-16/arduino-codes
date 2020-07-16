int a = 0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  a = Serial.read();
  if ((a == 'A') || (a == 'a'))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    Serial.print("LEFT");
    delay(1000);
  }
  if ((a == 'D') || (a == 'd'))
  {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    Serial.print("RIGHT");
  }
  if ((a == 'W') || (a == 'w'))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    Serial.print("FORWARD");
  }
  if ((a == 'S') || (a == 's'))
  {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    Serial.print("BACKWARD");
  }
  if ((a == 'g') || (a == 'G'))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    Serial.print("TESTING ALL LED MUST GLOW");
  }
}
