# Proyecto 13: Sensor Ultrasónico


![](../media/1be1364de2335da1f8eccfea2e2768ff.png)

#### Descripción

El sensor ultrasónico HC-SR04 es un sensor de medición de distancia comúnmente utilizado, que mide la distancia entre el objeto y el sensor. El sensor es pequeño, de bajo costo y fácil de usar, por lo que ha sido ampliamente utilizado en robótica, hogares inteligentes y control industrial.

En este proyecto, construimos un sistema de medición de distancia con la placa de desarrollo UNO R3 (ch340) y el sensor ultrasónico HC-SR04. A través de este proyecto, aprenderás cómo medir la distancia entre un objeto y el sensor usando el sensor ultrasónico HC-SR04 y mostrar los resultados de la medición en un monitor serial.

#### Hardware

1\. Placa de desarrollo UNO R3 (ch340) x1

2\. Sensor ultrasónico HC-SR04 x1

3\. Cables DuPont

#### Principio de Funcionamiento

Emite un ultrasonido a 40 000 Hz que viaja a través del aire y si hay un objeto u obstáculo en su camino, rebotará de vuelta al módulo. Considerando el tiempo de viaje y la velocidad del sonido, puedes calcular la distancia.

![](../media/c2be8c800c20ccc3b86e92f0f14ded4d.png)

Para generar el ultrasonido necesitamos poner el pin Trig en estado Alto durante 10 µs. Eso enviará un pulso ultrasónico de 8 ciclos que viajará a la [velocidad del sonido](https://es.wikipedia.org/wiki/Velocidad_del_sonido). El pin Echo se pone en alto justo después de que se envía ese pulso ultrasónico de 8 ciclos, y comienza a escuchar o esperar que esa onda sea reflejada por un objeto.

Si no hay objeto o pulso reflejado, el pin Echo se agotará después de 38 ms y volverá a estado bajo.

![](../media/ec9e76fec9b9b1d107577d42dc7d82b8.png)

Si recibimos un pulso reflejado, el pin Echo bajará antes de esos 38 ms. Según el tiempo que el pin Echo estuvo en ALTO, podemos determinar la distancia que la onda sonora viajó, y por lo tanto la distancia desde el sensor hasta el objeto.

Para ello usamos la siguiente fórmula básica para calcular la distancia:

*Distancia = Velocidad x Tiempo*

En realidad conocemos tanto la velocidad como el tiempo. El tiempo es la cantidad de tiempo que el pin Echo estuvo en ALTO, y la velocidad es la velocidad del sonido que es 340 m/s. Hay un paso adicional que debemos hacer, y es dividir el resultado final por 2, porque estamos midiendo la duración que la onda sonora necesita para viajar hasta el objeto y rebotar de vuelta.

![](../media/7b7a26c83a47a8a32c0a3835a253e25f.png)

Supongamos que el pin Echo estuvo en ALTO durante 2 ms. Si queremos obtener el resultado de la distancia en cm, podemos convertir la velocidad del sonido de 340 m/s a 34 cm/ms.

*Distancia = (Velocidad x Tiempo) / 2* **= (34cm/ms x 1.5ms) / 2 = 25.5cm.**

Entonces, si el pin Echo estuvo en ALTO durante 2 ms (lo que medimos usando la función **pulseIn()**), la distancia desde el sensor hasta el objeto es de 34 cm.

#### Especificaciones

Voltaje de trabajo DC 5V

Corriente de trabajo 15mA

Frecuencia de trabajo 40KHz

Rango máximo 4m

Rango mínimo 2cm

Ángulo de medición 15 grados

Señal de entrada Trigger Pulso TTL de 10µS

Señal de salida Echo Señal de nivel TTL proporcional a la distancia

#### Pinout

![](../media/85a3f8bd2c8d0111721f5213d699385a.png)

VCC suministra energía al sensor ultrasónico HC-SR04. Puedes conectarlo a la salida de 5V de tu Arduino.

El pin Trig (Trigger) se usa para disparar los pulsos ultrasónicos. Al poner este pin en ALTO durante 10 µs, el sensor inicia un pulso ultrasónico.

El pin Echo se pone en alto cuando se transmite el pulso ultrasónico y permanece en alto hasta que el sensor recibe un eco, después de lo cual vuelve a bajo. Midiendo el tiempo que el pin Echo permanece en alto, se puede calcular la distancia.

GND es el pin de tierra. Conéctalo a tierra del Arduino.

#### Diagrama de Conexiones

1\. Conecta el VCC del sensor ultrasónico al 5V de la placa

2\. Conecta el pin Trig del sensor ultrasónico al pin digital D6 de la placa

3\. Conecta el pin Echo del sensor ultrasónico al pin digital D5 de la placa

4\. Conecta el pin GND del sensor ultrasónico al GND de la placa

![Img](../media/img-20260401185431.png)


#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 13

Ultrasonic Sensor

Edit By Keyes

*/

const int trigPin = 6; // Define trigger pin number

const int echoPin = 5; // Define echo pin number

long duration; // Declare a long integer variable for storing the round-trip time of the ultrasonic pulse

int distance; // Declare an integer variable for storing the calculated distance

void setup() {

pinMode(trigPin, OUTPUT); // Set trigPin as output

pinMode(echoPin, INPUT); // Set echoPin as input

Serial.begin(9600); // Initialize serial communication with a baud rate of 9600

}

void loop() {

digitalWrite(trigPin, LOW); // Ensure the trigger pin is low

delayMicroseconds(2); // Wait for 2 microseconds

digitalWrite(trigPin, HIGH); // Send a 10-microsecond pulse

delayMicroseconds(10); // Keep the pulse for 10 microseconds

digitalWrite(trigPin, LOW); // End the pulse

duration = pulseIn(echoPin, HIGH); // Read the length of the pulse from the echo pin

// Calculate distance: sound speed is 0.034 cm per microsecond, divide the round-trip distance by 2

distance = duration * 0.034 / 2;

Serial.print("Distance: "); // Print text "Distance: "

Serial.print(distance); // Print the measured distance

Serial.println(" cm"); // Print the unit " cm" and go to the next line

delay(500); // Wait for 0.5 seconds before measuring again

}
```

#### Explicación del Código

Definición de Pines y Variables

```cpp

const int trigPin = 6;

const int echoPin = 5;

long duration;

int distance;

```

En esta sección, se definen dos constantes `trigPin` y `echoPin`, que representan los números de los pines digitales en la placa Arduino conectados a los pines trigger (Trig) y echo (Echo) del sensor HC-SR04. Además, se definen dos variables `duration` y `distance` para almacenar la duración de la señal de eco y la distancia calculada.

Función Setup

```cpp
void setup() {

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

Serial.begin(9600);

}
```

La función `setup()` es una función estándar de inicialización en el código Arduino que configura los modos de los pines e inicializa la comunicación serial. `pinMode(trigPin, OUTPUT)` y `pinMode(echoPin, INPUT)` configuran el pin Trig como salida y el pin Echo como entrada, respectivamente. `Serial.begin(9600)` inicia el puerto serial y establece la velocidad de transmisión de datos a 9600 bits por segundo, permitiendo que los datos se envíen al monitor serial en la computadora.

Bucle Principal

```cpp
void loop() {

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration * 0.034 / 2;

Serial.print("Distance: ");

Serial.print(distance);

Serial.println(" cm");

delay(500);

}
```

La función `loop()` contiene la lógica principal del programa y se ejecuta repetidamente. Primero, el pin Trig se pone en nivel bajo y se mantiene durante 2 microsegundos para asegurar la estabilidad de la transmisión de la señal ultrasónica. Luego, el pin Trig se pone en nivel alto durante 10 microsegundos, lo que dispara al sensor para enviar un pulso ultrasónico. Después, el pin Trig vuelve a nivel bajo, esperando que el pin Echo reciba el eco.

`duration = pulseIn(echoPin, HIGH);` mide el tiempo que el pin Echo permanece en nivel alto (es decir, el tiempo que tarda la onda ultrasónica en viajar de ida y vuelta). `distance = duration * 0.034 / 2;` calcula la distancia basada en la velocidad del sonido (aproximadamente 340 metros/segundo o 0.034 centímetros/microsegundo). Como la onda sonora debe viajar de ida y vuelta, la distancia real es el tiempo multiplicado por la velocidad y luego dividido por 2.

Finalmente, la distancia calculada se envía por el puerto serial, y hay un retardo de 500 milisegundos después de cada medición.

#### Resultado del Proyecto

Después de subir el código, abre el monitor serial y configura la velocidad en 9600 baudios. El valor de la distancia se mostrará en el monitor en cm. Cuando el objeto se acerca o se aleja del sensor, el valor cambia.

![](../media/ac72b74464cc5c7d2f3ed58cee36616b.png)

![P13](../media/P13.gif)