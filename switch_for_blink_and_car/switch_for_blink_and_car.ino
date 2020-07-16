int one = A2;
int two = A3;
int val = 0, val2 = 0;
void setup()
{
  unsigned int i;
  for (i = 1; i <= 5; i++)
    pinMode(i, INPUT);
  pinMode(A4, INPUT_PULLUP);

  unsigned int j;
  for (j = 3; j <= 13; j++)
    pinMode(j, OUTPUT);
}

void loop()
{
  unsigned int i;
  val = digitalRead(one);
  if (val == LOW)
  {
    for (i = 10; i <= 13; i++)
    {
      digitalWrite(i, HIGH); // turn the LED on (HIGH is the voltage level)
      delay(200);            // wait for a second
      digitalWrite(i, LOW);  // turn the LED off by making the voltage LOW
      delay(2);              // wait for a second
    }
  }
  else
  {
    for (i = 10; i <= 13; i++)
    {
      digitalWrite(i, LOW);
    }
  }
  //  int val=digitalRead(A4);
  //  digitalWrite(3, val);

  val2 = digitalRead(two);
  if (val2 == LOW)
  {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
