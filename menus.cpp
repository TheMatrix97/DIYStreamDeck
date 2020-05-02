#include "lcdcontroller.h"
#include "menus.h"

#define SELECT 0
#define IZQDA 1
#define ABAJO 2
#define ARRIBA 3
#define DERECHA 4


/* MainMenu = 0
 escenas = 1
 other = 2
*/
const char *mainMenu[] = {"Escenas","Other"};
const char *menuScenas[] = {"INTRO","DOA","Overwatch", "Apex", "BleedingEdge"};
const int mapEscenas[] = {KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5};
int currentMenu = 0;
int currentEscena = 0;

void showMainMenu(){
    bool exit = false;
    int index = currentMenu;
    Serial.println("Enter principal");
    int next_id = 0;
    while(!exit){
        next_id = index % (sizeof(mainMenu)/sizeof(char *));
        Serial.println(next_id);
        String aux = String(mainMenu[next_id]);
        printlcd(0, aux);
        delay(200);
        int pulsacion = getPulsacion();
        if(pulsacion == DERECHA) index += 1;
        else if(pulsacion == IZQDA) index -= 1;
        else if(pulsacion == ARRIBA) exit = true;
        else if(pulsacion == SELECT) enterSubMenu(next_id);
    }
    currentMenu = next_id;
    Serial.println("exit principal");
}

void enterSubMenu(int index){
    switch(index){
        case 0: //enter Escenas menu
            showMenuEscenas();
            break;
        default:
            return;
    }
}

void showMenuEscenas(){
    bool exit = false;
    int index = currentEscena;
    Serial.println("Enter escenas");
    int next_id = 0;
    while(!exit){
        next_id = index % (sizeof(menuScenas)/sizeof(char *));
        Serial.println(next_id);
        String aux = String(menuScenas[next_id]);
        printlcd(0, aux);
        delay(200);
        int pulsacion = getPulsacion();
        if(pulsacion == DERECHA) index += 1;
        else if(pulsacion == IZQDA) index -= 1;
        else if(pulsacion == ARRIBA) exit = true;
        else if(pulsacion == SELECT) changeEscena(next_id);
    }
    currentEscena = next_id;
    Serial.println("Exit escenas");
}

void changeEscena(int id){
    //keyboard_press(mapEscenas[id]);
}

void getCurrentEscena(){

}
void getNextEscena(){

}
void getNextItemMainMenu(){

}

int getPulsacion(){
    int btn = -1;
    int adc_key = 0;
   do{
        adc_key = analogRead(0);  
        if (adc_key < 750)  btn=SELECT; 
        if (adc_key < 550)  btn=IZQDA;
        if (adc_key < 350)  btn=ABAJO;
        if (adc_key < 150)  btn=ARRIBA;
        if (adc_key < 50)   btn=DERECHA; 
    }while(adc_key > 1000);
    return btn;
}
