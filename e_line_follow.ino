int All_Count = 0;
int Left_Count = 0;
int Right_Count = 0;

void Count_All()
{
  All_Count = 0;
  for(int i=0; i<8; i++)
  {
    if (sens[i] == 1) {All_Count += 1;}
  }
}

void Count_Left()
{
  Left_Count = 0;
  for(int i=0; i<4; i++)
  {
    if (sens[i] == 1) {Left_Count += 1;}
  }
}

void Count_Right()
{
  Right_Count = 0;
  for(int i=4; i<8; i++)
  {
    if (sens[i] == 1) {Right_Count += 1;}
  }
}

void Line_Follow()
{
  Ir_Sensor();
  
  Count_All();
  Count_Left();
  Count_Right();
  
  if (All_Count == 0 && Last_Read == 1)
  {
   while (sens[3] == 0)
   {
    Turn_Left(); 
    Ir_Sensor();
   }
    
  }
  
  else if (All_Count == 0 && Last_Read == 2)
  {
    while (sens[4] == 0)
    {
      Turn_Right();
      Ir_Sensor();
    }
  }
  
  if (All_Count == 8)
  {
    Brake();
    delay(4000);
  }
  
  else
  {
    Line_PID();
    Forward();
  }
 
}


