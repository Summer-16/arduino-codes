
int a = 0;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void loop()
{
  // put your main code here, to run repeatedly:
  a = Serial.read();
  if ((a == 'Q') || (a == 'q'))
  {
    digitalWrite(5, HIGH);
    Serial.println("off");
  }
  if ((a == 'A') || (a == 'a'))
  {
    digitalWrite(5, LOW);
    Serial.println("on");
  }
  if ((a == 'W') || (a == 'w'))
  {
    digitalWrite(6, HIGH);
    Serial.println("off");
  }
  if ((a == 'S') || (a == 's'))
  {
    digitalWrite(6, LOW);
    Serial.println("on");
  }
  if ((a == 'E') || (a == 'e'))
  {
    digitalWrite(7, HIGH);
    Serial.println("off");
  }
  if ((a == 'D') || (a == 'd'))
  {
    digitalWrite(7, LOW);
    Serial.println("on");
  }
  if ((a == 'R') || (a == 'r'))
  {
    digitalWrite(8, HIGH);
    Serial.println("off");
  }
  if ((a == 'F') || (a == 'f'))
  {
    digitalWrite(8, LOW);
    Serial.println("on");
  }
}
