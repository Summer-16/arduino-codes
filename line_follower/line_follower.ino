int s1 = 0;
int s2 = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  s1 = digitalRead(A5);
  s2 = digitalRead(A4);
  if ((s1 == HIGH) && (s2 == HIGH))
  {
    analogWrite(10, 150);
    analogWrite(9, LOW);
    analogWrite(6, LOW);
    analogWrite(5, 150);
  }
  if ((s1 == LOW) && (s2 == HIGH))
  {
    analogWrite(10, 150);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
  }
  if ((s1 == HIGH) && (s2 == LOW))
  {
    analogWrite(10, 0);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 150);
  }
  if ((s1 == LOW) && (s2 == LOW))
  {
    analogWrite(10, LOW);
    analogWrite(9, LOW);
    analogWrite(6, LOW);
    analogWrite(5, LOW);
  }
}
