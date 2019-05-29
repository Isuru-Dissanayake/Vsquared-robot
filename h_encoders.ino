
void Turn_Leftninety()
{
  
  while (Leften_Count <= 50)
  {
    Turn_Left();
    Serial.println(Leften_Count);
  }
  
  Brake();
  delay(3000);
  Leften_Count = 0;
}

void Left_Turns()
{
  /*
  if (digitalRead(Leften_A) && !digitalRead(Leften_B)) {
    
    Leften_Count++ ;
  }
  if (digitalRead(Leften_A) && digitalRead(Leften_B)) {
    Left_Count-- ;
  } 
  */
  Leften_Count = Leften_Count + 1;
}
void Count()
{
  Leften_Count = Leften_Count + 1;
  //Serial.println(Leften_Count);
}

