int s1 = 0;
int s2 = 0;
void setup()
{
  // put your setup code here, to run once:
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
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
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
  }
  if ((s1 == LOW) && (s2 == HIGH) || (s1 == HIGH) && (s2 == LOW) || (s1 == LOW) && (s2 == LOW))
  {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    delay(2000),
        digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    delay(2000);
  }
}
