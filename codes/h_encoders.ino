
void Turn_Rightninety()
{
  Righten_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(20), Right_Turns, RISING);
  while (Leften_Count > -180 || Righten_Count > -180)
  {
    if (Leften_Count > -180)
    {
      digitalWrite(Left_Dir1, LOW);
      digitalWrite(Left_Dir2, HIGH);
      analogWrite(Left_Speed, Left_Base);
    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);
    }
    
    if (Righten_Count > -180)
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, LOW);
      analogWrite(Right_Speed, Right_Base);
    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);
    }

  }
  Brake();
  delay(2000);
  Serial.println(Leften_Count);
  Leften_Count = 0;
  
  
}

void Turn_Leftninety()
{
  Leften_Count = 0;
  attachInterrupt(digitalPinToInterrupt(18), Left_Turns, RISING);
  attachInterrupt(digitalPinToInterrupt(20), Right_Turns, RISING);
  while (Leften_Count <180 || Righten_Count < 180)
  {
    if (Leften_Count <180)
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, LOW);
      analogWrite(Left_Speed, Left_Base);
    }
    else
    {
      digitalWrite(Left_Dir1, HIGH);
      digitalWrite(Left_Dir2, HIGH); 
      digitalWrite(Left_Speed, HIGH);
    }
    
    if (Righten_Count <180)
    {
      digitalWrite(Right_Dir1, LOW);
      digitalWrite(Right_Dir2, HIGH);
      analogWrite(Right_Speed, Right_Base);
    }
    else
    {
      digitalWrite(Right_Dir1, HIGH);
      digitalWrite(Right_Dir2, HIGH);  
      digitalWrite(Right_Speed, HIGH);
    }

  }
  Brake();
  delay(2000);
  Serial.println(Leften_Count);
  Leften_Count = 0;
  
  
}

void Left_Turns()
{
  
  if (digitalRead(Leften_A) && !digitalRead(Leften_B)) {
    
    Leften_Count-- ;
  }
  if (digitalRead(Leften_A) && digitalRead(Leften_B)) {
    Leften_Count++ ;
  } 
  //Serial.println(Righten_Count);
  //Righten_Count = Leften_Count + 1;
}



void Right_Turns()
{
  
  if (digitalRead(Righten_A) && !digitalRead(Righten_B)) {
    
    Righten_Count-- ;
  }
  if (digitalRead(Righten_A) && digitalRead(Righten_B)) {
    Righten_Count++ ;
  } 
  //Serial.println(Righten_Count);
  //Righten_Count = Leften_Count + 1;
}

