int sensor1 = A0;
int sensor2 = A1;
//int one=A2;

void setup()
{
  // put your setup code here, to run once:
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int s1 = digitalRead(sensor1);
  int s2 = digitalRead(sensor2);
  //int val=digitalRead(one);
  //if(val==LOW)
  //{
  if (s1 == HIGH || s2 == HIGH)
  {
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else
  {
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
  }
  //  }
}
