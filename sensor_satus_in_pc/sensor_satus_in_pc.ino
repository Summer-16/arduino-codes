int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //making the pushbutton pin an input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  //read the input pin
  int sensor_status1 = analogRead(sensor1);
  int sensor_status2 = analogRead(sensor2);
  int sensor_status3 = analogRead(sensor2);
  //print out the state of button
  Serial.print("Sensor 1  ");
  Serial.println(sensor_status1);
  Serial.print("Sensor 2  ");
  Serial.println(sensor_status2);
  Serial.print("Sensor 3  ");
  Serial.println(sensor_status3);
  delay(1000);
}
