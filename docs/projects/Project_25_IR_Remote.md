# Proyecto 25: Control Remoto IR


![](../media/d6fa77cf7e7cdd4a4d1b90847748e062.png)

#### Descripción

El control IR es un equipo de control remoto inalámbrico para la transmisión de señales. Se utiliza ampliamente en televisores, aire acondicionado, audio y otros electrodomésticos. Mediante la transmisión de señales infrarrojas, controla el receptor para realizar operaciones correspondientes.

En este proyecto, realizamos la función de control remoto infrarrojo mediante programación Arduino en la placa de desarrollo UNO R3 （ch340）.

#### Hardware

1. Placa de desarrollo UNO R3 （ch340） x1

2. Control Remoto Infrarrojo x1
   
3. Receptor Infrarrojo x1
   
4. Condensador 100NF x1
   
5. Condensador 10μF x1
   
6. Protoboard x1
   
7. Cables jumper

#### Principio de Funcionamiento

**¿QUÉ ES EL INFRARROJO?**

La radiación infrarroja es una forma de luz similar a la luz que vemos a nuestro alrededor. La única diferencia entre la luz IR y la luz visible es la frecuencia y la longitud de onda. La radiación infrarroja está fuera del rango de la luz visible, por lo que los humanos no pueden verla:

![IMG_256](../media/ea07ec19ce6355e6140cd9fe06fe7f06.png)

Debido a que el IR es un tipo de luz, la comunicación IR requiere una línea de visión directa desde el receptor hasta el transmisor. No puede transmitirse a través de paredes u otros materiales como WiFi o Bluetooth.

**CÓMO FUNCIONAN LOS MANDOS Y RECEPTORES IR**

Un sistema típico de comunicación infrarroja requiere un transmisor IR y un receptor IR. El transmisor se parece a un LED estándar, excepto que produce luz en el espectro IR en lugar del espectro visible. Si miras el frente de un control remoto de TV, verás el LED transmisor IR:

![](../media/9230d535fe2cb9c3669d6169cd86a5d6.png)

El receptor IR es un fotodiodo y preamplificador que convierte la luz IR en una señal eléctrica. Los diodos receptores IR típicamente lucen así:

![](../media/be369f836361b40bde56165bd7e3a5ed.png)

**MODULACIÓN DE LA SEÑAL IR**

La luz IR es emitida por el sol, bombillas y cualquier otra cosa que produzca calor. Eso significa que hay mucho ruido de luz IR a nuestro alrededor. Para evitar que este ruido interfiera con la señal IR, se utiliza una técnica de modulación de señal.

En la modulación de señal IR, un codificador en el control remoto IR convierte una señal binaria en una señal eléctrica modulada. Esta señal eléctrica se envía al LED transmisor. El LED transmisor convierte la señal eléctrica modulada en una señal de luz IR modulada. El receptor IR luego desmodula la señal de luz IR y la convierte de nuevo a binario antes de pasar la información a un microcontrolador:

![IMG_261](../media/3da1969e509f53706643c77d0534eb73.png)

La señal IR modulada es una serie de pulsos de luz IR que se encienden y apagan a una alta frecuencia conocida como frecuencia portadora. La frecuencia portadora usada por la mayoría de los transmisores es 38 kHz, porque es rara en la naturaleza y así puede distinguirse del ruido ambiental. De esta manera, el receptor IR sabrá que la señal de 38 kHz fue enviada por el transmisor y no captada del entorno.

El diodo receptor detecta todas las frecuencias de luz IR, pero tiene un filtro pasa banda que solo deja pasar IR a 38 kHz. Luego amplifica la señal modulada con un preamplificador y la convierte en una señal binaria antes de enviarla a un microcontrolador.

**PROTOCOLOS DE TRANSMISIÓN IR**

El patrón en el que la señal IR modulada se convierte a binario está definido por un protocolo de transmisión. Hay muchos protocolos de transmisión IR. Sony, Matsushita, NEC y RC5 son algunos de los protocolos más comunes.

El protocolo NEC es también el tipo más común en proyectos Arduino, así que lo usaré como ejemplo para mostrar cómo el receptor convierte la señal IR modulada en una señal binaria.

El ‘1’ lógico comienza con un pulso ALTO de 562.5 µs de luz IR a 38 kHz seguido de un pulso BAJO de 1,687.5 µs. El ‘0’ lógico se transmite con un pulso ALTO de 562.5 µs seguido de un pulso BAJO de 562.5 µs:

![IMG_262](../media/6f932364f352ec325568616dce2bdf3a.png)

Así es como el protocolo NEC codifica y decodifica los datos binarios en una señal modulada. Otros protocolos solo difieren en la duración de los pulsos ALTO y BAJO individuales.

#### Especificaciones

Voltaje de operación: 2.5V a 5.5V

Frecuencia portadora (38kHz)

Corriente de operación: 5mA

Alto alcance y amplia área de cobertura.

Mejor inmunidad contra ruido HF y RF

Tiene preamplificador incorporado

Compatible con TTL y CMOS

#### Pinout

![](../media/da578c9eb96126e0c82fc40878a7038c.png)

VCC: 5V de la placa de desarrollo

GND: GND de la placa de desarrollo

OUT: pin digital de la placa de desarrollo

#### Diagrama de Conexiones

1.  Conectar VCC del componente IR Remote a 5V en la placa
2.  Conectar GND del componente IR Remote a GND en la placa
3.  Conectar OUT del componente IR Remote al pin digital D2 en la placa

4. Conectar los condensadores de 100NF y 10μF entre VCC y GND del receptor IR.

![Img](../media/img-20260403133400.png)




### Instalar Librería

Antes de comenzar a programar, necesitamos instalar primero el archivo de la librería IRremote.

**Navegar al Gestor de Librerías**: Haz clic en el menú “Herramientas”, luego selecciona “Gestionar librerías…”.

![](../media/7bb083e374003eb07f5eb6228618191d.png)

**Buscar Librerías**:

En la ventana del Gestor de Librerías que aparece, verás un cuadro de búsqueda. Ingresa el nombre de la librería "IRremote".

![](../media/a55cc2cf676c8b3bcba2b0a7865a3b4c.png)

**Seleccionar e Instalar Librerías**:

Abre la lista en el archivo de la librería IRremote, selecciona la versión 2.0.1, haz clic e instala.

![](../media/328abf7beaa3240aac6a38086017e520.png)

Aparecerá un botón “Instalar” en el lado derecho de la ventana. Haz clic en el botón “Instalar”.

![](../media/727511b4c03467700f65e4665518a234.png)

**Esperar la Instalación**: El IDE de Arduino descargará e instalará automáticamente la librería seleccionada. Una vez completada la instalación, el botón “Instalar” cambiará a “Instalado”, indicando una instalación exitosa.

#### Explicación del Código

Primero, se incluye la librería IRremote:

```cpp
#include <IRremote.h>
```

Esta línea de código importa la librería IRremote. La librería IRremote es una biblioteca para Arduino que permite que Arduino se comunique con dispositivos externos mediante señales infrarrojas. Esta librería soporta múltiples protocolos infrarrojos y puede decodificar señales de dispositivos comunes como controles remotos de TV y aire acondicionado.

Definir el pin receptor y objetos

A continuación, el código define el pin para recibir señales infrarrojas y los objetos necesarios:

```cpp

const int RECV_PIN = 2; // Pin receptor del control remoto IR

IRrecv irrecv(RECV_PIN); // crear objeto IRrecv

decode_results results; // Un objeto que almacena el resultado decodificado

```

Aquí, `RECV_PIN` define el número de pin en Arduino para recibir señales infrarrojas, que está configurado en el pin 2. El objeto `IRrecv` llamado `irrecv` se inicializa especificando el pin y se usa para configurar y leer señales infrarrojas. El objeto `decode_results` llamado `results` se usa para almacenar los datos de la señal infrarroja decodificada.

Inicialización y configuración

En la función `setup()`, se realiza una inicialización y configuración básica:

```cpp
void setup() {

Serial.begin(9600); // inicializar puerto serial

irrecv.enableIRIn(); // habilitar receptor IR

}
```

`Serial.begin(9600);` inicializa la comunicación serial con una tasa de baudios de 9600 para la salida y visualización de datos. `irrecv.enableIRIn();` inicia el receptor infrarrojo, habilitándolo para comenzar a recibir señales del control remoto infrarrojo.

Bucle principal

En la función `loop()`, el código procesa las señales infrarrojas recibidas:

```cpp
void loop() {

if (irrecv.decode(&results)) { // Si se recibe una señal infrarroja

Serial.println(results.value, HEX); // Imprime el código infrarrojo recibido

irrecv.resume(); // Recibe el siguiente valor

}

delay(100); // espera 100ms

}
```

Esta parte del código es el núcleo del programa, revisando continuamente si se ha recibido una señal infrarroja. `irrecv.decode(&results)` verifica si se ha recibido una señal y, si es así, la función devuelve `true` y almacena el resultado decodificado en el objeto `results`. Luego, `Serial.println(results.value, HEX);` muestra el código infrarrojo recibido en formato hexadecimal en el monitor serial para observación y depuración. `irrecv.resume();` prepara para recibir la siguiente señal infrarroja. `delay(100);` pausa 100 milisegundos después de cada iteración del bucle para evitar un procesamiento excesivamente frecuente.

#### Código de Ejemplo

```cpp

/*

Kit de inicio de aprendizaje de electrónica para Arduino

Proyecto 25

Control Remoto IR

Editado por Keyes

*/

#include <IRremote.h> // importar librería IRremote

const int RECV_PIN = 2; // Pin receptor del control remoto IR

IRrecv irrecv(RECV_PIN); // crear objeto IRrecv

decode_results results; // Un objeto que almacena el resultado decodificado

void setup() {

Serial.begin(9600); // inicializar puerto serial

irrecv.enableIRIn(); // habilitar receptor IR

}

void loop() {

if (irrecv.decode(&results)) { // Si se recibe una señal infrarroja

Serial.println(results.value, HEX); // Imprime el código infrarrojo recibido

irrecv.resume(); // Recibe el siguiente valor

}

delay(100); // espera 100ms

}
```

#### Resultado del Proyecto

Después de subir el código, abre el monitor serial y configura la tasa de baudios a 9600. Cuando presionas una tecla en el control remoto, el monitor serial muestra el código infrarrojo recibido. Cada tecla corresponde a un valor codificado único.

![](../media/a942cba72bb01f242b822e5fea479c08.png)

![P25](../media/P25.gif)