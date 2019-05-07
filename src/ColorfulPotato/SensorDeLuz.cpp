#include "SensorDeLuz.h"
#include "Configuracao.h"


int __LDR__;
void StartColorSensing(int pin = LDR_PIN){
    __LDR__ = pin;
}

char DetectColor()
{
  
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(DELAY_PARAM);
  int environmentBrightness = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    HIGH);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   LOW);
  delay(DELAY_PARAM);
  int redReflected  = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  LOW);
  digitalWrite(BLUE_PIN,   HIGH);
  delay(DELAY_PARAM);
  int blueReflected = analogRead(LDR_PIN);
  digitalWrite(RED_PIN,    LOW);
  digitalWrite(GREEN_PIN,  HIGH);
  digitalWrite(BLUE_PIN,   LOW);
  delay(DELAY_PARAM);
  int greenReflected  = analogRead(LDR_PIN);

  if(isBlue(redReflected, greenReflected , blueReflected)){
    return 'b';
  }
  if(isRed(redReflected, greenReflected , blueReflected)){
    return 'r';
  }
  if(isGreen(redReflected, greenReflected , blueReflected)){
    return 'g';
  }
  if(isYellow(redReflected, greenReflected , blueReflected)){
    return 'y';
  }
  if(isDark(redReflected, greenReflected , blueReflected)){
    return 'd';
  }
  else{
    return FAILED_TO_DETECT;    
  }
  
}


bool isBlue(int r, int g, int b){
  if(b > blue_threshold) return true;
  return false;
}
bool isYellow(int r, int g, int b){
  return false;
}
bool isRed(int r, int g, int b){
  if(r - g > 70){return true;}
  return false;
}


bool isGreen(int r, int g, int b){
  if(g > r) return true;
  return false;
}
bool isDark(int r, int g, int b){
  if(r+g+b < sum_rgb_dark_threshold) {return true;}
  return false;
}
