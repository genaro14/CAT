void setup()
{
  pinMode( 2 , OUTPUT);
}

void loop()
{
  if (( ( analogRead( 7 ) ) > ( 60 ) ))
  {
    digitalWrite( 2 , LOW);
  }
  else
  {
    digitalWrite( 2 , HIGH);
  }
}


