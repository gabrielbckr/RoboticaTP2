#include "Tarefas.h"
#include "Configuracao.h"
#include "Movimentacao.h"
#include "SensorDeLuz.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd2(8, 9, 4, 5, 6, 7);

unsigned long TempoAnterior = 0;
unsigned long TempoAtual = 0;

void TasksSetup() {
  SETUP_MOVIMENTACAO();
  lcd2.begin(16, 2);
}

void ex1() {
  anda(30);
  gira1(12);
  anda(30);
  gira1(12);
  para();
}

void ex2() {
  anda(30);
  gira1(6);
  anda(30);
  gira1(9);
  anda(42);
  gira1(9);
  para();
}

void ex3() {
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

void ex4() {
  gira1(12);
  delay(1000);
  gira1(6);
}

void ExploraAmbiente() {
  while(1){
    if (DetectaObjeto()) {
      // ANDA PARA TRAZ UM POUQUINHO

      char color = DetectaCor();
      if (color == yellow) {
        //gire 180 graus e ande para frente;
      }
      else if (color == red) {
        //pare e dê um giro de 360 graus (permanecendo parado após o giro).
      }
      else if (color == green) {
        //vire à esquerda 90 graus e ande para frente
      }
      else if (color == blue) {
        // vire à direita 90 graus e ande para frente
      }
      else if (color == black) {
      }
      TempoAnterior = millis();
    }
    TempoAtual = millis();
    if (TempoAtual - TempoAnterior < 10000){
      return;
    }
  }
}

void MostraNoLCDCorDetectada() {
  char color = DetectaObjeto();
  if (color == yellow) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Amarelo");
  }
  else if (color == red) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Vermelho");
  }
  else if (color == green) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Verde");
  }
  else if (color == blue) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Azul");
  }
  else if (color == black) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Preto");
  }
}
