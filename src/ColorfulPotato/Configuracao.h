#ifndef __COLORFUL_CONFIDURACAO__
#define __COLORFUL_CONFIDURACAO__


#include "Arduino.h"
//Se acontecer problema de redefinicao, mudar A8

/*      LED E LDR    */
// Pinos dos LEDs
const int RED_PIN = 23; // Fio vermelho
const int GREEN_PIN = 25; // Fio azul
const int BLUE_PIN = 27; // Fio laranja; Fio marrom é o terra
// Pino do LDR
const int LDR_PIN = A8; // VCC=vermelho, GND=marrom, SIG(A0)=amarelo

/*      MOTORES    */
const int LEFT_MOTOR_INPUT = 1;
const int RIGHT_MOTOR_INPUT = 2;
#define LEFT_MOTOR_FORWARD FORWARD
#define LEFT_MOTOR_BACKWARD BACKWARD
#define RIGHT_MOTOR_FORWARD  BACKWARD
#define RIGHT_MOTOR_BACKWARD FORWARD




#endif 
