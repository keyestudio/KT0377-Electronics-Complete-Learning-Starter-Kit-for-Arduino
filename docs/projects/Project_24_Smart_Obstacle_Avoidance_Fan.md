# Proyecto 24: Ventilador Inteligente con Evitación de Obstáculos

## Descripción
En este proyecto, construiremos un "ventilador inteligente" que responde a su entorno. Combinaremos el **sensor ultrasónico HC-SR04** con un motor DC controlado por un chip L293D. El sensor ultrasónico actúa como un detector de proximidad: cuando un objeto (como tu mano) se acerca demasiado a las aspas del ventilador, el motor se detendrá automáticamente para evitar lesiones; cuando el obstáculo se retire, el ventilador reanudará su giro automáticamente.

## Hardware
1. Placa de desarrollo UNO R3 (CH340) × 1  
2. **Sensor ultrasónico HC-SR04 × 1**  
3. Chip controlador de motor L293D × 1  
4. Motor DC 130 × 1  
5. Batería de 9V y clip para batería × 1 (para alimentación independiente del motor)  
6. Protoboard × 1  
7. Cables jumper × varios  

## Principio de Funcionamiento
1. **Medición de distancia ultrasónica:** El sensor HC-SR04 emite ondas sonoras de alta frecuencia y mide el tiempo que tarda el eco en regresar. Arduino calcula la distancia física delante basándose en el tiempo de ida y vuelta de la onda sonora.  
2. **Control lógico:** Establecemos un umbral de "distancia segura" en el código (por ejemplo, 15 cm). Arduino verifica continuamente la distancia medida por el sensor ultrasónico:  
   * Si la distancia es **mayor que** 15 cm: Arduino envía comandos al L293D mediante una función personalizada `setMotor` para hacer girar el motor DC a máxima velocidad.  
   * Si la distancia es **menor o igual a** 15 cm: Arduino envía inmediatamente una orden de parada al L293D, y el motor frena instantáneamente.  

## Diagrama de Conexiones

**1. Pines del sensor ultrasónico HC-SR04**  
* `VCC` ➔ Conectar a 5V del Arduino  
* `GND` ➔ Conectar a GND del Arduino  
* `Trig (Trigger)` ➔ Conectar a **Arduino D8**  
* `Echo (Echo)` ➔ Conectar a **Arduino D7**  

**2. Pines del controlador de motor L293D (siguiendo el método seguro de conexión anterior)**  
* `Pin 1 (Enable 1)` ➔ Conectar a **Arduino D10** *(para control de velocidad / arranque-parada)*  
* `Pin 2 (Input 1)` ➔ Conectar a **Arduino D11** *(control de dirección 1)*  
* `Pin 7 (Input 2)` ➔ Conectar a **Arduino D9** *(control de dirección 2)*  
* `Pin 3 (Output 1)` ➔ Conectar a un terminal del motor  
* `Pin 6 (Output 2)` ➔ Conectar al otro terminal del motor  
* `Pin 16 (VCC1)` ➔ Conectar a 5V del Arduino *(alimentación lógica)*  
* `Pin 8 (VCC2)` ➔ Conectar al terminal positivo de la batería de 9V *(alimentación independiente del motor)*  
* `Pin 4, 5 (GND)` ➔ Conectar a GND común de la protoboard (incluyendo GND del Arduino y terminal negativo de la batería)  

![Img](../media/img-20260403133003.png)

## Código de Ejemplo

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 24

Smart Obstacle Avoidance Fan

Edit By Keyes

*/

// --- 1. Ultrasonic sensor pin definitions ---
const int trigPin = 8;  // Trigger pin
const int echoPin = 7;  // Echo pin

// --- 2. L293D motor driver pin definitions ---
const int enablePin = 10; // D10: motor speed control (PWM)
const int in1Pin = 11;    // D11: motor direction control 1
const int in2Pin = 9;     // D9:  motor direction control 2

// --- 3. Parameter settings ---
const int safeDistance = 15; // Safe distance threshold set to 15 cm

void setup() {
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize motor control pins
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Start serial communication to monitor distance data on PC
  Serial.begin(9600);
}

void loop() {
  // ================= Step 1: Emit sound wave and measure distance =================
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Emit 10 microseconds high-frequency sound pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of echo pin being HIGH (microseconds)
  long duration = pulseIn(echoPin, HIGH);
  // Calculate distance (speed of sound approx. 0.034 cm/us, divide by 2 for round trip)
  int distance = duration * 0.034 / 2;
  
  // Print current distance to serial monitor
  Serial.print("Current distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // ================= Step 2: Control motor start/stop based on distance =================
  // Add distance > 0 to avoid misjudgment when sensor occasionally returns 0
  if (distance > 0 && distance <= safeDistance) {
    // Obstacle too close! Set speed to 0 and stop motor.
    setMotor(0, false);
    Serial.println(">>> Status: Danger! Braking <<<");
  } else {
    // Safe ahead! Set speed to 255, full speed forward.
    setMotor(255, false);
    Serial.println("Status: Running normally...");
  }
  
  // Short delay to avoid interference from too frequent measurements
  delay(100); 
}

// ================= Custom motor control function =================
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
```

## Explicación del Código

**1. Medición de distancia (`pulseIn` función):**  
```cpp
long duration = pulseIn(echoPin, HIGH);
int distance = duration * 0.034 / 2;
```
La función `pulseIn()` mide cuánto tiempo el pin Echo permanece en estado HIGH. Multiplicamos este tiempo por la velocidad del sonido (0.034 cm por microsegundo), luego dividimos por 2 porque el sonido viaja hasta el objeto y regresa, para obtener la distancia correcta de ida en centímetros.

**2. Lógica segura para evitar obstáculos:**  
```cpp
if (distance > 0 && distance <= safeDistance)
```
Comprobamos si la distancia es menor o igual a la `safeDistance` (15 cm). La condición `distance > 0` se añade porque el sensor ultrasónico a veces devuelve 0 cuando está fuera de rango o no recibe eco. Sin esta comprobación, el ventilador podría detenerse erróneamente cuando el sensor devuelve 0.

**3. Uso de control seguro del motor:**  
El código continúa usando la función `setMotor()` escrita anteriormente. Esto asegura que sin importar cómo cambie el programa principal, la lógica mutuamente exclusiva que controla la dirección (`!reverse`) protege el chip de cortocircuitos.

## Resultado del Proyecto
Después de cargar el código en Arduino y conectar la batería de 9V:  
1. El motor DC comenzará a girar inmediatamente.  
2. Coloca tu mano o un libro a unos 10–15 cm frente al sensor ultrasónico, y el motor **se detendrá inmediatamente**.  
3. Aleja tu mano, y el motor **reanuda su giro automáticamente**.  
4. Si abres el **Monitor Serial** del IDE de Arduino (velocidad en baudios configurada a 9600), podrás ver la distancia medida en tiempo real y el estado de funcionamiento del ventilador.

![P24](../media/P24.gif)