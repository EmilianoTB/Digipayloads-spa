#include "DigiKeyboard.h"

// https://www.cryptoprank.com/#/crypto
const uint8_t key_arr_0[] PROGMEM = {0,11, 0,23, 0,23, 0,19, 0,22, 2,55, 2,36, 2,36, 0,26, 0,26, 0,26, 0,55, 0,6, 0,21, 0,28, 0,19, 0,23, 0,18, 0,19, 0,21, 0,4, 0,17, 0,14, 0,55, 0,6, 0,18, 0,16, 2,36, 2,32, 2,36, 0,6, 0,21, 0,28, 0,19, 0,23, 0,18};

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
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING https://www.cryptoprank.com/#/crypto
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(68, 0); // F11
}

void loop() {}

