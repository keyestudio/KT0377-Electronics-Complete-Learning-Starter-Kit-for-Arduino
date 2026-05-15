/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 26

Ventilador con Control Remoto IR

Editado por Keyes

* /

#include <IRremote.h> // Librería de infrarrojos incluida (requiere versión 2.0.1)

// --- 1. Definición del pin del receptor IR y creación del objeto ---
const int RECV_PIN = 2; // Pin de señal del receptor IR D2
IRrecv irrecv(RECV_PIN); // Crear objeto receptor IR
decode_results results;  // Objeto para almacenar resultados decodificados

// --- 2. Definición de pines de control del motor L293D ---
const int enablePin = 10; // D10: Controla la velocidad del motor (PWM)
const int in1Pin = 11;    // D11: Controla dirección del motor 1
const int in2Pin = 9;     // D9:  Controla dirección del motor 2

void setup() {
  Serial.begin(9600);      // Inicializar puerto serie, velocidad 9600
  irrecv.enableIRIn();     // Activar receptor IR

  // Configurar pines del motor como salida
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  Serial.println("Sistema inicializado, esperando señal infrarroja...");
}

void loop() {
  // Si se recibe y decodifica correctamente una señal IR
  if (irrecv.decode(&results)) { 
    // Imprimir en serie el código IR recibido en hexadecimal (HEX)
    Serial.print("Código IR recibido: 0x");
    Serial.println(results.value, HEX); 

    // Ejecutar acción según el código del botón recibido
    switch (results.value) {
      
      // Botón 1 (código de ejemplo): Giro adelante (puede cambiarse por el código del botón "arriba" del control)
      case 0xFF629D: 
        setMotor(255, false); // Giro adelante a máxima velocidad
        Serial.println("Acción: Ventilador girando adelante (FORWARD)");
        break;

      // Botón 2 (código de ejemplo): Giro atrás (puede cambiarse por el código del botón "abajo" del control)
      case 0xFFA857: 
        setMotor(255, true);  // Giro atrás a máxima velocidad
        Serial.println("Acción: Ventilador girando atrás (BACKWARD)");
        break;

      // Botón 3 (código de ejemplo): Detener (puede cambiarse por el código del botón "OK" o "stop" del control)
      case 0xFF02FD: 
        setMotor(0, false);   // Velocidad 0, detener motor
        Serial.println("Acción: Ventilador detenido (STOP)");
        break;
        
      default:
        // Botón desconocido, no hacer nada
        break;
    }
    
    // Preparar para recibir la siguiente señal
    irrecv.resume(); 
  }
  
  delay(100); // Pequeña demora para evitar lecturas excesivas por pulsaciones repetidas
}

// --- 3. Función personalizada para controlar el motor ---
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}