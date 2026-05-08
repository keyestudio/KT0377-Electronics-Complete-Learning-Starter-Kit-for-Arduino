# Proyecto 9: Potenciómetro


![IMG_256](../media/a176df2ce1eebc80bbb029d83867de89.jpeg)

#### Descripción

Un potenciómetro consiste en una perilla giratoria y una resistencia, cuyo valor de resistencia cambia al girar la perilla, controlando así la corriente en el circuito.

En este proyecto, creamos un circuito en el que el brillo del LED puede ajustarse mediante programación en la placa de desarrollo y girando el potenciómetro. Así podemos entender cómo funciona el potenciómetro y cómo usar entradas analógicas en Arduino.

#### Hardware

1\. Placa de desarrollo UNO R3 （ch340） x1

2\. Protoboard x1

3\. Potenciómetro (10kΩ) x1

4\. LED x1

5\. Resistencia de 220Ω x1

6\. Cables jumper

#### Principio de Funcionamiento

Un potenciómetro tiene 3 pines. Dos terminales (el azul y el verde) están conectados a un elemento resistivo y el tercer terminal (el negro) está conectado a un contacto deslizante ajustable.

![IMG_256](../media/13a0843a867097517fe08997cd9de5f9.png)

El potenciómetro puede funcionar como un **reóstato** (resistencia variable) o como un **divisor de voltaje**.

Reóstato

Para usar el potenciómetro como reóstato, solo se usan dos pines: un pin exterior y el pin central. La posición del contacto deslizante determina cuánta resistencia impone el potenciómetro al circuito, como muestra la figura:

![IMG_257](../media/e85814c25253e9a4d2fc875a63995aa9.png)

Si tenemos un potenciómetro de 10kΩ, significa que la resistencia máxima de la resistencia variable es 10kΩ y la mínima es 0Ω. Esto quiere decir que al cambiar la posición del contacto deslizante, se obtiene un valor entre 0Ω y 10kΩ.

Especificaciones:

Rango estándar de resistencia：10 a 2 megaohmios

Tolerancia de resistencia：±10 % estándar.

Resistencia mínima absoluta: 2 ohmios máx.

Variación de resistencia de contacto: 2 % o 3 ohmios máx. (el que sea mayor)

Voltaje: ±0.05 %

Resistencia: ±0.15 %

Resolución: Infinita

Resistencia de aislamiento: 500 VDC. 1,000 megaohmios mínimo.

Potencia nominal (300 voltios máx.)

85 °C：0.5 vatios

150 °C：0 vatios

Rango de temperatura：-55 °C a +125 °C

Coeficiente de temperatura：±100 ppm/°C

Torque：5.0 oz-in. máx.

#### Pinout

![](../media/8ddfc1bfdc39858329a24f5d541b8106.png)

#### Diagrama de Conexiones

1\. Inserte los tres pines del potenciómetro en los agujeros de la protoboard.

2\. Conecte un pin exterior del potenciómetro al pin de 5V de la placa de desarrollo.

3\. Conecte el otro pin exterior del potenciómetro al pin GND de la placa de desarrollo.

4\. Conecte el pin central del potenciómetro al pin de entrada analógica A1 de la placa de desarrollo.

5\. Conecte el ánodo del LED (pin largo) al pin digital 11 de la placa a través de una resistencia de 220Ω.

6\. Conecte el cátodo del LED (pin corto) al GND de la placa.

![Img](../media/img-20260401175754.png)



#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 9

Potentiometer

Edit By Keyes

*/

int potPin = A1; // Connect the potentiometer to analog pin A1

int ledPin = 11; // Connect LED to digital pin 11

int potValue = 0; // store the read values of potentiometer

int ledValue = 0; // store the brightness values of LED

void setup() {

pinMode(ledPin, OUTPUT); // set LED pin to output

}

void loop() {

potValue = analogRead(potPin); // Read the potentiometer value (range 0-1023)

ledValue = map(potValue, 0, 1023, 0, 255); // map the potentiometer value to the LED brightness(0-255)

analogWrite(ledPin, ledValue); // set LED brightness

delay(10); // delay

}
```

#### Explicación del Código

Primero, comencemos con la parte de definición e inicialización del código:

```cpp

int potPin = A1; // Connect the potentiometer to analog pin A1

int ledPin = 11; // Connect LED to digital pin 11

int potValue = 0; // store the read values of potentiometer

int ledValue = 0; // store the brightness values of LED

```

Aquí definimos cuatro variables:

`potPin`: define el pin de entrada analógica A1 en la placa Arduino donde está conectado el potenciómetro.

`ledPin`: define el pin digital 11 al que está conectado el LED.

`potValue`: se usa para almacenar los valores leídos del potenciómetro.

`ledValue`: se usa para almacenar los valores de brillo mapeados para el LED.

A continuación está la función `setup()`:

```cpp
void setup() {

pinMode(ledPin, OUTPUT); // set LED pin to output

}
```

La función `setup()` se ejecuta solo una vez en el código Arduino y se usa para configurar modos de pines o inicializar la comunicación serial. Aquí, configuramos `ledPin` como salida porque el LED necesita recibir señales de potencia desde el Arduino.

Luego, entramos en la función principal de bucle `loop()`:

```cpp
void loop() {

potValue = analogRead(potPin); // Read the potentiometer value (range 0-1023)

ledValue = map(potValue, 0, 1023, 0, 255); // map the potentiometer value to the LED brightness(0-255)

analogWrite(ledPin, ledValue); // set LED brightness

delay(10); // delay

}
```

La función `loop()` se ejecuta continuamente en el Arduino después de cargar el programa, realizando las siguientes operaciones:

1\. Lee el valor del potenciómetro desde `potPin` usando la función `analogRead()`. Los valores del potenciómetro van de 0 a 1023, representando la posición de la perilla del potenciómetro.

2\. Mapea el valor leído del potenciómetro (0-1023) al valor de brillo (0-255) que el LED puede aceptar usando la función `map()`. Esto es porque la función `analogWrite()` usada para la salida PWM solo acepta valores de 0 a 255.

3\. Envía el valor de brillo mapeado a `ledPin` usando la función `analogWrite()`, ajustando el brillo del LED en consecuencia.

4\. La llamada `delay(10)` pausa el bucle por 10 milisegundos después de cada ejecución. Esto reduce la frecuencia de lectura y evita parpadeos innecesarios causados por ajustar el brillo demasiado rápido.

#### Resultado del Proyecto

Después de cargar el código en la placa de desarrollo, gira el potenciómetro y verás cómo cambia el brillo del LED. Gira en sentido horario para que se ilumine más, y gira en sentido antihorario para que se oscurezca.

![](../media/d2c5fb58391a86f117ac34358eaffdde.png)

![P9](../media/P9.gif)