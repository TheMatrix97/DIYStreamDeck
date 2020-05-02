#include <LiquidCrystal.h>
#include "lcdcontroller.h"

int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup_lcd(){ //Start lcd
    lcd.begin(16, 2);
    lcd.noBlink();
    //lcd.autoscroll();
}

void printlcd(int fila, String aux){
    int size = aux.length();
    int total = 16;
    lcd.clear();
    lcd.setCursor((16-size)/2,fila);
    lcd.print(aux);
}

void clear_lcd(){
    lcd.clear();
}