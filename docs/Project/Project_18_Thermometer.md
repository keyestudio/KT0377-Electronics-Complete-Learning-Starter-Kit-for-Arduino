# Proyecto 18: Termómetro


![](../media/2eca65ae31760bbc6aed1525dcc0f8f8.png)

#### Descripción

Este proyecto tiene como objetivo diseñar un termómetro inteligente simple con Arduino utilizando un Termistor NTC-MF52AT 10K y una pantalla LCD. El sensor Termistor detecta la temperatura ambiente, y la pantalla LCD muestra el valor de la temperatura en tiempo real. Este proyecto sirve como un excelente ejercicio para principiantes, ya que les ayuda a entender el principio básico de funcionamiento de los sensores y practicar la interacción entre la pantalla y el sensor.

#### Hardware

1\. Placa de desarrollo UNO R3 （ch340） x1

2\. Termistor NTC-MF52AT 10K x1

3\. Pantalla LCD 16x2 x1

4\. Resistencias (220 ohmios) x1

5\. Protoboard x1

6\. Cables jumper

#### Principio de Funcionamiento

El principio de funcionamiento de este proyecto es el siguiente:

El Termistor NTC-MF52AT 10K detecta la temperatura ambiente y la convierte en una señal de voltaje analógico correspondiente.

El pin de entrada analógica de la placa de desarrollo Arduino (A0 en este caso) lee la salida de voltaje analógico del Termistor.

El convertidor analógico a digital (ADC) dentro del Arduino convierte el valor de voltaje analógico en una cantidad digital.

Basado en la fórmula de conversión del Termistor (donde cada 10mV corresponde a 1 grado Celsius), el Arduino convierte la cantidad digital en un valor de temperatura.

Luego, el Arduino muestra el valor de temperatura calculado en la pantalla de cristal líquido LCD1602.

#### Diagrama de Conexiones

**Sensor Termistor**

VCC: 5V del Arduino

GND: GND del Arduino

VOUT: A0 (pin de entrada analógica)

**LCD1602**

RS: Conectar al pin digital 11

EN: Conectar al pin digital 12

D4-D7: Conectar a los pines digitales 5, 4, 3, 2, respectivamente

![Img](../media/img-20260401193348.png)


#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 18

Thermometer

Edit By Keyes

*/

#include <LiquidCrystal.h>

// Initialize the GPIO pins: RS, E, D4, D5, D6, D7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0; // Thermistor connected to A0

void setup() {

// Set LCD column and row count

lcd.begin(16, 2);

// Display text on the first line

lcd.print("Temperature:");

}

void loop() {

// Read the analog value from Thermistor (0-1023)

int sensorValue = analogRead(sensorPin);

// Convert the analog value to voltage (unit: mV)

float voltage = sensorValue * (5000.0 / 1023.0);

// Calculate the temperature value (unit: Celsius)

float temperatureC = voltage / 10.0;

// Display the temperature value on the LCD second line

lcd.setCursor(0, 1);

lcd.print(temperatureC);

lcd.print(" C ");

// Update every second

delay(1000);

}
```

#### Explicación del Código

**Inclusión de Librerías e Inicialización**

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0; // Thermistor connected to A0
```

`#include <LiquidCrystal.h>`: Incluye la librería LiquidCrystal para el control del LCD.

`LiquidCrystal lcd(...)`: Inicializa el objeto lcd basado en las conexiones de los pines del LCD.

`const int sensorPin = A0;`: Define el pin analógico que conecta el sensor Termistor como A0.

**Función de Configuración setup()**

```cpp
void setup() {

lcd.begin(16, 2);

lcd.print("Temperature:");

}
```

`lcd.begin(16, 2);`: Configura el LCD para un modo de visualización de 16 columnas y 2 filas.

`lcd.print("Temperature:");`: Muestra “Temperature:” en la primera línea del LCD.

**Función Principal loop()**

```cpp
void loop() {

int sensorValue = analogRead(sensorPin);

float voltage = sensorValue * (5000.0 / 1023.0);

float temperatureC = voltage / 10.0;

lcd.setCursor(0, 1);

lcd.print(temperatureC);

lcd.print(" C ");

delay(1000);

}
```

**Leer Valor del Sensor**

```cpp

int sensorValue = analogRead(sensorPin);

```

`analogRead(sensorPin)`: Lee el valor de voltaje analógico del sensor Termistor, retornando un entero entre 0 y 1023.

**Convertir a Voltaje**

```cpp

float voltage = sensorValue * (5000.0 / 1023.0);

```

Convierte el valor del sensor a un valor real de voltaje en milivoltios.

`5000.0` corresponde al voltaje de referencia de 5V del Arduino, convertido a 5000mV.

`1023.0` es el valor máximo del ADC (escala ADC de 10 bits: 0-1023).

**Calcular Temperatura**

```cpp

float temperatureC = voltage / 10.0;

```

Según las especificaciones del Termistor, cada grado Celsius equivale a 10mV.

Por lo tanto, dividir el voltaje entre 10 da la temperatura actual en Celsius.

**Mostrar Temperatura en el LCD**

```cpp

lcd.setCursor(0, 1);

lcd.print(temperatureC);

lcd.print(" C ");

```

`lcd.setCursor(0, 1);`: Mueve el cursor a la segunda línea, primera columna del LCD.

`lcd.print(temperatureC);`: Muestra el valor de la temperatura.

`lcd.print(" C ");`: Muestra el símbolo de Celsius con espacios para cubrir cualquier carácter sobrante.

**Retardo de Un Segundo**

```cpp

delay(1000);

```

Espera 1000 milisegundos (1 segundo) para controlar la frecuencia de actualización.

#### Resultado del Proyecto

Al completar este proyecto, tendrás un probador de temperatura completamente funcional. Este dispositivo puede mostrar la temperatura ambiente en tiempo real y proporcionar retroalimentación visual para los cambios de temperatura.

![P18](../media/P18.gif)