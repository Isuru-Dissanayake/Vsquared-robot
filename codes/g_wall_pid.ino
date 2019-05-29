float p = 20;   
float i = 0;
float d = 4;

float Left_Wall = 8;
float Right_Wall = 8;

float Wallerror=0;
float Wallpreerror = 0;
float Walltoterror = 0;

float Wallpower = 0;

void Wall_Error()
{
  Wallerror = Ldistance - Rdistance;
}

void Wall_PID()
{
  Wall_Error();
  Walltoterror += Wallerror;
  
  Wallpower = (p*Wallerror) + (d*(Wallerror-Wallpreerror));
  Wallpreerror = Wallerror;
  Wallerror = 0;
  Right_PWM = Right_Base + Wallpower;
  Left_PWM = Left_Base - Wallpower;
  if (Right_PWM > 255) {Right_PWM = 255;}
  if (Left_PWM > 255) {Left_PWM = 255;}
  
}

void Wall_Follow()
{
  Rsonar();
  Fsonar();
  if (Fdistance <= 8)
  {
    Brake();
    delay(1000);
    Turn_Left();
    delay(500);
    Brake();
    delay(1000);
  }
  else
  {
    Wall_PID();
    //Serial.println(Wallpower);
    Forward();
  }
}

