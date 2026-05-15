/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 23

Controlador de Motor L293D

Editado por Keyes

* /

// Definir pines
const int enablePin = 10; // D10: Controla la velocidad del motor (PWM)
const int in1Pin = 11;    // D11: Controla la dirección del motor 1
const int in2Pin = 9;     // D9:  Controla la dirección del motor 2

void setup() {
  // Configurar pines de control como salida
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  // 1. Giro a máxima velocidad hacia adelante, durante 2 segundos
  setMotor(255, false); 
  delay(2000);

  // 2. Detener motor, durante 1 segundo
  setMotor(0, false);   
  delay(1000);

  // 3. Giro a máxima velocidad hacia atrás, durante 2 segundos
  setMotor(255, true);  
  delay(2000);

  // 4. Detener motor, durante 1 segundo
  setMotor(0, false);   
  delay(1000);
}

// Función personalizada para controlar el motor
// Parámetro speed: velocidad (0~255)
// Parámetro reverse: dirección (false para adelante, true para reversa)
void setMotor(int speed, boolean reverse) {
  // Enviar señal PWM para establecer la velocidad
  analogWrite(enablePin, speed);
  
  // Controlar la dirección usando lógica inversa, asegurando que los dos pines tengan niveles opuestos
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}