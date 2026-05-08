# Proyecto 6: Zumbador Activo


![](../media/4039ba1aabe3a7c78713ec9eed7aea33.png)

#### Descripción

Un zumbador activo es un zumbador con un circuito de accionamiento incorporado. En comparación con los zumbadores pasivos tradicionales, se caracteriza por su tamaño pequeño, tono ajustable y accionamiento simple. En la vida diaria, a menudo nos encontramos con zumbadores activos, como en teléfonos móviles, computadoras y electrodomésticos.

En este proyecto, haremos un sistema de alarma simple mediante una placa Arduino y un zumbador activo. Este sistema puede usarse en diversas situaciones, como avisos de timbre o advertencias de temperatura excesiva.

#### Hardware

1\. Placa de desarrollo UNO R3 (ch340) x1

2\. Zumbador activo x1

3\. Cables jumper

#### Principio de Funcionamiento

El zumbador activo es un dispositivo electrónico común para generar sonido y se usa ampliamente en diversos equipos electrónicos. Así es como funciona:

1.  Circuito de oscilación: El zumbador activo contiene un circuito de oscilación en su interior, que generalmente está compuesto por resistencias, condensadores, transistores y otros componentes. Cuando el zumbador está encendido, el circuito de oscilación genera una señal eléctrica de una frecuencia específica.
1.  Elemento piezoeléctrico: El zumbador también contiene un elemento piezoeléctrico, que generalmente está hecho de cerámica piezoeléctrica o película piezoeléctrica. Los elementos piezoeléctricos tienen propiedades únicas: cuando se aplica un voltaje, producen una deformación mecánica; a la inversa, cuando se someten a una tensión mecánica, generan un voltaje.

3. Generación de sonido: La señal eléctrica generada por el circuito de oscilación se aplica al elemento piezoeléctrico, lo que provoca que se deforme mecánicamente de forma rápida y empuje el aire circundante para generar ondas sonoras. La frecuencia de la onda sonora depende de la frecuencia del circuito de oscilación, por lo que el tono emitido por el zumbador puede controlarse cambiando los parámetros del circuito de oscilación.

4. Circuito de accionamiento: El zumbador activo tiene un circuito de accionamiento incorporado simple para amplificar la señal generada por el circuito de oscilación y proporcionar suficiente corriente al elemento piezoeléctrico para producir un sonido lo suficientemente fuerte.

![IMG_256](../media/bdad47352afd45130d53e693cd185e27.png)

En resumen, el zumbador activo genera una señal eléctrica de una frecuencia específica a través de un circuito de oscilación interno y utiliza un elemento piezoeléctrico para convertir la señal eléctrica en sonido. Este principio de funcionamiento simple y efectivo hace que el zumbador activo sea un dispositivo electrónico comúnmente utilizado para generar sonido.

#### Especificaciones

Voltaje de operación Min/Máx: +3.3V a +5V

Corriente máxima: 30mA

Frecuencia de resonancia: 2500Hz ± 300Hz continua

Salida mínima de sonido: 85Db @ 4in (10cm)

Temperatura de almacenamiento: -22°F a 221°F (-30°C a 105°C)

Temperatura de operación: -4°F a 158°F (-20°C a 70°C)

#### Pinout

![IMG_256](../media/a48b7bfc855107e71447c544d7945e9f.png)

#### Diagrama de Conexiones

1\. Conecte el polo positivo del zumbador activo (usualmente "S" o "+") al pin digital D8 en la placa de desarrollo.

2\. Conecte el polo negativo del zumbador (“-”) a GND.

![Img](../media/img-20260330192707.png)



#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 6

Active Buzzer

Edit By Keyes

*/

const int BUZZER_PIN = 8;// Define the digital port to which the buzzer is connected

void setup() {

// Set the buzzer port to output mode

pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {

// Make the buzzer sound

digitalWrite(BUZZER_PIN, HIGH);

delay(1000); // Sound lasts 1s

// Stop sounding

digitalWrite(BUZZER_PIN, LOW);

delay(1000); // Stop sounding for 1s

}
```

#### Explicación del Código

```cpp

const int BUZZER_PIN = 8; // Define a constant BUZZER_PIN with a value of 8, indicating the buzzer is connected to digital pin 8

```

Primero, el código define una constante `BUZZER_PIN` para almacenar el número de pin 8 donde está conectado el zumbador. Usar una constante hace que el código sea más fácil de entender y mantener.

```cpp
void setup() {

// Set the buzzer pin to output mode

pinMode(BUZZER_PIN, OUTPUT);

}
```

La función `setup()` es una función especial de inicialización en Arduino que se ejecuta primero cuando el programa comienza o se reinicia. Aquí, la función `pinMode()` configura el pin del zumbador en modo salida. Esto significa que el pin emitirá una señal de voltaje para controlar un dispositivo externo—en este caso, el zumbador.

```cpp
void loop() {

// Make the buzzer sound

digitalWrite(BUZZER_PIN, HIGH);

delay(1000); // Sound for 1 second

// Stop the sound

digitalWrite(BUZZER_PIN, LOW);

delay(1000); // Stop for 1 second

}
```

La función `loop()` se ejecuta continuamente y es el bloque funcional principal del código Arduino. En este ciclo, el código usa la función `digitalWrite()` para poner el pin en `HIGH`, haciendo que el zumbador suene. Luego, usa `delay(1000)` para crear una pausa de 1 segundo, permitiendo que el zumbador suene durante 1 segundo. Después, el código pone el pin en `LOW` para detener el sonido del zumbador y vuelve a pausar por 1 segundo. Por lo tanto, este ciclo hace que el zumbador suene durante 1 segundo y se detenga durante 1 segundo en un patrón alterno regular.

#### Resultado del Proyecto

Después de subir el código anterior a la placa de desarrollo, el zumbador activo emitirá un sonido cada segundo, formando un sonido intermitente.

![P6](../media/P6.gif)

Esta salida puede usarse como diversas señales de aviso o advertencia.