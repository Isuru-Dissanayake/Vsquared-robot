int Errorval[16] = {-6, -5, -4, -3, -2, -1, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6};

float Kp = 25;   
float Ki = 0;
float Kd = 4;

float Error=0;
float previousError = 0;
float totalError = 0;

float Power = 0;

void Error_Cal()
{
  for(int ii=0; ii<16; ii++)
  {
    Error = Error + sens[ii]*Errorval[ii];
    //Serial.println(sens[ii]);
  }
  
}                                                                                                                                                                         


void Line_PID()
{
  Error_Cal();
  totalError += Error;
  Power = (Kp*Error) + (Kd*(Error-previousError)) + (Ki*totalError);
  previousError = Error;
  //Serial.println(Power);
  if( Power>Base_PWM ) { Power = Base_PWM; }
  if( Power<-Base_PWM ) { Power = -Base_PWM; }
  Right_PWM = Right_Base - Power;
  Left_PWM = Left_Base + Power;
  if (Right_PWM > 255) {Right_PWM = 255;}
  if (Left_PWM > 255) {Left_PWM = 255;}
  /*
  Serial.print(Right_PWM);
  Serial.print("   ");
  Serial.print(Left_PWM);
  Serial.println("");
  */
  Error = 0;
  
}


