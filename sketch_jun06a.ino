int pinlevel;
char waterstat;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int pinlevel = analogRead(A0); // read input value
  char waterstat = analogRead(A0);
  
  if (pinlevel<341)
  {
   Serial.println(pinlevel);
   Serial.print("Low");
  }
  else if (pinlevel==341)
  { 
    Serial.println(pinlevel);
    Serial.print("Medium");
  }
   else if (pinlevel > 341)
  { 
    Serial.println(pinlevel);
    Serial.print("High");
  }
  delay(5000);
}
