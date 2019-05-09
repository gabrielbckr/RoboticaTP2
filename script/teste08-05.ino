#include "SensorDeLuz.h"

int avrEnvironment = 0;
void setup  (){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_PIN,OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
 /* int i=0;
 delay(3000);
 Serial.println("Calibrando...");
  while(i<10){
    avrEnvironment= avrEnvironment + analogRead(LDR_PIN);
    delay(1);
    i++;
  }

  avrEnvironment=avrEnvironment/10;
  Serial.print("Calibrado"); */
}

void loop(){
  DetectaCor();
  /*delay(500);
  int environmentBrightness = analogRead(LDR_PIN);
  Serial.print(avrEnvironment);
  Serial.print(", ");
  Serial.println(environmentBrightness);
  if((avrEnvironment-environmentBrightness)>70){

    Serial.println("OBJETO DETECTADO");
  } */
}
