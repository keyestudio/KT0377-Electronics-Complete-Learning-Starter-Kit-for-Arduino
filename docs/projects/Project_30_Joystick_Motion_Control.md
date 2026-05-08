# Proyecto 30: Control de Movimiento con Joystick

## Descripción
Este proyecto demuestra cómo usar un Arduino para leer las señales analógicas de un módulo joystick de doble eje y controlar manualmente la rotación de un motor paso a paso. Al mover el joystick, puedes controlar con precisión el motor paso a paso para que gire hacia adelante, hacia atrás o se detenga.

Este tipo de control es común en gimbals robóticos, enseñanza manual de las articulaciones de brazos robóticos, traslación de etapas de microscopios y otros dispositivos de automatización. Sirve como un excelente proyecto básico para entender el "control de interacción hombre-máquina".

## Hardware
1. Placa de desarrollo UNO R3 (CH340) × 1  
2. **Motor Paso a Paso 28BYJ-48** × 1  
3. **Placa Controladora de Motor Paso a Paso ULN2003** × 1  
4. **Módulo Joystick de Doble Eje** × 1  
5. Protoboard × 1  
6. Cables Dupont/cables jumper × varios  

## Principio de Funcionamiento
El núcleo de este proyecto es convertir el voltaje de salida del joystick en comandos de movimiento para el motor paso a paso.

1. **Salida Analógica del Joystick:** El joystick contiene internamente dos potenciómetros (resistencias variables). Cuando empujas el joystick a lo largo del eje X, el pin `VRx` emite un voltaje variable. Arduino lee este voltaje a través de un pin de entrada analógica (A0) y lo convierte en un valor entre `0` y `1023`.
2. **Posición Central y Umbrales:** Cuando el joystick está naturalmente centrado, la lectura es aproximadamente `512`. En el código, los umbrales se establecen de la siguiente manera:  
   * Si la lectura es **menor que 300** (empujado hacia un lado), el motor paso a paso gira continuamente hacia adelante.  
   * Si la lectura es **mayor que 800** (empujado hacia el otro lado), el motor paso a paso gira continuamente en reversa.  
   * Si la lectura está **entre 300 y 800** (joystick centrado/liberado), el motor paso a paso deja de recibir energía y se mantiene detenido.

## Diagrama de Conexiones

**1. Módulo Joystick**  
*(Nota: Este proyecto solo controla un motor paso a paso de un solo eje, por lo que solo se conecta el eje X. Los pines del eje Y `VRy` y el botón `SW` pueden dejarse sin conectar.)*  
* `VRx (salida analógica del eje X)` ➔ Conectar a **Arduino A0**  
* `VCC` ➔ Conectar a Arduino 5V  
* `GND` ➔ Conectar a Arduino GND  

**2. Motor Paso a Paso y Placa Controladora (ULN2003)**  
* Inserta el conector blanco del motor paso a paso en el zócalo de la placa controladora ULN2003.  
* `IN1` ➔ Conectar a **Arduino D8**  
* `IN2` ➔ Conectar a **Arduino D10** *(Nota la secuencia: para la librería Stepper incorporada de Arduino, el orden debe ser 8, 10, 9, 11)*  
* `IN3` ➔ Conectar a **Arduino D9**  
* `IN4` ➔ Conectar a **Arduino D11**  
* `+ (VCC)` ➔ Conectar a Arduino 5V (o fuente de alimentación externa de 5V)  
* `- (GND)` ➔ Conectar a Arduino GND  
![Img](../media/img-20260508111525.png)


## Código de Ejemplo

Copia y sube el siguiente código a tu Arduino:

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 30

Joystick Motion Control

Edit By Keyes

*/

#include <Stepper.h>

// Define the number of steps per revolution for the stepper motor (28BYJ-48 is usually 2048 steps)
const int stepsPerRevolution = 2048; 

// Initialize the stepper motor object, note the pin order is 8, 10, 9, 11
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set the stepper motor speed to 10 RPM (revolutions per minute)
  myStepper.setSpeed(10);
  
  // Initialize serial communication for monitoring joystick values
  Serial.begin(9600);
}

void loop() {
  // 1. Read the joystick X-axis analog value (range 0 - 1023)
  int xValue = analogRead(A0);
  
  // Print the current value to the serial monitor for debugging
  Serial.print("Joystick X-axis value: ");
  Serial.println(xValue);

  // 2. Determine joystick direction and control the motor
  if (xValue < 300) {
    // Joystick pushed to one side: step motor forward
    myStepper.step(10); 
  }
  else if (xValue > 800) {
    // Joystick pushed to the other side: step motor backward
    myStepper.step(-10); 
  } 
  else {
    // Joystick in neutral position (300 ~ 800)
    // De-energize all coils to prevent the stepper motor from overheating while idle
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
```

## Explicación del Código

1. **Inclusión de Librería e Inicialización:** La línea `#include <Stepper.h>` importa la librería de control del motor paso a paso. La línea `Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);` define los pines de control. **Importante:** Al usar esta librería oficial con el motor 28BYJ-48, los dos pines centrales deben intercambiarse (es decir, 10, 9 en lugar de 9, 10) para asegurar una rotación suave del motor.
2. **Lectura del Valor Analógico:** `analogRead(A0)` detecta continuamente la inclinación del joystick, devolviendo un número entre 0 y 1023.
3. **Respuesta de Movimiento (`step`):** Cada iteración del bucle mueve el motor un pequeño paso (`10` o `-10` pasos). Como el bucle se ejecuta muy rápido, mantener el joystick en una dirección hará que el motor se mueva de forma continua y suave.
4. **Protección de Apagado (`digitalWrite(..., LOW)`):** Los motores paso a paso tienden a bloquear el eje cuando se detienen porque las bobinas permanecen energizadas. Para evitar esto y reducir el calor, cuando el joystick está centrado (liberado), los cuatro pines de control se ponen en LOW para cortar la corriente de las bobinas, protegiendo el motor y la placa controladora de sobrecalentamiento.

## Resultado del Proyecto

Después de subir el código y alimentar el circuito:

1. **Estado Neutral:** Cuando el joystick no se toca, vuelve automáticamente al centro y el motor paso a paso permanece quieto sin calentarse.
2. **Empujar a la Izquierda/Abajo:** Mover el joystick hacia un lado (lectura < 300) hace que el motor paso a paso gire continuamente en sentido horario (o antihorario).
3. **Empujar a la Derecha/Arriba:** Mover el joystick hacia el lado opuesto (lectura > 800) invierte inmediatamente la dirección del motor para una rotación continua.
4. **Respuesta en Tiempo Real:** Cuando sueltas el joystick, este vuelve al centro y el motor frena y se detiene al instante. Abrir el monitor serial en tu computadora te permite ver los cambios de datos del joystick en tiempo real.

![P30](../media/P30.gif)