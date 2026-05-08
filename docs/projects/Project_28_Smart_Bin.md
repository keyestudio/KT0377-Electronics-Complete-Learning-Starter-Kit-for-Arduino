# Proyecto 28: Contenedor Inteligente


![](../media/096c6f2a9c09b45e9e2fe7e7ba620340.png)

#### Descripción

El contenedor inteligente no solo tiene las funciones básicas de los cubos de basura tradicionales, sino que también integra una variedad de tecnologías inteligentes, lo que aporta mucha comodidad a nuestras vidas.

En este proyecto, hacemos un contenedor inteligente con la placa de desarrollo UNO R3 （ch340）, un sensor ultrasónico y un servo. Cuando alguien está cerca del contenedor, la tapa se abrirá automáticamente; cuando las personas se alejan, la tapa se cierra automáticamente.

#### Hardware

1. Placa de desarrollo UNO R3 （ch340） x1

2. Sensor ultrasónico HC-SR04 x1

3. Servo SG90 x1

4. Cables DuPont

5. Cables jumper

#### Principio de Funcionamiento

El sensor ultrasónico HC-SR04 calcula la distancia al objeto transmitiendo y recibiendo ondas ultrasónicas. Cuando se detecta una persona, el servo controla la apertura de la tapa. Cuando la persona se aleja, la tapa se cierra.

![](../media/f07fb3b0caa91f115f89698ad49c37af.png)

#### Diagrama de Conexiones

1.  Conectar el pin Trig del HC-SR04 al pin digital D6, el pin Echo al pin digital D5.
2.  Conectar el cable amarillo (señal) del servo al pin digital D10 en la placa.

![Img](../media/img-20260403150628.png)


#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 28

Smart Bin

Edit By Keyes

*/

#include <Servo.h>

const int trigPin = 6; // Ultrasonic sensor Trig pin

const int echoPin = 5; // Ultrasonic sensor Echo pin

const int servoPin = 10; // Servo motor pin

Servo myservo; // Create a servo object

void setup() {

pinMode(trigPin, OUTPUT); // Set Trig pin as output

pinMode(echoPin, INPUT); // Set Echo pin as input

myservo.attach(servoPin); // Attach servo motor to pin 10

myservo.write(0); // Initialize servo to 0 degrees

Serial.begin(9600); // Initialize serial communication with a baud rate of 9600

}

void loop() {

long duration, distance;

// Send a 10-microsecond high pulse to trigger the ultrasonic sensor

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Read the high pulse duration from the Echo pin

duration = pulseIn(echoPin, HIGH);

// Calculate distance (in centimeters)

distance = duration * 0.034 / 2;

// Print the distance value to the serial monitor

Serial.print("Distance: ");

Serial.print(distance);

Serial.println(" cm");

if (distance < 20) { // If the distance is less than 20 cm, open the lid

myservo.write(180);

delay(3000); // Keep it open for 3 seconds

} else { // If the distance is greater than 20 cm, close the lid

myservo.write(0);

}

delay(100); // Delay for 100 milliseconds

}
```

#### Explicación del Código

**Inclusión de la Biblioteca:**

```cpp
#include <Servo.h>
```

Esto incluye la biblioteca Servo de Arduino, que se usa para controlar el motor servo.

**Definición de Pines y Creación de Objeto:**

```cpp

const int trigPin = 6; // Pin Trig para el sensor ultrasónico

const int echoPin = 5; // Pin Echo para el sensor ultrasónico

const int servoPin = 10; // Pin para el motor servo

Servo myservo; // Crear un objeto servo

```

Define los pines Trig y Echo para el sensor ultrasónico y el pin para la conexión del motor servo. También crea un objeto servo para control posterior.

**Configuración Inicial:**

```cpp
void setup() {

pinMode(trigPin, OUTPUT); // Configurar el pin Trig como salida

pinMode(echoPin, INPUT); // Configurar el pin Echo como entrada

myservo.attach(servoPin); // Conectar el servo al pin digital 10

myservo.write(0); // Establecer la posición inicial del servo a 0 grados (posición cerrada)

Serial.begin(9600); // Inicializar comunicación serial a 9600 baudios

}
```

Configura los modos de los pines para el sensor ultrasónico, conecta el servo y establece su posición inicial. También inicia la comunicación serial para depuración y monitoreo de datos del sensor.

**Función Principal Loop:**

```cpp
void loop() {

// ... (continuación como arriba)

}
```

En el loop principal, se lee continuamente el sensor ultrasónico y se controla la acción del servo según la distancia.

**Disparo y Lectura del Sensor Ultrasónico:**

```cpp
// Enviar un pulso alto de 10 microsegundos para activar el sensor ultrasónico

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Leer la duración del pulso alto en el pin Echo

duration = pulseIn(echoPin, HIGH);
```

Envía una señal de pulso específica para activar el sensor ultrasónico, luego usa la función `pulseIn` para medir la duración del pulso alto en el pin Echo.

**Cálculo de la Distancia:**

```cpp

// Calcular la distancia (en centímetros)

distance = duration * 0.034 / 2;

```

Calcula la distancia desde el sensor hasta un objeto basado en el principio de los sensores ultrasónicos. El sonido viaja en el aire a aproximadamente 340 metros por segundo, o 0.034 centímetros por microsegundo. Como el sonido debe ir y volver, el resultado se divide por dos.

**Salida Serial de la Distancia:**

```cpp

// Imprimir la distancia en el monitor serial

Serial.print("Detected Distance: ");

Serial.print(distance);

Serial.println(" cm");

```

Envía la distancia calculada al monitor serial, que puede verse en el IDE de Arduino.

**Control del Motor Servo:**

```cpp

if (distance < 20) { // Si la distancia es menor a 20 cm, abrir la tapa del contenedor

myservo.write(180); // Girar el servo a 180 grados (posición abierta)

delay(3000); // Mantenerla abierta por 3 segundos

} else { // Si la distancia es 20 cm o mayor, cerrar la tapa del contenedor

myservo.write(0); // Girar el servo a 0 grados (posición cerrada)

}

```

Determina si alguien está cerca basado en la distancia. Si la distancia detectada es menor a 20 centímetros, asume que alguien se acerca y abre la tapa del contenedor, manteniéndola abierta por 3 segundos; de lo contrario, el servo mantiene la posición cerrada.

**Retraso en el Loop:**

```cpp

delay(100); // Retraso de 100 milisegundos para controlar la frecuencia del loop

```

Retrasa el loop 100 milisegundos para evitar que el ciclo se ejecute demasiado rápido y consuma recursos excesivos.

#### Resultado del Proyecto

Cuando alguien está cerca del contenedor (a menos de 20 cm), la tapa se abrirá automáticamente durante 3 segundos.

Cuando las personas se alejan (la distancia es mayor o igual a 20 cm), la tapa se cierra automáticamente para mantener el ambiente limpio.

![P28](../media/P28.gif)