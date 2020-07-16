int pbtn = A5; //pbtn=pushbutton
// to make the A2 pushbutton input vale in a variable
void setup()
{
  // put your setup code here, to run once:
  pinMode(pbtn, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int bstate = digitalRead(pbtn); //bstate=button status
  //read the input pin
  digitalWrite(13, bstate);
  bstate = 1;
  delay(1); //delay between read for stability
}
