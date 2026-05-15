# Proyecto 27: hogar inteligente con control remoto infrarrojo

## Descripción
Los hogares inteligentes utilizan tecnologías de IoT y automatización para brindar a las personas una experiencia de vida más cómoda, conveniente y segura. Cubre muchos aspectos, desde la iluminación y la seguridad hasta el control de electrodomésticos.

En este proyecto, usaremos una placa principal Arduino UNO R3, un módulo receptor infrarrojo, un módulo relé y un motor paso a paso para construir un "sistema de hogar inteligente" en miniatura. Puedes usar un control remoto IR común para operar dispositivos en casa de forma remota: por ejemplo, usar el relé para encender o apagar la "luz", y usar el motor paso a paso para controlar la apertura y cierre de las "cortinas".

## Hardware
1. Placa de desarrollo UNO R3 (CH340) × 1  
2. **Receptor IR** × 1 *(incluye capacitores de 100nF y 10μF)*  
3. **Módulo Relé** × 1  
4. **Motor paso a paso 28BYJ-48** × 1  
5. **Placa controladora de motor paso a paso ULN2003** × 1  
6. Control remoto IR × 1  
7. LED × 1 *(usado para simular un electrodoméstico controlado por el relé)*  
8. Resistencia de 220Ω × 1 *(para limitar la corriente del LED)*  
9. Protoboard × 1 y varios cables Dupont  

## Principio de funcionamiento
Cuando presionas un botón en el control remoto, el receptor IR detecta una señal infrarroja codificada específica. El Arduino decodifica esta señal y desencadena acciones correspondientes según el código:  
* **Control de iluminación (relé):** Cuando se recibe el código para el "Botón 1", el Arduino cambia el estado del relé (si estaba ENCENDIDO, lo apaga; si estaba APAGADO, lo enciende), controlando así el LED conectado al relé.  
* **Control de cortinas (motor paso a paso):** Cuando se recibe el "Botón 2", el Arduino ordena al motor paso a paso que gire hacia adelante una vuelta completa (simulando la apertura de las cortinas); cuando se recibe el "Botón 3", ordena al motor que gire hacia atrás una vuelta completa (simulando el cierre de las cortinas).

## Diagrama de conexiones

**1. Receptor IR**  
* `VCC` ➔ Arduino 5V  
* `GND` ➔ Arduino GND  
* `OUT (Pin de señal)` ➔ **Arduino D2**

**2. Motor paso a paso y placa controladora (ULN2003)**  
* Conecta el conector blanco del motor paso a paso en el socket correspondiente de la placa controladora ULN2003.  
* Driver `IN1` ➔ **Arduino D8**  
* Driver `IN2` ➔ **Arduino D10** *(Nota: según el código abajo, IN2 se conecta a D10, IN3 a D9)*  
* Driver `IN3` ➔ **Arduino D9**  
* Driver `IN4` ➔ **Arduino D11**  
* Driver `+ (VCC)` ➔ Arduino 5V  
* Driver `- (GND)` ➔ Arduino GND

**3. Módulo Relé**  
* Relé `VCC` ➔ Arduino 5V  
* Relé `GND` ➔ Arduino GND  
* Relé `S (Señal/IN)` ➔ **Arduino D3**

**4. Electrodoméstico simulado (LED conectado al lado del relé)**  
* Conecta la pata larga del LED (ánodo) a través de una resistencia de 220Ω a 5V.  
* Conecta la pata corta del LED (cátodo) al terminal **Normalmente Abierto (NO)** del relé.  
* Conecta el terminal **Común (COM)** del relé a GND.  
![Img](../media/img-20260508101829.png)


## Código de ejemplo

*Nota: Antes de subir el código, asegúrate de haber instalado la librería `IRremote` (versión recomendada 2.0.1) mediante el Gestor de Librerías del IDE de Arduino. Los códigos hexadecimales `0xFF...` en el código son ejemplos; reemplázalos con los códigos reales de los botones de tu control remoto.*

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 27

infrared remote control Smart Home

Edit By Keyes

*/

#include <IRremote.h> // Include IR remote library
#include <Stepper.h>  // Include Arduino built-in stepper motor library

// --- 1. Pin and parameter definitions ---
#define IR_RECEIVE_PIN 2   // IR receiver pin D2
#define RELAY_PIN 3        // Relay control pin D3
#define STEPS_PER_REV 2048 // Number of steps for 28BYJ-48 stepper motor to complete one revolution

// --- 2. Create control objects ---
IRrecv irrecv(IR_RECEIVE_PIN); // Create IR receiver object
decode_results results;        // Store IR decode results

// Create stepper motor object; note pin order is 8, 10, 9, 11 (corresponding to IN1, IN3, IN2, IN4, which is the motor’s required driving sequence)
Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11); 

void setup() {
  irrecv.enableIRIn();           // Initialize and start the IR receiver
  
  pinMode(RELAY_PIN, OUTPUT);    // Set relay pin as output
  digitalWrite(RELAY_PIN, LOW);  // Initialize relay as OFF
  
  stepper.setSpeed(10);          // Set stepper motor speed to 10 RPM
}

void loop() {
  // If an IR signal is received
  if (irrecv.decode(&results)) {
    
    // Perform actions based on received button code
    switch (results.value) {
      
      // Button 1 (example code 0xFF6897): control light (relay)
      case 0xFF6897: 
        // Toggle relay state: if ON, turn OFF; if OFF, turn ON
        digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN)); 
        break;

      // Button 2 (example code 0xFF9867): open curtains (stepper motor forward)
      case 0xFF9867: 
        // Rotate stepper motor forward one full revolution (2048 steps)
        stepper.step(STEPS_PER_REV); 
        break;

      // Button 3 (example code 0xFFB04F): close curtains (stepper motor backward)
      case 0xFFB04F: 
        // Rotate stepper motor backward one full revolution (-2048 steps)
        stepper.step(-STEPS_PER_REV); 
        break;
    }
    
    // Resume IR receiver to get next signal
    irrecv.resume(); 
  }
}
```

## Explicación del código

**1. Incluir las librerías necesarias:**  
```cpp
#include <IRremote.h>
#include <Stepper.h>
```
La librería `IRremote.h` permite que el Arduino entienda los "códigos" enviados por el control remoto IR. La librería `Stepper.h` es una librería oficial de Arduino diseñada para el control preciso de ángulos y direcciones de rotación de motores paso a paso (se usa aquí para simular el movimiento de las cortinas).

**2. Inicialización de objetos:**  
```cpp
Stepper stepper(STEPS_PER_REV, 8, 10, 9, 11);
```
Esta línea es muy importante. Debido a la disposición interna de las bobinas del motor paso a paso 28BYJ-48, para asegurar una rotación suave, el orden de pines que se pasa al código debe ser `8, 10, 9, 11` (correspondiente a IN1, IN3, IN2, IN4 de la placa controladora). Esto se llama secuencia de medio paso.

**3. Lógica para cambiar el estado del relé:**  
```cpp
digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));
```
Este es un código clásico de "interruptor con un solo botón". Primero lee el estado actual del relé con `digitalRead`, luego usa el operador `!` (NOT) para invertir el estado, y finalmente escribe el estado opuesto con `digitalWrite`. Así, al presionar el botón una vez se enciende, y al presionarlo otra vez se apaga.

**4. Rotación del motor paso a paso:**  
```cpp
stepper.step(STEPS_PER_REV);
stepper.step(-STEPS_PER_REV);
```
La función `step()` hace que el motor gire un número especificado de pasos. Como definimos `STEPS_PER_REV = 2048`, pasar 2048 hace que el motor gire una vuelta completa hacia adelante (abrir cortinas), y pasar -2048 hace que gire una vuelta completa hacia atrás (cerrar cortinas). El programa espera en esta línea hasta que el motor complete los pasos.

## Resultado del proyecto

Después de subir el código y alimentar el circuito, puedes experimentar el control de hogar inteligente:  
1. **Controlar la luz:** Presiona el "Botón 1" en el control remoto, escucharás un clic del relé y el LED se encenderá; presiona "Botón 1" nuevamente, el relé hará clic otra vez y el LED se apagará.  
2. **Abrir cortinas:** Presiona "Botón 2", el LED indicador del motor paso a paso parpadeará y el eje del motor girará suavemente una vuelta completa en sentido horario, simulando que las cortinas se abren lentamente.  
3. **Cerrar cortinas:** Presiona "Botón 3", el motor paso a paso girará una vuelta completa en sentido antihorario, regresando a la posición inicial, simulando el cierre de las cortinas.

¡Con este proyecto puedes entender de forma intuitiva cómo los electrodomésticos y dispositivos de automatización pueden ser controlados centralizadamente mediante señales inalámbricas!

![P27](../media/P27.gif)