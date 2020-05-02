#include <LiquidCrystal.h>
#include "lcdcontroller.h"

#define LinesLCD 2
#define RowLCD 16

int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup_lcd(){
    lcd.begin(RowLCD, LinesLCD);
    lcd.noBlink();
}

void printlcd(int fila, String aux, bool isScene, bool isSelected){
    if(isScene && !isSelected) aux = aux + "[]";
    else if(isScene && isSelected) aux = aux + "[X]";
    Serial.println(aux);
    int size = aux.length();
    clearLCDLine(fila);
    lcd.setCursor((RowLCD-size)/2,fila);
    lcd.print(aux);
}

void clearLCDLine(int line){
    lcd.setCursor(0,line);
    for(int n = 0; n < RowLCD; n++) lcd.print(" ");
}

void clear_lcd(){
    lcd.clear();
}