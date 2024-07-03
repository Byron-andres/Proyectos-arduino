// Pines para los LEDs
const int ledUp = 2;    // LED para "arriba"
const int ledDown = 3;  // LED para "abajo"
const int ledLeft = 4;  // LED para "izquierda"
const int ledRight = 5; // LED para "derecha"

// Pines para el joystick
const int joyX = A0; // Eje X
const int joyY = A1; // Eje Y

//Salidas de los led y entradas
void setup() {
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);

  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}

//Movimiento horizontal y vertical del joystick
void loop() {
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // Desactivar todos los LEDs antes de cambiar el estado
  digitalWrite(ledUp, LOW);
  digitalWrite(ledDown, LOW);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);

  // Leer el joystick y encender el LED correspondiente
  if (xValue < 400) { // Izquierda
    digitalWrite(ledLeft, HIGH);
  } else if (xValue > 600) { // Derecha
    digitalWrite(ledRight, HIGH);
  }

//Leer el joystick y encender el LED correspondiente
  if (yValue < 400) { // Arriba
    digitalWrite(ledUp, HIGH);
  } else if (yValue > 600) { // Abajo
    digitalWrite(ledDown, HIGH);
  }

  delay(100); // Pequeña pausa para estabilidad
}
