# Proyecto 17: LCD 1602


![IMG_256](../media/c1ac4699b15f913827b8d8a2657854c9.GIF)

#### Descripción

El LCD 1602 cuenta con 16 columnas y 2 filas que pueden mostrar un total de 32 caracteres. Es fácil de usar y tiene un bajo costo, por lo que se utiliza ampliamente en diversos equipos electrónicos.

En este proyecto, escribiremos programas en la placa de desarrollo Arduino para controlar el LCD 1602 y mostrar lo que queremos.

#### Hardware

1\. Placa de desarrollo UNO R3 （ch340） x1

2\. Pantalla LCD 1602 x1

3\. Potenciómetro de 10K x1

4\. Protoboard x1

5\. Cables jumper

#### Principio de Funcionamiento

Una pantalla LCD es un módulo de visualización electrónica que utiliza cristal líquido para producir una imagen visible. La pantalla LCD 16×2 es un módulo muy básico comúnmente usado en [DIYs](https://www.electronicsforu.com/category/electronics-projects/hardware-diy) y circuitos. El 16×2 significa una pantalla de 16 caracteres por línea en 2 líneas. En este LCD, cada carácter se muestra en una matriz de píxeles de 5×7.

![/data/weboffice/tmp/webword_1554412927/upload_post_object_v2_656871922](../media/e24c10a46607d364b31f23fc0820c57d.jpeg)

#### Especificaciones

Tipo de pantalla: Pantalla de caracteres alfanuméricos

Formato de caracteres: Matriz de 5x8 puntos

Tamaño de pantalla: 16 caracteres x 2 líneas

Color de pantalla: Azul o Verde

Retroiluminación: Retroiluminación LED

Suministro de voltaje: 5V DC

Temperatura de operación: -20°C a +70°C

Interfaz: Modo de 4 bits o 8 bits

Dimensiones: 84.0 x 44.0 x 13.0 mm

#### Pinout

![IMG_256](../media/78ad1bc8515e80f4bdfc4e75d5d8b95a.png)

| **No.** | **Marca** | **Descripción del Pin**       | **No.** | **Marca** | **Descripción del Pin**       |
|---------|-----------|-------------------------------|---------|-----------|-------------------------------|
| 1       | VSS       | Tierra de alimentación         | 9       | D2        | Entrada/Salida de datos        |
| 2       | VDD       | Alimentación positiva          | 10      | D3        | Entrada/Salida de datos        |
| 3       | V0        | Señal de polarización del LCD | 11      | D4        | Entrada/Salida de datos        |
| 4       | RS        | Selección de datos/comando (V/L) | 12      | D5        | Entrada/Salida de datos        |
| 5       | R/W       | Selección lectura/escritura (H/L) | 13      | D6        | Entrada/Salida de datos        |
| 6       | E         | Señal de habilitación          | 14      | D7        | Entrada/Salida de datos        |
| 7       | D0        | Entrada/Salida de datos        | 15      | A         | Alimentación positiva de retroiluminación |
| 8       | D1        | Entrada/Salida de datos        | 16      | K         | Alimentación negativa de retroiluminación |

Dos pines de alimentación, uno para la alimentación del módulo y otro para la retroiluminación, generalmente usan 5V. En este proyecto, usamos 3.3V para la retroiluminación.

**V0** es el pin para ajustar el contraste. Usualmente se conecta un potenciómetro (no mayor a 5KΩ) en serie para su ajuste. En este experimento, usamos una resistencia de 1KΩ. Para su conexión, hay dos métodos, potencial alto y potencial bajo. Aquí usamos el método de potencial bajo; conectamos la resistencia y luego a tierra (GND).

**RS** es un pin muy común en el LCD. Es un pin de selección para comando/dato. Cuando el pin está en nivel alto, está en modo datos; cuando está en nivel bajo, está en modo comando.

**RW** también es un pin muy común en el LCD. Es un pin de selección para lectura/escritura. Cuando el pin está en nivel alto, está en operación de lectura; si está en nivel bajo, está en operación de escritura.

**E** también es un pin muy común en el LCD. Usualmente, cuando la señal en el bus está estabilizada, envía un pulso positivo que requiere operación de lectura. Cuando este pin está en nivel alto, no se permite ningún cambio en el bus.

**D0-D7** es un bus paralelo bidireccional de 8 bits, usado para transmisión de comandos y datos.

**BLA** es el ánodo para la retroiluminación; **BLK**, el cátodo para la retroiluminación.

#### Diagrama de Conexiones

Conectar el pin VSS del LCD 1602 a GND

Conectar el pin VDD del LCD 1602 a 5V

Conectar el pin V0 del LCD 1602 al pin central del potenciómetro de 10K, y los dos extremos del potenciómetro se conectan a 5V y GND respectivamente.

Conectar el pin RS del LCD 1602 al pin digital D12 del Arduino

Conectar el pin RW del LCD 1602 a GND

Conectar el pin E del LCD 1602 al pin digital D11 del Arduino

Conectar el pin D4 del LCD 1602 al pin digital D5 del Arduino

Conectar el pin D5 del LCD 1602 al pin digital D4 del Arduino

Conectar el pin D6 del LCD 1602 al pin digital D3 del Arduino

Conectar el pin D7 del LCD 1602 al pin digital D2 del Arduino

Conectar el pin A del LCD 1602 a 5V, y el pin K a GND

![IMG_256](../media/78ad1bc8515e80f4bdfc4e75d5d8b95a.png)

![Img](../media/img-20260401192640.png)




#### Código de Ejemplo

```cpp

/*

Electronics Learning Starter Kit for Arduino

Project 17

1602 LCD

Edit By Keyes

*/

#include <LiquidCrystal.h>

// Initialize 1602 LCD and set the Arduino pin

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

// set the numbers of row and column of 1602 LCD

lcd.begin(16, 2);

// Print character strings on 1602 LCD

lcd.print("Hello, world!");

}

void loop() {

// set the the cursor to row 2 column 0

lcd.setCursor(0, 1);

// Print the current operating time in ms

lcd.print(millis() / 1000);

}
```

#### Explicación del Código

Introducción a la Biblioteca LiquidCrystal

```cpp
#include <LiquidCrystal.h>
```

Esta línea de código es el inicio del programa. Incluye la biblioteca LiquidCrystal usando la directiva `#include`. Esta biblioteca provee funciones y métodos para controlar pantallas de cristal líquido (LCD), particularmente aquellas compatibles con el controlador HD44780. Este tipo de LCD es muy común y ampliamente usado para mostrar texto en varios dispositivos.

Inicializando el LCD

```cpp

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

```

Esta línea de código crea un objeto `LiquidCrystal` llamado `lcd`. Los números dentro de los paréntesis representan los pines de Arduino conectados al LCD. Estos pines son RS, E, D4, D5, D6 y D7, respectivamente. Este método de conexión se conoce como modo de 4 bits, donde solo se usan cuatro líneas de datos (D4 a D7) para transmitir datos.

Función Setup

```cpp
void setup() {

lcd.begin(16, 2);

lcd.print("Hello, world!");

}
```

La función `setup()` es una parte obligatoria de todo programa Arduino. Se ejecuta solo una vez después de reiniciar la placa Arduino. En esta función, primero se llama a `lcd.begin(16, 2);` para establecer el número de columnas y filas del LCD. En este ejemplo, se configura para 16 columnas y 2 filas.

Inmediatamente después, `lcd.print("Hello, world!");` muestra el texto "Hello, world!" en el LCD. Esto demuestra cómo imprimir una cadena en el LCD.

Función Loop

```cpp
void loop() {

lcd.setCursor(0, 1);

lcd.print(millis() / 1000);

}
```

La función `loop()` es otra parte fundamental del código Arduino. Se ejecuta indefinidamente después de reiniciar el dispositivo. En esta función, `lcd.setCursor(0, 1);` establece la posición del cursor al inicio de la segunda fila (ten en cuenta que la numeración de filas y columnas comienza desde 0).

Luego, `lcd.print(millis() / 1000);` calcula el número de segundos desde que el programa comenzó a ejecutarse y lo muestra en el LCD. Aquí, la función `millis()` devuelve el número de milisegundos desde que inició el programa, y dividirlo por 1000 lo convierte a segundos.

#### Resultado del Proyecto

Después de subir el código, el LCD 1602 mostrará dos filas de contenido: "Hello, world!" en la primera línea y el tiempo actual de operación (en segundos) de la placa de desarrollo Arduino en la segunda línea.

![P17](../media/P17.gif)

A través de este proyecto, aprendiste cómo usar el LCD 1602 mediante la placa de desarrollo UNO R3 （ch340）. Puedes modificar los códigos para probar funciones más complejas, como mostrar diferentes mensajes y agregar otros módulos como botones o sensores de temperatura.