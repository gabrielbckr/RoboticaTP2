#include "Configuracao.h"
#include "Movimentacao.h"
#include "SensorDeLuz.h"
#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
char input;
bool r,g,b;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  // initialize serial communication with computer:
  Serial.begin(115200);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  if (Serial.available() > 0){
    input = Serial.read();
    switch(input){
      case 'R':
      case 'r':
        r = !r;
        if(r)
          digitalWrite(RED_PIN, HIGH);
        else
          digitalWrite(RED_PIN, LOW);
        break;
      case 'G':
      case 'g':
        g = !g;
        if(g)
          digitalWrite(GREEN_PIN, HIGH);
        else
          digitalWrite(GREEN_PIN, LOW);
        break;
      case 'B':
      case 'b':
        b = !b;
        if(b)
          digitalWrite(BLUE_PIN, HIGH);
        else
          digitalWrite(BLUE_PIN, LOW);
        break;
    }
  }
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(LDR_PIN);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(1);        // delay in between reads for stability
}
