void openGate() 
{
  for (gatePos = 0; gatePos <= 60; gatePos += 5) { 
    gateServo.write(gatePos);                                     
  }
  delay(1000);
  for (gatePos = 60; gatePos >= 0; gatePos -= 5) {
    gateServo.write(gatePos);                                    
  }
  delay(1000);
  
}
