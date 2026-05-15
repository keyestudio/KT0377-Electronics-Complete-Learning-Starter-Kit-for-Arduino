# Proyecto 20: Servo


![](../media/2f4ec6cd76c063f95aff6f9da82c3c3c.png)

#### Descripción

El servo es un actuador que convierte señales eléctricas en desplazamiento mecánico. Juega un papel importante en la vida y se usa ampliamente en robótica, drones, hogares inteligentes así como en control industrial.

En este proyecto, escribimos código Arduino para controlar el servo mediante la placa de desarrollo UNO R3 (ch340).

#### Hardware

1\. Placa de desarrollo UNO R3 (ch340) x1

2\. Servo x1

3\. Cables DuPont

#### Principio de Funcionamiento

Hay cuatro componentes principales dentro de un servo hobby: un motor DC, una caja de engranajes, un potenciómetro y un circuito de control. El motor DC es de alta velocidad y bajo torque, pero la caja de engranajes reduce la velocidad a alrededor de 60 RPM y al mismo tiempo aumenta el torque.

![IMG_256](../media/23000e79c9f20006f20ebb27914f9a72.jpeg)

El potenciómetro está unido al engranaje final o al eje de salida, por lo que a medida que el motor gira, el potenciómetro también gira, produciendo así un voltaje relacionado con el ángulo absoluto del eje de salida. En el circuito de control, este voltaje del potenciómetro se compara con el voltaje que proviene de la línea de señal. Si es necesario, el controlador activa un puente H integrado que permite que el motor gire en cualquiera de las dos direcciones hasta que la diferencia entre las dos señales sea cero.

Un motor servo se controla enviando una serie de pulsos a través de la línea de señal. La frecuencia de la señal de control debe ser de 50Hz o debe ocurrir un pulso cada 20ms. El ancho del pulso determina la posición angular del servo y este tipo de servos usualmente pueden girar 180 grados (tienen límites físicos de recorrido).

![IMG_256](../media/929b5300df8cda083df6718be9802945.png)

Generalmente, los pulsos con duración de 1ms corresponden a la posición de 0 grados, 1.5ms a 90 grados y 2ms a 180 grados. Aunque la duración mínima y máxima de los pulsos puede variar a veces con diferentes marcas y pueden ser 0.5ms para 0 grados y 2.5ms para la posición de 180 grados.

#### Especificaciones

Motor Servo T-pro Mini SG-90 9g Servo

Mejor opción para aeronaves RC

Accesorios incluidos

Cumplimiento ROHS

Dimensiones: 23x12.2x29mm

Torque: 0.5kg/cm

Torque de bloqueo: 1.5kg/cm a 5V

Velocidad de operación: 0.3seg/60 grados a 4.8V

Voltaje de operación: 4.2-6V

Rango de temperatura: 0-55 °C

Ancho de banda muerto: 10us

Material de engranajes: Nylon

#### Pinout

![](../media/8403c76ee664e4aa065b54796191285c.png)

GND Tierra (Cable Marrón) – Este es el pin de tierra.

VCC +5V (Cable Rojo) – El voltaje se suministra al motor servo a través de este pin.

Control (Cable Naranja) – A través de este cable, se reciben señales de control de posición vía PWM.

#### Diagrama de Conexiones

1\. Conectar el cable rojo (positivo) del servo al pin 5V en la placa

2\. Conectar el cable negro (negativo) del servo al GND en la placa

3\. Conectar el cable naranja (señal) del servo al pin digital D9 en la placa

![Img](../media/img-20260401195822.png)




#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 20

Servo

Edit By Keyes

*/

#include <Servo.h>

Servo myservo; // create a Servo object

void setup() {

myservo.attach(9); // connect servo to digital pin 9

}

void loop() {

myservo.write(0); // rotate servo to 0 degree

delay(1000); // delay 1s

myservo.write(90); // rotate servo to 90 degree

delay(1000); // delay 1s

myservo.write(180); // rotate servo to 180 degree

delay(1000); // delay 1s

}
```

#### Explicación del Código

Importación de Librerías y Creación de un Objeto Servo

Primero, en la parte superior del programa Arduino, necesitamos incluir la librería `Servo.h`, lo cual se hace usando la directiva del preprocesador `#include <Servo.h>`. Luego, creamos un objeto de la clase `Servo`, llamado `myservo` en este ejemplo. Este objeto se usará para todas las operaciones posteriores relacionadas con el motor servo.

```cpp
#include <Servo.h>

Servo myservo; // Crear un objeto servo
```

Función Setup

En la función `setup()`, conectamos el motor servo a un pin digital específico en la placa Arduino. En este ejemplo, usamos el pin digital 9. La línea `myservo.attach(9);` vincula el objeto servo al pin digital 9, permitiendo que la señal de salida de ese pin controle el motor servo.

```cpp
void setup() {

myservo.attach(9); // Conectar el motor servo al pin digital 9

}
```

Función Loop

En la función `loop()`, escribimos la lógica específica para controlar el motor servo. Esta función se repetirá continuamente, formando un bucle infinito. En este ejemplo, hacemos que el motor servo gire a 0 grados, 90 grados y 180 grados, respectivamente. Después de cada rotación, el programa se pausa por un segundo (1000 milisegundos), lo cual se logra usando la función `delay(1000);`.

```cpp
void loop() {

myservo.write(0); // Girar servo a 0 grados

delay(1000); // Pausa por 1 segundo

myservo.write(90); // Girar servo a 90 grados

delay(1000); // Pausa por 1 segundo

myservo.write(180); // Girar servo a 180 grados

delay(1000); // Pausa por 1 segundo

}
```

En este proceso, la función `myservo.write(angle);` se usa para especificar el ángulo objetivo para el motor servo. El parámetro `angle` es un entero que representa el ángulo al que el motor debe girar. La librería Servo se encarga de generar las señales para asegurar que el motor se mueva a la posición especificada.

#### Resultado del Proyecto

Después de subir el código, el servo gira a 0°, 90° y 180°, manteniendo cada posición por 1 segundo. Estas acciones se repiten.

![P20](../media/P20.gif)