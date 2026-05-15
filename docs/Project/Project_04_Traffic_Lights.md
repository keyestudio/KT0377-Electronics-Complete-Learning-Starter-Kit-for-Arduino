# Proyecto 4: Semáforos


![](../media/bf4ee74acad49c35a4f546f4128570c7.jpeg)

#### Descripción

Los semáforos son instalaciones importantes para la seguridad vial en la carretera. Utilizan diferentes colores de luz para dirigir el paso de vehículos y peatones, asegurando la seguridad y el orden en la vía.

Este proyecto utilizará una placa de desarrollo Arduino y LEDs para implementar un sistema simple de semáforo. Mediante la escritura de código Arduino, puedes controlar los LEDs de colores rojo, amarillo y verde para realizar las funciones básicas de un semáforo.

#### Hardware

1\. Placa de desarrollo UNO R3 (ch340) x1

2\. LED rojo x1

3\. LED amarillo x1

4\. LED verde x1

5\. Resistencia de 220 ohm x3

6\. Protoboard x1

7\. Cables jumper

#### Principio de Funcionamiento

Los semáforos son una parte indispensable del sistema de transporte moderno, que utilizan luces rojas, amarillas y verdes para controlar el paso de vehículos y peatones, asegurando así un tráfico ordenado y seguro. Este proyecto buscará cómo funcionan los semáforos.

Los semáforos están compuestos principalmente por un controlador electrónico y una luz señalizadora. El controlador electrónico es el "cerebro" del semáforo. Controla los cambios de la luz señalizadora según el tiempo y la lógica preestablecidos. Las luces señalizadoras suelen estar compuestas por LEDs o bombillas incandescentes, que muestran tres colores: rojo, amarillo y verde.

![](../media/fa43ca16e8dd51d521322b12418ddea2.jpeg)

El ciclo de funcionamiento de los semáforos se divide generalmente en cuatro etapas: luz roja, luz roja y amarilla, luz verde y luz amarilla. Durante la fase de luz roja, la luz roja se enciende y todos los vehículos y peatones deben detenerse y esperar. Cuando termina la luz roja, las luces roja y amarilla se encienden al mismo tiempo, indicando a conductores y peatones que se preparen para avanzar. A continuación, se enciende la luz verde y los vehículos y peatones pueden pasar. Finalmente, se enciende la luz amarilla, recordando a conductores y peatones que la luz verde está a punto de terminar y deben prepararse para detenerse o acelerar para pasar.

#### Diagrama de Conexiones

1.Conecta el ánodo del LED rojo al pin digital D10 en la placa, y el cátodo al pin GND con una resistencia de 220 ohm en serie;

2.Conecta el ánodo del LED amarillo al pin digital D7 en la placa, y el cátodo al pin GND con una resistencia de 220 ohm en serie;

3.Conecta el ánodo del LED verde al pin digital D4 en la placa, y el cátodo al pin GND con una resistencia de 220 ohm en serie;

![Img](../media/img-20260330191623.png)


#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 4

Traffic Lights

Edit By Keyes

*/

int redPin = 10; // Red LED is connected to digital pin 10

int yellowPin = 7; // Yellow LED is connected to digital pin 7

int greenPin = 4; // Green LED is connected to digital pin 4

void setup() {

pinMode(redPin, OUTPUT);

pinMode(yellowPin, OUTPUT);

pinMode(greenPin, OUTPUT);

}

void loop() {

// Red LED will be on for 5s

digitalWrite(redPin, HIGH);

delay(5000);

// Red LED will be off and green LED will be on for 3s

digitalWrite(redPin, LOW);

digitalWrite(greenPin, HIGH);

delay(3000);

// Green LED will be off and yellow LED will be on for 1s

digitalWrite(greenPin, LOW);

digitalWrite(yellowPin, HIGH);

delay(1000);

// Yellow LED will be off

digitalWrite(yellowPin, LOW);

}
```

#### Explicación del Código

El código define tres variables enteras, `redPin`, `yellowPin` y `greenPin`, que almacenan los números de los pines digitales conectados a los tres LEDs en la placa Arduino. El LED rojo está conectado al pin digital 10, el LED amarillo está conectado al pin digital 7 y el LED verde está conectado al pin digital 4.

```cpp

int redPin = 10; // Red LED connected to digital pin 10

int yellowPin = 7; // Yellow LED connected to digital pin 7

int greenPin = 4; // Green LED connected to digital pin 4

```

En la función `setup()`, estos tres pines se configuran en modo salida (`OUTPUT`) usando la función `pinMode()`. Esto es porque los LEDs necesitan recibir una señal de energía desde la placa Arduino para controlar su estado de encendido/apagado.

```cpp
void setup() {

pinMode(redPin, OUTPUT);

pinMode(yellowPin, OUTPUT);

pinMode(greenPin, OUTPUT);

}
```

La función `loop()` es el núcleo del programa Arduino y se ejecuta repetidamente. En esta función, la función `digitalWrite()` controla el estado de encendido/apagado de cada LED, mientras que la función `delay()` controla la duración de cada estado.

1\. Primero, el LED rojo se pone en nivel alto (`HIGH`), lo que significa que está encendido, durante 5 segundos (5000 milisegundos).

```cpp
digitalWrite(redPin, HIGH);

delay(5000);
```

2\. Después de 5 segundos, el LED rojo se apaga (se pone en nivel bajo, `LOW`), y el LED verde se enciende durante 3 segundos.

```cpp
digitalWrite(redPin, LOW);

digitalWrite(greenPin, HIGH);

delay(3000);
```

3\. A continuación, el LED verde se apaga y el LED amarillo se enciende solo durante 1 segundo.

```cpp
digitalWrite(greenPin, LOW);

digitalWrite(yellowPin, HIGH);

delay(1000);
```

4\. Finalmente, el LED amarillo se apaga.

```cpp
digitalWrite(yellowPin, LOW);
```

#### Resultado del Proyecto

Después de subir el código a la placa de desarrollo, los LEDs se encenderán y apagarán según la secuencia de tiempo establecida, simulando el estado de funcionamiento de un semáforo.

![P4](../media/P4.gif)

La luz roja está encendida durante 5s y luego se apaga; la luz verde está encendida durante 3s y luego se apaga; la luz amarilla está encendida durante 1s y luego se apaga.