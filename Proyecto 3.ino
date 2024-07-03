const int trigPin = 9; // Pin del sensor para enviar señal de ultrasonido

const int echoPin = 10; // Pin del sensor para recibir la señal de eco

const int ledPin1 = 3; // Pin del LED para 15cm

const int ledPin2 = 4; // Pin del LED para 10cm

const int ledPin3 = 7; // Pin del LED para 5cm

void setup() {

pinMode(trigPin, OUTPUT); // configurar el pin del trig como salida

pinMode(echoPin, INPUT); // configurar el pin del echo como entrada

pinMode(ledPin1, OUTPUT); // configurar el pin del LED para 15cm como salida

pinMode(ledPin2, OUTPUT); // configurar el pin del LED para 10cm como salida

pinMode(ledPin3, OUTPUT); // configurar el pin del LED para 5cm como salida

Serial.begin(9600); // iniciar la comunicación serial a 9600 baudios

}

void loop() {

long duration, distance;

digitalWrite(trigPin, LOW); // enviar una señal baja al pin del trig

delayMicroseconds(2);

digitalWrite(trigPin, HIGH); // enviar una señal alta al pin del trig durante 10 microsegundos

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH); // leer la duración de la señal de eco

distance = (duration / 2) / 29.1; // calcular la distancia en centímetros

Serial.print("Distancia: ");

Serial.print(distance);

Serial.println(" cm");

if (distance < 5) { // si la distancia es menor a 5 centímetros, encender el LED para 5cm

digitalWrite(ledPin3, HIGH);

digitalWrite(ledPin2, LOW);

digitalWrite(ledPin1, LOW);

} else if (distance < 10) { // si la distancia es menor a 10 centímetros, encender el LED para 10cm

digitalWrite(ledPin2, HIGH);

digitalWrite(ledPin3, LOW);

digitalWrite(ledPin1, LOW);

} else if (distance < 15) { // si la distancia es menor a 15 centímetros, encender el LED para 15cm

digitalWrite(ledPin1, HIGH);

digitalWrite(ledPin2, LOW);

digitalWrite(ledPin3, LOW);

} else { // de lo contrario, apagar todos los LEDs

digitalWrite(ledPin1, LOW);

digitalWrite(ledPin2, LOW);

digitalWrite(ledPin3, LOW);

}

delay(500); // esperar 500 milisegundos antes de volver a medir la distancia

}