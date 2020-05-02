#include "lcdcontroller.h"
#include "menus.h"

#define SELECT 0
#define IZQDA 1
#define ABAJO 2
#define ARRIBA 3
#define DERECHA 4


const char *mainGames[] = {"DOA","Overwatch","Apex", "BleedingEdge", "Naruto" ,"Other"};
const char *menuScenas[] = {"INTRO","GAME"};
int currentGame = -1;
int currentEscena = -1;

void showMenuEscenasGames(){
    bool exit = false;
    int indexGame = 0;
    int indexEscena = 0;
    Serial.println("Enter principal");
    while(true){ //loop inside menu
        int nextGame = indexGame % (sizeof(mainGames)/sizeof(char *));
        int nextEscena = indexEscena % (sizeof(menuScenas)/sizeof(char *));
        generateMenu(nextGame, nextEscena);
        delay(200);
        int pulsacion = getPulsacion();
        if(pulsacion == DERECHA) indexEscena += 1;
        else if(pulsacion == IZQDA) indexEscena -= 1;
        else if(pulsacion == ARRIBA) indexGame += 1;
        else if(pulsacion == ABAJO) indexGame -= 1;
        else if(pulsacion == SELECT){
            //save la seleccion
            currentGame = nextGame;
            currentEscena = nextEscena;
            sendCommand(nextGame, nextEscena);
        }
    }
}

void generateMenu(int nextGame, int nextEscena){
    String gameToPrint = String(mainGames[nextGame]);
    String sceneToPrint = String(menuScenas[nextEscena]);
    Serial.println(gameToPrint);
    Serial.println(sceneToPrint);
    bool isSelected = nextGame == currentGame && nextEscena == currentEscena;
    printlcd(0, gameToPrint, false, false);
    printlcd(1, sceneToPrint, true, isSelected);
}

void sendCommand(int game, int escena){
    Serial.println(game);
    Serial.println(escena);
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
