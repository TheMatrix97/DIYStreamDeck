//hello world
#include "lcdcontroller.h"
#include "menus.h"
#include <Keyboard.h>
#define ledPin 13

void setup(){
    setup_lcd();
    setup_keyboard();
    Serial.begin(9600);
}


void loop(){
    showMainMenu();
}

void setup_keyboard(){
    Keyboard.begin();
}

void keyboard_press(int command){
    Keyboard.press(command);
    Keyboard.press("C");
    delay(500);
    Keyboard.releaseAll();
}
