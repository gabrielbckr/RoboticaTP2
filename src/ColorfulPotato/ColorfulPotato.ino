// #define __PILHA__ // DESCOMENTE PARA USAR NA TOAMDA

#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#include "Configuracao.h"
#include "Tarefas.h"
#include "SensorDeLuz.h"

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 20;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
char input;
bool r,g,b;

enum states {
  MAIN_1,
  MAIN_2,
  MAIN_3,
  LOC_1,
  LOC_2,
  LOC_3
};

states menu_state = MAIN_1;


int read_LCD_buttons() {
  int adc_key_in = analogRead(0);      // read the value from the sensor
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result

  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;

  return btnNONE;  // when all others fail, return this...
}

void setup() {
  lcd.begin(16, 2);
  SENSORDELUZ_SETUP();
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  Menu();
}

void Menu(){
  int button = 5;
  button = read_LCD_buttons();
  switch(menu_state){
    case MAIN_1:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L. 2-ID  3-M  ");
      if (button == btnRIGHT){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnDOWN){
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      break;
    case MAIN_2:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-ID. 3-M  ");
      if (button == btnRIGHT){
        menu_state = MAIN_3;
        delay(btnDELAY);
      }        
      else if (button == btnLEFT){
        menu_state = MAIN_1;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Id cor em exec. ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //CHAMAR IDENTIFICA CORES AQUI
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      break;
    case MAIN_3:
      lcd.setCursor(0,0);
      lcd.print("Menu de Tarefas ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-ID  3-M. ");
      if (button == btnLEFT){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Multi em exec.  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //CHAMAR MULTITAREFA AQUI
        menu_state = MAIN_3;
        delay(btnDELAY);
      }
      break;
    case LOC_1:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L. 2-TR  3-Q  ");
      if (button == btnRIGHT){
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_1;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Linha em exec.  ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //CHAMAR DESENHA LINHA AQUI
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      break;
    case LOC_2:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-TR. 3-Q  ");
      if (button == btnRIGHT){
        menu_state = LOC_3;
        delay(btnDELAY);
      }
      else if (button == btnLEFT){
        menu_state = LOC_1;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_2;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Triang. em exec.");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //CHAMAR DESENHA TRIÂNGULO AQUI
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      break;
    case LOC_3:
      lcd.setCursor(0,0);
      lcd.print("Locomocao       ");
      lcd.setCursor(0,1);
      lcd.print("1-L  2-TR  3-Q. ");
      if (button == btnLEFT){
        menu_state = LOC_2;
        delay(btnDELAY);
      }
      else if (button == btnUP){
        menu_state = MAIN_3;
        delay(btnDELAY);
      }
      else if (button == btnSELECT){
        lcd.setCursor(0,0);
        lcd.print("Quadr. em exec. ");
        lcd.setCursor(0,1);
        lcd.print("                ");
        //CHAMAR DESENHA QUADRADO AQUI
        menu_state = LOC_3;
        delay(btnDELAY);
      }
      break;
  }

}
