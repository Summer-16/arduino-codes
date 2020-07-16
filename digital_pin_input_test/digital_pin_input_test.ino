int pin = 5;
void setup()
{
  pinMode(5, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  int val = digitalRead(pin);
  if (val == HIGH)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  delay(1);
}
