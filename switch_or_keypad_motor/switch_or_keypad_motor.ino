int s1 = 0;
1 int s2 = 0;
int s3 = 0;
int s4 = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
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
  s1 = digitalRead(A2);
  s2 = digitalRead(A3);
  s3 = digitalRead(A4);
  s4 = digitalRead(A5);
  if ((s1 == HIGH) && (s4 == HIGH))
  {
    analogWrite(10, 150);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 150);
  }
  if (s1 == HIGH)
  {
    analogWrite(10, 150);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
  }
  if (s2 == HIGH)
  {
    analogWrite(10, 0);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 150);
  }
  if ((s2 == HIGH) && (s3 == HIGH))
  {
    analogWrite(10, 0);
    analogWrite(9, 150);
    analogWrite(6, 150);
    analogWrite(5, 0);
  }
  else
  {
    analogWrite(10, 0);
    analogWrite(9, 0);
    analogWrite(6, 0);
    analogWrite(5, 0);
  }
}
