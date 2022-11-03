#include "DigiKeyboard.h"

// https://updatefaker.com/windows10/index.html
const uint8_t key_arr_0[] PROGMEM = {0,11, 0,23, 0,23, 0,19, 0,22, 2,55, 2,36, 2,36, 0,24, 0,19, 0,7, 0,4, 0,23, 0,8, 0,9, 0,4, 0,14, 0,8, 0,21, 0,55, 0,6, 0,18, 0,16, 2,36, 0,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 0,30, 0,39, 2,36, 0,12, 0,17, 0,7, 0,8, 0,27, 0,55, 0,11, 0,23, 0,16, 0,15};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING https://updatefaker.com/windows10/index...
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(400); // DELAY 400
    DigiKeyboard.sendKeyStroke(68, 0); // F11
}

void loop() {}