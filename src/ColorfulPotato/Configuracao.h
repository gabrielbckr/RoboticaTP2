#ifndef __COLORFUL_POTATO__CONFIG__
#define __COLORFUL_POTATO__CONFIG__
#include "Arduino.h"

// Pinos dos LEDs
const int RED_PIN = 23; // Fio vermelho
const int GREEN_PIN = 25; // Fio azul
const int BLUE_PIN = 27; // Fio laranja; Fio marrom é o terra
// Pino do LDR
const int LDR_PIN = A8; // VCC=vermelho, GND=marrom, SIG(A0)=amarelo

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 20;


#endif 
