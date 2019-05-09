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
const int LDR_PIN = 62; // VCC=vermelho, GND=marrom, SIG(A0)=amarelo

/*      CORES        */
const char yellow = 'C';
const char black = 'D';
const char blue  = 'B';
const char red    = 'R';
const char green = 'G';

/*      MOTORES    */
const int LEFT_MOTOR_INPUT = 1;
const int RIGHT_MOTOR_INPUT = 2;
#define LEFT_MOTOR_FORWARD FORWARD
#define LEFT_MOTOR_BACKWARD BACKWARD
#define RIGHT_MOTOR_FORWARD  BACKWARD
#define RIGHT_MOTOR_BACKWARD FORWARD


#ifdef __PILHA__
// CONSTANTES DE PILHA
#else
// CONSTANTES DE TOMADA
#endif


#endif 
