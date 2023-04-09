#include <DigiMouse.h>
// Ees necesario instalar esta libreria para ejecutarla en el digispark

void setup() {
  DigiMouse.begin();
}

void loop() {
  // Mueve el cursor de manera aleatoria en un pequeño rango
  int x = random(-5, 5);
  int y = random(-5, 5);
  DigiMouse.move(x, y);
  
  // Espera un corto tiempo para mover de nuevo
  delay(random(100, 500));
}