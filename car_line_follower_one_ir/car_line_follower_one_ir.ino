int s = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  s = digitalRead(A5);
  while (s == 0)
  {
    analogWrite(10, 150);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 150);
    s = digitalRead(A5);
    if (s == 1)
      break;
  }
  while (s == 1)
  {
    analogWrite(10, 150);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
    s = digitalRead(A5);
    if (s == 0)
      break;
    delay(400);
    analogWrite(10, 0);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 150);
    s = digitalRead(A5);
    if (s == 0)
      break;
    delay(800);
  }
}
