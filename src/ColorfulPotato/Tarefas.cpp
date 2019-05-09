#include "Tarefas.h"
#include "Configuracao.h"
#include "Movimentacao.h"
#include "SensorDeLuz.h"

#include <LiquidCrystal.h>
LiquidCrystal lcd2(8, 9, 4, 5, 6, 7);

unsigned long TempoAnterior = 0;
unsigned long TempoAtual = 0;

void TasksSetup() {
  SENSORDELUZ_SETUP();
  SETUP_MOVIMENTACAO();
  lcd2.begin(16, 2);
}

void ex1() {
  anda(30);
  gira_sentido_horario(12);
  anda(30);
  gira_sentido_horario(12);
  para();
}

void ex2() {
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(9);
  anda(42);
  gira_sentido_horario(9);
  para();
}

void ex3() {
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  anda(30);
  gira_sentido_horario(6);
  para();
}

void ex4() {
  gira_sentido_horario(12);
  delay(1000);
  gira_sentido_horario(6);
}

void ExploraAmbiente() {
  // inicia movimento para algum lugar 
  anda (0);
  TempoAnterior = millis();
  while(1){
    if (DetectaObjeto()) {
      char color = DetectaCor();
      
      anda_re(5);

      if (color == yellow) {
        //gire 180 graus e ande para frente;
        gira_sentido_horario(12);
        anda (0);
      }
      else if (color == red) {
        //pare e dê um giro de 360 graus (permanecendo parado após o giro).
        gira_sentido_horario(24);
      }
      else if (color == green) {
        //vire à esquerda 90 graus e ande para frente
        gira_sentido_antihorario(6);
        anda (0);
      }
      else if (color == blue) {
        // vire à direita 90 graus e ande para frente
        gira_sentido_horario(6);
        anda (0);
      }
      else if (color == black) {
      }
      TempoAnterior = millis();
    }
    TempoAtual = millis();
    if (TempoAtual - TempoAnterior > 10000){
      para();
      return;
    }
  }
}

void MostraNoLCDCorDetectada() {
  char color = DetectaObjeto();
  if (color == yellow) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Amarelo ");
  }
  else if (color == red) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Vermelho");
  }
  else if (color == green) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Verde   ");
  }
  else if (color == blue) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Azul    ");
  }
  else if (color == black) {
    lcd2.setCursor(7, 1);
    lcd2.print ("Preto   ");
  }
}
