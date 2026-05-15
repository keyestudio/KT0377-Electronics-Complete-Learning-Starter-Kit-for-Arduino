# Proyecto 22: Relé de 5V


![](../media/66d16dff818af8aa3837bab9b5a94190.png)

#### Descripción

El módulo relé se usa para controlar corrientes o voltajes altos en un circuito. Consiste en una bobina y un contacto. Cuando la bobina se energiza, los contactos se cierran, y entonces el circuito se conecta. Cuando la bobina se apaga, el contacto se desconecta, rompiendo así el circuito.

En este proyecto, controlamos el módulo relé de 5V a través de la placa de desarrollo Arduino, para así realizar el control de encendido y apagado de un circuito o equipo externo. Cuando Arduino emite un nivel alto, el relé se activa y el contacto normalmente abierto se cierra, conectando el circuito externo; cuando Arduino emite un nivel bajo, el relé vuelve a su estado inicial y desconecta el circuito externo.

#### Hardware

1. Placa de desarrollo UNO R3 (ch340) x1

2. Relé de 5V x1

3. LED x1

4. Resistencia de 220 ohmios x1

5. Cables DuPont

#### Principio de Funcionamiento

En el núcleo de un relé hay un electroimán (una bobina de alambre que se convierte en un imán temporal cuando pasa electricidad por ella). Un relé puede considerarse como una palanca eléctrica; se activa con una corriente relativamente pequeña, y activa otro dispositivo con una corriente mucho mayor.

Fundamentos del Relé

Aquí hay una pequeña animación que muestra cómo un relé conecta dos circuitos juntos.

![](../media/c059e6e9d96fb9fd27c4960fa9d5b498.GIF)

Para ilustrar, piensa en dos circuitos simples: uno con un electroimán y un interruptor o sensor, y el otro con un interruptor magnético y una bombilla.

Inicialmente, ambos circuitos están abiertos, sin corriente fluyendo por ellos.

Cuando una pequeña corriente fluye por el primer circuito, el electroimán se energiza, creando un campo magnético a su alrededor. El electroimán energizado atrae el contacto del segundo circuito, cerrando el interruptor y permitiendo que fluya una corriente grande.

Cuando la corriente en el primer circuito deja de fluir, el contacto vuelve a su posición original, reabriendo el segundo circuito.

Especificaciones

Voltaje de alimentación – 3.3V a 5V

Corriente en reposo: 2mA

Corriente cuando el relé está activo: ~70mA

Voltaje máximo de contacto del relé – 250VAC o 30VDC

Corriente máxima del relé – 10A

#### Pinout

![IMG_256](../media/e980a7520e528d5217c5d6387ab70a0d.jpeg)

GND es el pin de tierra común.

El pin VCC suministra energía al módulo.

S se usa para controlar el relé. Este es un pin activo bajo, lo que significa que llevarlo a LOW activa el relé y llevarlo a HIGH lo desactiva.

Terminales de salida:

El terminal COM se conecta al dispositivo que deseas controlar.

El terminal NC está normalmente conectado al terminal COM, a menos que actives el relé, lo que rompe la conexión.

El terminal NO está normalmente abierto, a menos que actives el relé, que lo conecta al terminal COM.

#### Diagrama de Conexiones

1\. Conecta el pin VCC del relé al 5V del Arduino

2\. Conecta el pin GND del relé al GND del Arduino

3\. Conecta el pin S del relé al pin digital D3 del Arduino

4\. Conecta un circuito o dispositivo externo a los contactos normalmente abiertos y común del relé

Las conexiones de alto voltaje pueden hacerse a este terminal de tornillo. Por ejemplo: bombilla, ventilador de techo, etc. Pero en este proyecto solo usamos un LED.

Cuando haces la conexión entre a) y b), el LED conectado está siempre ENCENDIDO hasta que recibe una señal del Arduino para apagarlo.

Cuando haces la conexión entre b) y c), el LED conectado está APAGADO hasta que recibe una señal del Arduino para encenderlo.

![Img](../media/img-20260402165139.png)


#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 22

5V Relay

Edit By Keyes

*/

const int relayPin = 3; // set relay pin

void setup() {

pinMode(relayPin, OUTPUT); // set pin to output

}

void loop() {

digitalWrite(relayPin, HIGH); // output high to trigger the relay

delay(1000); // delay 1s

digitalWrite(relayPin, LOW); //output low to disable the relay

delay(1000); // delay 1s

}
```

#### Explicación del Código

Primero, comencemos con la primera línea del código:

```cpp

const int relayPin = 3; // set relay pin

```

Esta línea define una constante llamada `relayPin` y le asigna el valor 3. En Arduino, `const int` se usa para definir una constante entera, lo que significa que una vez asignada, `relayPin` no puede cambiarse durante la ejecución del programa. El número 3 aquí indica que el relé está conectado al pin digital I/O 3 en la placa Arduino.

Luego está la función `setup()`:

```cpp
void setup() {

pinMode(relayPin, OUTPUT); // set pin to output

}
```

La función `setup()` es una parte obligatoria de cada programa Arduino. Se ejecuta solo una vez y se usa para la inicialización. En esta función, llamamos a `pinMode()`, que es una función incorporada en el lenguaje Arduino usada para configurar el modo de un pin específico. La función `pinMode()` toma dos parámetros: el número de pin y el modo. Aquí, configuramos el modo de `relayPin` (es decir, el pin digital 3) como `OUTPUT`, lo que significa que este pin se usará como salida para enviar voltaje.

Luego viene la función `loop()`:

```cpp
void loop() {

digitalWrite(relayPin, HIGH); // output high to trigger the relay

delay(1000); // delay 1s

digitalWrite(relayPin, LOW); //output low to disable the relay

delay(1000); // delay 1s

}
```

La función `loop()` es el núcleo del programa Arduino. Se ejecuta repetidamente después de que la placa Arduino se enciende. En esta función, usamos la función `digitalWrite()` para controlar el relé. La función `digitalWrite()` también toma dos parámetros: el número de pin y el estado (HIGH o LOW). Primero, configuramos `relayPin` a `HIGH`, lo que envía un voltaje de 5V al relé, activándolo para que se cierre. Luego, el programa se pausa durante 1000 milisegundos (es decir, 1 segundo) usando `delay(1000);`, para que el relé permanezca cerrado un tiempo.

Después de eso, `digitalWrite(relayPin, LOW);` configura el estado del pin a `LOW`, cortando el suministro de voltaje al relé, lo que hace que vuelva al estado abierto. La función `delay(1000);` se llama nuevamente para pausar el programa por 1 segundo, y luego este ciclo comienza de nuevo.

#### Resultado del Proyecto

Después de subir el código, el relé cambia su estado (encendido o apagado) cada segundo. Cuando el relé está encendido, NO se conecta a COM y el circuito externo se cierra. Cuando el relé está apagado, NO se desconecta de COM y el circuito se abre.

![P22](../media/P22.gif)