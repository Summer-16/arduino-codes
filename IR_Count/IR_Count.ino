int p1 = 3;
int p2 = 4;
int counter = 0;
int state1;
int state2;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int state1 = digitalRead(p1);
  int state2 = digitalRead(p2);

  if ((state1 == HIGH) && (state2 == LOW))
  {

    counter++;
    delay(1000);
    Serial.println(counter);
  }
  if ((state1 == LOW) && (state2 == HIGH))
  {
    counter--;
    delay(1000);
    Serial.println(counter);
  }
}
