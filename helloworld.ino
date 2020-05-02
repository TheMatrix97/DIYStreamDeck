//hello world
#include "lcdcontroller.h"
#include "menus.h"

void setup(){
    setup_lcd();
    Serial.begin(9600);
}

void loop(){
    showMenuEscenasGames();
}