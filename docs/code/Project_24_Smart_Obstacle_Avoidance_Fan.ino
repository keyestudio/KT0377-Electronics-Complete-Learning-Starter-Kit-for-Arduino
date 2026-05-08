/*

Electronics Learning Starter Kit para Arduino

Proyecto 24

Ventilador Inteligente con Evitación de Obstáculos

Editado por Keyes

*/

// --- 1. Definición de pines del sensor ultrasónico ---
const int trigPin = 8;  // Pin de emisión
const int echoPin = 7;  // Pin de recepción

// --- 2. Definición de pines del controlador de motor L293D ---
const int enablePin = 10; // D10: Controla la velocidad del motor (PWM)
const int in1Pin = 11;    // D11: Controla la dirección del motor 1
const int in2Pin = 9;     // D9:  Controla la dirección del motor 2

// --- 3. Configuración de parámetros ---
const int safeDistance = 15; // Umbral de distancia segura establecido en 15 centímetros

void setup() {
  // Inicializar pines del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Inicializar pines de control del motor
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Iniciar comunicación serial para observar datos de distancia en la computadora
  Serial.begin(9600);
}

void loop() {
  // ================= Paso 1: Emitir ondas sonoras y medir distancia =================
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Emitir un pulso ultrasónico de 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Medir el tiempo que el pin de eco permanece en alto (microsegundos)
  long duration = pulseIn(echoPin, HIGH);
  // Calcular la distancia (velocidad del sonido aprox. 0.034 cm/us, se divide entre 2 por el viaje de ida y vuelta)
  int distance = duration * 0.034 / 2;
  
  // Imprimir la distancia actual en el monitor serial
  Serial.print("Distancia actual: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // ================= Paso 2: Controlar el motor según la distancia =================
  // Se añade distance > 0 para evitar falsas lecturas cuando el sensor falla y devuelve 0
  if (distance > 0 && distance <= safeDistance) {
    // ¡Obstáculo demasiado cerca! Velocidad a 0, detener el motor.
    setMotor(0, false);
    Serial.println(">>> Estado: ¡Peligro! Frenando <<<");
  } else {
    // ¡Frente seguro! Velocidad a 255, giro a máxima velocidad.
    setMotor(255, false);
    Serial.println("Estado: Funcionando normalmente...");
  }
  
  // Pequeña pausa para evitar interferencias por alta frecuencia de medición
  delay(100); 
}

// ================= Función personalizada para control del motor =================
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}