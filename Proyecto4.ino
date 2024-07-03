#include <stdlib.h> // Incluye la biblioteca para funciones de aleatoriedad

int segmentPins[] = {8, 7, 6, 5, 4, 3, 2}; // Pines para los segmentos del display
int numbers[7][7] = { // Números 0-6
  {0,0,0,0,0,0,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1}   // 6
};
int joystickButton = 12; // Botón del joystick en pin 12

void setup() {
  for (int i = 0; i < 7; i++) { // Configura segmentos como salidas
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(joystickButton, INPUT_PULLUP); // Botón como entrada
  randomSeed(analogRead(0)); // Semilla aleatoria
  Serial.begin(9600); // Inicia comunicación serial a 9600 baudios
}

void loop() {
  if (digitalRead(joystickButton) == LOW) { // Revisa el botón
    int randomNumber = random(1, 7); // Genera número aleatorio
    displayNumber(randomNumber);
    Serial.println(randomNumber); // Envía número al Monitor Serial
    delay(200); // Evita rebotes
    while(digitalRead(joystickButton) == LOW); // Espera soltar botón
  }
}

void displayNumber(int num) { // Muestra número en display
  for (int segment = 0; segment < 7; segment++) {
    digitalWrite(segmentPins[segment], numbers[num][segment]);
  }
}