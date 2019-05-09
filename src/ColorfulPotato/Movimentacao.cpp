
#include "Movimentacao.h"
#include "Configuracao.h"
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LEFT_MOTOR = AFMS.getMotor(LEFT_MOTOR_INPUT);
Adafruit_DCMotor *RIGHT_MOTOR = AFMS.getMotor(RIGHT_MOTOR_INPUT);  

void SETUP_MOVIMENTACAO(){
    AFMS.begin();
}


void para(){
  LEFT_MOTOR->run(RELEASE);
  RIGHT_MOTOR->run(RELEASE);
  delay(100);
}

void anda(int d){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD );
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  d=d*91;
  delay(d);
  para();
}


void anda_re(int d){
  para();
  LEFT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(LEFT_MOTOR_FORWARD);
  d=d*91;
  delay(d);
  para();
}

void gira_sentido_horario(double t){
  para();
  LEFT_MOTOR->run(LEFT_MOTOR_FORWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  t=t*181;
  delay(t);
  para();
}


void gira_sentido_antihorario(double t){
  para();
  LEFT_MOTOR->run(RIGHT_MOTOR_BACKWARD);
  RIGHT_MOTOR->run(RIGHT_MOTOR_FORWARD);
  t=t*181;
  delay(t);
  para();
}
