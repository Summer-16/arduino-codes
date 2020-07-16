int a = 0;
int count = 0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  a = Serial.read();
  if ((a == 'W') || (a == 'w'))
  {
    Serial.println("incremented");
    count++;
    Serial.println(count);
    if (count % 2 == 0)
      Serial.println("even");
    else
      Serial.println("odd");
  }

  if ((a == 'S') || (a == 's'))
  {
    Serial.println("decremented");
    count--;
    Serial.println(count);
    if (count % 2 == 0)
      Serial.println("even");
    else
      Serial.println("odd");
  }
}
