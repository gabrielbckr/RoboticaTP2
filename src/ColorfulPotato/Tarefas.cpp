#include "Tarefas.h"
#include "Configuracao.h"
#include "Movimentacao.h"


void TasksSetup(){
  SETUP_MOVIMENTACAO();
}



void ex1(){
  anda(30);
  gira1(12);
  anda(30);
  gira1(12);
  para();
}

void ex2(){
  anda(30);
  gira1(6);
  anda(30);
  gira1(9);
  anda(42);
  gira1(9);
  para();
}

void ex3(){
  anda(30);
  gira1(6);
  anda(30);
  gira1(6);
  anda(30);
  gira1(6);
  anda(30);
  gira1(6);
  para();
}

void ex4(){
  gira1(12);
  delay(1000);
  gira1(6);
}
