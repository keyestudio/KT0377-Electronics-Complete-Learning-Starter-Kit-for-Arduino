# Proyecto 26: Ventilador con Control Remoto IR

## Introducción al Proyecto
En este proyecto, combinaremos la "tecnología de control remoto infrarrojo" con la "tecnología de conducción de motor de corriente continua" para crear un ventilador inteligente que pueda ser controlado de forma inalámbrica usando un control remoto. Los controles remotos infrarrojos se usan ampliamente en electrodomésticos como televisores y aires acondicionados. Usaremos un módulo receptor infrarrojo para capturar las señales enviadas por el control remoto (como los botones "adelante", "atrás" y "detener"). Después de decodificar estas señales con un Arduino, ordenaremos al chip L293D que cambie el estado operativo del ventilador (motor DC), logrando un control remoto integral.

## Hardware del Proyecto
Se requieren los siguientes componentes para completar este proyecto:
1. Placa de desarrollo UNO R3 (CH340) × 1
2. **Control Remoto Infrarrojo** × 1
3. **Módulo Receptor IR** × 1 *(Si usa un componente suelto, agregue capacitores de 100nF y 10μF según sea necesario)*
4. **Chip Driver de Motor L293D** × 1
5. **Motor DC 130** × 1
6. **Batería de 9V y clip para batería** × 1 (para alimentación independiente del motor)
7. Protoboard × 1 y varios cables Dupont

## Principio del Proyecto
Este proyecto involucra la operación coordinada de dos sistemas independientes:
1. **Decodificación de Señal Infrarroja (Decodificación IR):**  
   El control remoto infrarrojo emite señales de luz infrarroja moduladas por un portador de 38kHz a través de su LED IR frontal. El receptor IR captura esta luz, filtra interferencias ambientales y la convierte nuevamente en señales eléctricas. El Arduino usa la librería `IRremote` para decodificar estas señales mediante el protocolo NEC, convirtiéndolas en códigos hexadecimales (HEX) únicos. Cada botón corresponde a un código único.
2. **Conducción del Motor:**  
   Tras recibir el código decodificado del botón, el Arduino realiza comprobaciones lógicas (por ejemplo, ¿es el botón presionado la tecla "arriba"?). Una vez confirmado el comando, el Arduino envía la señal PWM de velocidad correspondiente y señales de dirección alta/baja al chip L293D. Usando el circuito puente H interno del L293D, controla de forma segura la rotación hacia adelante, hacia atrás o el frenado del motor.

## Instalación de la Librería (Instalar Librería IRremote)
Antes de escribir el código, debe instalar la librería dedicada al control remoto infrarrojo:
1. En el IDE de Arduino, haga clic en la barra de menú **Herramientas** -> **Administrar bibliotecas...**.
2. En la ventana emergente del Administrador de Bibliotecas, en el cuadro de búsqueda, escriba **`IRremote`**.
3. Busque la librería llamada `IRremote`, **seleccione la versión `2.0.1` en el menú desplegable de versiones** (para que coincida con la sintaxis de este tutorial, no instale la versión más reciente), luego haga clic en “Instalar.”
4. Espere hasta que el estado cambie a “Instalado,” luego cierre la ventana.

## Diagrama de Conexiones

**1. Pines del Receptor IR**  
* `VCC` ➔ Conectar a Arduino 5V  
* `GND` ➔ Conectar a GND común de la protoboard  
* `OUT (Pin de señal)` ➔ Conectar a **Arduino D2**

**2. Pines del Driver de Motor L293D**  
* `Pin 1 (Enable 1)` ➔ Conectar a **Arduino D10** *(control de velocidad PWM)*  
* `Pin 2 (Input 1)` ➔ Conectar a **Arduino D11** *(Dirección 1)*  
* `Pin 7 (Input 2)` ➔ Conectar a **Arduino D9** *(Dirección 2)*  
* `Pin 3 (Output 1)` ➔ Conectar a un terminal del motor DC  
* `Pin 6 (Output 2)` ➔ Conectar al otro terminal del motor DC  
* `Pin 16 (VCC1)` ➔ Conectar a Arduino 5V *(alimentación lógica del chip)*  
* `Pin 8 (VCC2)` ➔ Conectar al terminal positivo de la batería de 9V *(alimentación independiente del ventilador)*  
* `Pin 4, 5 (GND)` ➔ Conectar a GND común de la protoboard (Nota: el GND del Arduino y el terminal negativo de la batería de 9V deben compartir tierra común)  
![Img](../media/img-20260403134309.png)

## Código de Ejemplo

*Nota: Diferentes controles remotos tienen diferentes códigos de botón. Los códigos hexadecimales usados a continuación (por ejemplo, `0xFF629D`) son ejemplos de controles comunes en el mercado. Si los botones de su control no responden, abra el Monitor Serial, presione un botón, anote el código HEX mostrado y reemplace las sentencias `case` correspondientes en el código.*

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 26

IR Remote Fan

Edit By Keyes

*/

#include <IRremote.h> // Include IR library (version 2.0.1 required)

// --- 1. IR Receiver Pin Definition and Object Creation ---
const int RECV_PIN = 2; // IR receiver signal pin D2
IRrecv irrecv(RECV_PIN); // Create IR receiver object
decode_results results;  // Object to store decoding results

// --- 2. L293D Motor Control Pin Definition ---
const int enablePin = 10; // D10: motor speed control (PWM)
const int in1Pin = 11;    // D11: motor direction 1
const int in2Pin = 9;     // D9:  motor direction 2

void setup() {
  Serial.begin(9600);      // Initialize serial port at 9600 baud
  irrecv.enableIRIn();     // Start the IR receiver

  // Set motor pins as outputs
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  Serial.println("System initialized, waiting for IR signals...");
}

void loop() {
  // If an IR signal is received and decoded successfully
  if (irrecv.decode(&results)) { 
    // Print the received hexadecimal IR code to the serial monitor
    Serial.print("Received IR code: 0x");
    Serial.println(results.value, HEX); 

    // Execute corresponding action based on received button code
    switch (results.value) {
      
      // Button 1 (example code): Forward rotation (replace with your remote's "up" key code)
      case 0xFF629D: 
        setMotor(255, false); // Full speed forward
        Serial.println("Action: Fan forward (FORWARD)");
        break;

      // Button 2 (example code): Reverse rotation (replace with your remote's "down" key code)
      case 0xFFA857: 
        setMotor(255, true);  // Full speed backward
        Serial.println("Action: Fan backward (BACKWARD)");
        break;

      // Button 3 (example code): Stop (replace with your remote's "OK" or "stop" key code)
      case 0xFF02FD: 
        setMotor(0, false);   // Speed zero, stop
        Serial.println("Action: Fan stop (STOP)");
        break;
        
      default:
        // Unknown button, do nothing
        break;
    }
    
    // Prepare to receive the next signal
    irrecv.resume(); 
  }
  
  delay(100); // Slight delay to avoid excessive reading from rapid button presses
}

// --- 3. Custom Motor Control Function ---
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
```

## Explicación del Código
1. **Inclusión e Inicialización:** `#include <IRremote.h>` importa la librería. En `setup()`, `irrecv.enableIRIn()` activa el receptor para comenzar a escuchar en el pin D2 señales de 38kHz.
2. **Decodificación y Detección:** `irrecv.decode(&results)` es el método central. Escucha continuamente y devuelve `true` cuando se presiona un botón del control remoto, almacenando el código único decodificado en `results.value`.
3. **Despacho con Switch-Case:** Tras recibir el código, el programa usa una sentencia `switch` para compararlo. Si coincide con `case 0xFF629D:`, el programa sabe que quieres encender el ventilador, por lo que llama a la función personalizada `setMotor(255, false)`.
4. **Reinicio del Receptor:** `irrecv.resume()` es una línea frecuentemente olvidada pero crítica. Limpia el buffer y prepara el receptor para aceptar el siguiente comando. Sin ella, el receptor solo funciona una vez.

## Observación del Experimento
1. Después de cablear y subir el código, abra el **Monitor Serial** del IDE de Arduino y configure la velocidad de baudios en la esquina inferior derecha a `9600`.
2. Apunte el control remoto al receptor IR y presione botones. El Monitor Serial imprimirá códigos hexadecimales como `0xFF629D`.
3. **Paso importante para depurar:** Modifique los valores `0xFFxxxx` en la sentencia `switch` del código de ejemplo según los códigos reales que su control remoto emita, luego vuelva a subir el código.
4. Tras la depuración: presionar un botón específico hará que el ventilador gire hacia adelante a máxima velocidad; otro botón hará que gire hacia atrás a máxima velocidad; y presionar el botón de detener frenará suavemente y detendrá el ventilador. ¡Ahora tienes un ventilador inteligente controlable con un control remoto de TV!

![P26](../media/P26.gif)