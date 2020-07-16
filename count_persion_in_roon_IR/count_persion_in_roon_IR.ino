int s1 = 0;
int s2 = 0;
int a = 0;
int a1 = 0;
int b = 0;
int c = 0;
int num = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  s1 = digitalRead(A4);
  s2 = digitalRead(A5);
  if (s1 == HIGH)
  {
    b = 1;
    if ((s1 == HIGH) && (b == 1))
    {
      while (digitalRead(A4) == HIGH)
        ;
      delay(100);
      b = 2;
    }
    if ((s2 == HIGH) && (b == 2))
    {

      while (digitalRead(A5) == HIGH)
        ;
      /*Serial.println("someone enter in room");
//Serial.print("total no of person in room is");
Serial.print(a);*/
      b = 0;
      delay(100);
      a++;
    }
  }
  s1 = digitalRead(A4);
  s2 = digitalRead(A5);
  c = 2;
  if (s2 == HIGH)
  {
    c = 2;
    if ((s2 == HIGH) && (c == 2))
    {

      while (digitalRead(A5) == HIGH)
        ;
      c = 3;
      delay(100);
    }
    if ((s1 == HIGH) && (c == 3))
    {
      while (digitalRead(A4) == HIGH)
        ;

      //Serial.println("\nsomeone lefted the room");
      //Serial.print("\n");
      //Serial.print("total no of person in room is");
      //Serial.print(a1);
      delay(100);
      a1++;
      c = 2;
    }
  }
  num = a - a1;

  Serial.println("total no of person in room is");
  Serial.println(a);
  Serial.println(a1);
  Serial.println(num);
}
