# Proyecto 1: Parpadeo de LED


![](../media/f5747eb89be492fd9aca3247fc125ad7.png)

#### Descripción

El LED, también conocido como diodo emisor de luz, es un dispositivo semiconductor que puede convertir la energía eléctrica en luz visible. Está compuesto por dos tipos diferentes de materiales semiconductores, uno con carga negativa y otro con carga positiva. Cuando la corriente fluye a través del LED, los electrones saltan de la capa negativa a la positiva, liberando fotones y produciendo luz.

En este proyecto, utilizaremos una placa Arduino y un LED para crear el clásico proyecto "Blink". A través de este proyecto, comprenderás el principio de funcionamiento de los LEDs y escribirás un programa simple para controlar el parpadeo del LED.

#### Hardware

1\. Placa de desarrollo UNO R3 (ch340) x1

2\. LED de 5mm x1

3\. Resistencia de 220 ohmios x1

4\. Protoboard x1

5\. Cables jumper

#### Conocimiento de Componentes

**¿Qué es una resistencia?**

La resistencia es el componente electrónico en el circuito que limita y regula el flujo de corriente. Su unidad es (Ω).

Las unidades mayores que ohmios son kiloohmios (KΩ) y megaohmios (MΩ). Al usarla, además del tamaño de la resistencia, también se debe prestar atención a su potencia. En el proyecto, las patas en ambos extremos de la resistencia deben doblarse en un ángulo de 90° para ajustarse correctamente a la protoboard. Si la pata es demasiado larga, puede cortarse a una longitud adecuada.

![IMG_256](../media/dfdb73d8035f6971d1908122ff52cc10.png)

**¿Qué es una protoboard?**

Una protoboard se utiliza para construir y probar circuitos rápidamente antes de finalizar cualquier diseño de circuito. La protoboard tiene muchos orificios en los que se pueden insertar componentes del circuito como circuitos integrados y resistencias. A continuación se muestra una protoboard típica:

![IMG_257](../media/4b8c42375b382b41345ddc71ffd702d6.jpeg)

![IMG_258](../media/2d675695f136fc09617082d55e5d160f.jpeg)

La protoboard tiene tiras de metal que corren debajo de la placa y conectan los orificios en la parte superior. Las tiras metálicas están dispuestas como se muestra a continuación. Note que las filas superior e inferior de orificios están conectadas horizontalmente, mientras que los orificios restantes están conectados verticalmente.

![IMG_259](../media/8520dafaedfffe613c9606b04331b04c.jpeg)

Para usar la protoboard, las patas de los componentes se colocan en los orificios. Cada conjunto de orificios conectados por una tira metálica debajo forma un ánodo.

**¿Qué es un LED?**

Un diodo emisor de luz (LED) es un dispositivo semiconductor que emite luz cuando una corriente eléctrica pasa a través de él. Cuando la corriente pasa por un LED, los electrones se recombinan con los huecos emitiendo luz en el proceso. Los LEDs permiten que la corriente fluya en la dirección directa y bloquean la corriente en la dirección inversa.

![](../media/bffdb1b357871e36a7c96429918340ff.png)

Los diodos emisores de luz son uniones p-n fuertemente dopadas. Según el material semiconductor utilizado y la cantidad de dopaje, un LED emitirá luz de color en una longitud de onda espectral particular cuando esté polarizado en directa. Como se muestra en la figura, un LED está encapsulado con una cubierta transparente para que la luz emitida pueda salir.

Símbolo del LED

El símbolo del LED es el símbolo estándar de un diodo, con la adición de dos pequeñas flechas que denotan la emisión de luz.

![](../media/f41eeb218b077ff027d4decc667409b8.png)

Circuito simple de LED

La figura a continuación muestra un circuito simple de LED.  
![](../media/a7731e4961a9354fa0a0fe06f17102fd.png)  
El circuito consta de un LED, una fuente de voltaje y una resistencia para regular la corriente y el voltaje.

#### Principio de Funcionamiento del LED

Cuando el diodo está polarizado en directa, los electrones minoritarios se envían de p → n mientras que los huecos minoritarios se envían de n → p. En la frontera de la unión, la concentración de portadores minoritarios aumenta. Los portadores minoritarios en exceso en la unión se recombinan con los portadores mayoritarios.

![](../media/b153ea7cce8868c0420ea717d0833c30.png)

La energía se libera en forma de fotones durante la recombinación. En diodos estándar, la energía se libera en forma de calor. Pero en los diodos emisores de luz, la energía se libera en forma de fotones. A este fenómeno lo llamamos electroluminiscencia. La electroluminiscencia es un fenómeno óptico y eléctrico donde un material emite luz en respuesta a una corriente eléctrica que pasa a través de él. A medida que aumenta el voltaje directo, la intensidad de la luz aumenta y alcanza un máximo.

#### Especificaciones del LED

Caída directa: 1.8-2.2VDC

Corriente máxima: 20mA

Corriente sugerida: 16-18mA

Intensidad luminosa: 150-200mcd

#### Pinout del LED

![IMG_256](../media/3301c3903482d2cd7f64740bdf055ebb.png)

Un LED tiene una pata positiva (ánodo) y una pata negativa (cátodo). El símbolo esquemático del LED es similar al del diodo excepto por dos flechas que apuntan hacia afuera. El ánodo (+) está marcado con un triángulo, y el cátodo (-) está marcado con una línea.

La pata más larga de un LED es generalmente la positiva (ánodo), mientras que la pata más corta es la negativa (cátodo).

#### Diagrama de Conexiones

1. Inserta el LED en la protoboard;

2. Conecta un extremo de la resistencia de 220 ohmios a la fila de la protoboard donde está el ánodo del LED, y conecta el otro extremo de la resistencia al pin digital 9 de la placa de desarrollo;

3. Conecta el pin GND de la placa mediante un cable jumper a la fila de la protoboard donde está el cátodo del LED.

![Img](../media/img-20260330185532.png)



#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 1

LED Blink

Edit By Keyes

*/

void setup() {

pinMode(9, OUTPUT); // Configura el pin digital 9 como salida

}

void loop() {

digitalWrite(9, HIGH); // Establece el pin digital 9 en alto, encendiendo el LED

delay(1000); // Espera 1000 milisegundos (1 segundo)

digitalWrite(9, LOW); // Establece el pin digital 9 en bajo, apagando el LED

delay(1000); // Espera 1000 milisegundos (1 segundo)

}
```

#### Explicación del Código

Primero, necesitamos definir una variable para representar el pin digital conectado al LED. En la programación de Arduino, esto se puede hacer con una línea simple de código:

```cpp

int ledPin = 9;

```

Esta línea de código define una variable llamada `ledPin` y la inicializa en 9, indicando que el LED está conectado al pin digital número 9 en la placa Arduino. En Arduino, cada pin digital puede usarse como pin de entrada o salida, dependiendo de cómo lo configuremos.

A continuación, necesitamos configurar el modo de `ledPin` para que pueda enviar señales correctamente al LED. Esto se hace usando la función `pinMode()`, con la siguiente sintaxis:

```cpp
pinMode(ledPin, OUTPUT);
```

Esta línea de código configura `ledPin` en modo salida (`OUTPUT`). En modo salida, la placa Arduino puede enviar señales de voltaje a los dispositivos conectados. Para un LED, esto significa que podemos controlar sus estados de encendido y apagado.

Una vez configurado el modo del pin, el siguiente paso es controlar los estados de encendido y apagado del LED enviando señales altas (HIGH) o bajas (LOW) al LED. Esto se hace usando la función `digitalWrite()`, representada por las siguientes dos líneas de código respectivamente:

```cpp
digitalWrite(ledPin, HIGH); // Enciende el LED

digitalWrite(ledPin, LOW); // Apaga el LED
```

Cuando el segundo parámetro de la función `digitalWrite()` es `HIGH`, Arduino emite un voltaje alto al `ledPin`, haciendo que el LED conectado se encienda. Por el contrario, cuando el parámetro es `LOW`, emite un voltaje bajo y el LED se apaga.

Para mantener el estado del LED (encendido o apagado) durante una cierta duración, usamos la función `delay()` para pausar la ejecución del programa. Por ejemplo:

```cpp

delay(1000);

```

Esta línea de código pausa el programa durante 1000 milisegundos (es decir, 1 segundo). Esto significa que el LED mantendrá su estado actual (ya sea encendido o apagado) durante un segundo. Ajustando el número de milisegundos en `delay()`, podemos controlar cuánto tiempo dura el estado del LED.

#### Resultado del Proyecto

![P1](../media/P1.gif)

Después de subir el código a la placa de desarrollo, el LED conectado al pin digital 9 comienza a parpadear y estará encendido y apagado durante 1 segundo.