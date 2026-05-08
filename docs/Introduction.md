# Kit Completo de Electrónica para Aprendizaje y Inicio de Robots para Arduino UNO R3

![Img](media/img-20260508114126.jpeg)

**Antes de comenzar los proyectos, por favor asegúrate de haber instalado el IDE de Arduino y las librerías necesarias.**

## 1. Introducción

El Kit Completo de Electrónica para Aprendizaje es un kit de desarrollo compatible con Arduino, completo y versátil, diseñado para principiantes, estudiantes y entusiastas de la electrónica. Este kit contiene una gran variedad de sensores, módulos y componentes para ayudarte a comenzar rápidamente y practicar una multitud de proyectos básicos e intermedios de electrónica. Ya sea que estés aprendiendo programación, construyendo prototipos de hogares inteligentes o explorando robótica, este kit proporciona todas las herramientas esenciales que necesitas.

---

## 2. Características

1. **Facilidad de uso**: Arduino es popular por su simplicidad y facilidad de uso, permitiendo a los usuarios comenzar sin necesidad de conocimientos avanzados en programación o electrónica.  
2. **Abundantes módulos de componentes**: El kit incluye varios módulos como LEDs, sensores, pantallas, motores y más, permitiendo a los usuarios realizar diversos proyectos.  
3. **Tutoriales detallados**: Ofrece tutoriales detallados para 32 proyectos, cubriendo principios de funcionamiento, código y diagramas de conexión para ayudar a los usuarios a dominar gradualmente los conceptos básicos.  
4. **Aplicaciones versátiles**: El kit soporta la creación de una amplia gama de proyectos, desde monitoreo básico de temperatura hasta sistemas complejos de hogar inteligente y controles robóticos, ampliando considerablemente su aplicabilidad.  
5. **Expansibilidad**: Más allá de los proyectos básicos en los tutoriales, los usuarios pueden explorar y desarrollar aplicaciones más avanzadas basadas en intereses personales. Esta flexibilidad mejora significativamente el valor práctico del kit.

---

## 3. Lista de Componentes

![](media/kit_cover.png)

| Componente | Cantidad | Componente | Cantidad |
|-----------|----------|-----------|----------|
| Placa Arduino UNO R3 | 1 | Módulo LCD 1602 | 1 |
| Shield de Expansión para Protoboard | 1 | Display de Segmentos LED de 4 dígitos | 1 |
| Protoboard de 830 orificios | 1 | Display de Segmentos LED de 1 dígito | 1 |
| Motor Paso a Paso (5V) | 1 | Sensor Ultrasónico HC-SR04 | 1 |
| Driver para Motor Paso a Paso ULN2003 | 1 | Motor Servo SG90 | 1 |
| Motor DC 130 | 1 | Módulo Joystick | 1 |
| Control Remoto IR | 1 | Sensor Receptor IR | 1 |
| Módulo Relé 5V | 1 | Registro de Desplazamiento 74HC595 | 1 |
| Zumbador Activo | 1 | Zumbador Pasivo | 1 |
| Interruptor de Botón | 5 | Módulo MPU6050 | 1 |
| Potenciómetro 10K | 2 | Termistor NTC-MF52AT 10K | 1 |
| Fotoresistor | 2 | Matriz de Puntos LED 8x8 | 1 |
| LED RGB | 1 | MAX7219CNG | 1 |
| LED - Rojo | 5 | LED - Verde | 5 |
| LED - Azul | 5 | LED - Amarillo | 5 |
| LED - Blanco | 5 | Driver de Motor L293D | 1 |
| Resistencia (220Ω) | 10 | Resistencia (1KΩ) | 10 |
| Resistencia (10KΩ) | 10 | Resistencia (100KΩ) | 10 |
| Resistencia (330Ω) | 10 | Resistencia (1MΩ) | 10 |
| Resistencia (10Ω) | 10 | Resistencia (100Ω) | 10 |
| Resistencia (2KΩ) | 10 | Conector para Batería 9V | 1 |
| Cable USB | 1 | Adaptador de Corriente 9V 1A | 1 |
| Cables Jumper (M-M) | 65 | Cables Dupont (F-M) | 10 |
| Transistor BC547 | 5 | Transistor BC557 | 5 |
| Transistor 2N2222 | 5 | Diodo 1N4007 | 5 |
| Condensador 10uF 50V | 2 | Condensador 100uF 50V | 2 |
| Condensador Cerámico 104PF | 5 | Condensador Cerámico 22PF | 5 |
| Header de Pines (24 pines) | 1 | Soporte para Ultrasónico | 1 |

---

## 4. Comenzando con Arduino

**¿QUÉ ES ARDUINO?**

Arduino es una plataforma electrónica de código abierto basada en hardware y software fáciles de usar. Está destinada a cualquier persona que realice proyectos interactivos.

**SOFTWARE DE ARDUINO**

Puedes indicarle a tu Arduino qué hacer escribiendo código en el lenguaje de programación Arduino y utilizando el entorno de desarrollo Arduino.

### 1. Descargar Arduino IDE

#### A. Sistema Windows

Puedes descargar Arduino IDE desde el sitio web oficial: <https://www.arduino.cc/>

Ingresa al enlace y haz clic en **SOFTWARE**:

![IMG_256](media/6014f55b686eaeda41962b0ad77736a3.png)

Hay varias versiones del IDE para Arduino. Solo descarga una versión compatible con tu sistema.

![IMG_257](media/24c561930b3186ad00a9ba22353fe03d.png)

Aquí te mostraremos cómo descargar e instalar la versión de Arduino IDE para Windows.

Hay dos versiones del IDE para el sistema WINDOWS. Puedes elegir entre el instalador (.exe) y el archivo Zip. Para el instalador, se puede descargar directamente, sin necesidad de instalarlo manualmente, mientras que para el paquete Zip, deberás instalar el controlador manualmente.

![IMG_258](media/8ec65288928b34f5bc469c6006490b64.png)

Solo necesitas hacer clic en **JUST DOWNLOAD**.

#### B. Sistema Mac

Las versiones de Arduino IDE varían según el sistema operativo.

Para saber cómo descargar Arduino IDE en Mac, por favor consulta la sección de Windows:

![IMG_259](media/5d7e2c9e5c669f9c6cdc6d80a033062f.png)

Después de descargarlo, haz doble clic para abrirlo y sigue las instrucciones de instalación.

#### C. Pasos detallados de instalación:

1. Guarda el archivo .exe descargado desde la página del software en tu disco duro y simplemente ejecuta el archivo.

![IMG_260](media/94d0d4f51a6ace50b21956fe3343c3c8.png)

2. Lee el Acuerdo de Licencia y acéptalo.

![IMG_261](media/4549ac3c1bf357812bf1b7f1e5c957b0.png)

3. Elige las opciones de instalación.

![IMG_262](media/b79aac95963c924dad31312bd29d0153.png)

4. Elige la ubicación de instalación.

![IMG_263](media/cfa42c06a2d876d92289d1147b60e6cc.png)

5. Haz clic en finalizar y ejecuta Arduino IDE.

![IMG_264](media/697ea012cd650c065e63f2b4616dcdc0.png)

### 2. Instalar el controlador

Necesitamos un controlador para arrancar nuestra placa de desarrollo. De lo contrario, el puerto COM conectado a la computadora no será detectado.

#### Instalar el controlador CH340 en sistema Windows

Descarga: <https://fs.keyestudio.com/CH340-WINDOWS>

Windows 10 (y sistemas posteriores) cuenta con sus propios controladores, por lo que no es necesario instalar controladores adicionales.

Conecta la placa de control a tu computadora.

Haz clic en Computadora – Propiedades – Administrador de dispositivos, como se muestra a continuación. Esto indica una conexión exitosa, por lo que no se requiere la instalación del controlador.

![IMG_256](media/7cc41c72ee4461bda82ccc4d0dba89bb.png)

Si ocurre la siguiente situación, necesitarás instalar el controlador manualmente.

![IMG_257](media/04ed97b4a54e1c4299f6eb8d373ea42f.png)

Haz clic en ![IMG_258](media/896228c33e54210b9384d463ad1b6625.png) para seleccionar "Actualizar controlador". Entonces comenzará la instalación del controlador.

![IMG_259](media/146b192c7d1474664008d444321a248d.png)

Pulsa "Buscar controladores en mi equipo".

![IMG_260](media/8e8ffe57882a82783826d01114ed6db0.png)

Busca el archivo **usb_ch341_3.1.2009.06** o **cp210x** que descargaste, y haz clic en "Siguiente".

![IMG_261](media/1ba1b4ecfe4ea3ead3d9d8f0e2d5a0f4.png)

Después de terminar la instalación, haz clic en "Cerrar" y aparecerá el número del puerto serial.

![IMG_262](media/776fa8f2bba399b2668f1baa0b6d3b5f.png)

¡El controlador se instaló correctamente!

Haz clic en Computadora – Propiedades – Administrador de dispositivos para verificar:

![IMG_263](media/7cc41c72ee4461bda82ccc4d0dba89bb.png)

#### Instalar el controlador CH340 en sistema MAC

**Paso 1**: Descarga el controlador desde el sitio web y extrae el archivo al directorio local de instalación.

<https://fs.keyestudio.com/CH340-MAC>

![IMG_256](media/7dfcb6e458f17b0e71f9025fae67194d.png)

**Paso 2**: Para detalles sobre cómo instalar el controlador en formato pkg por defecto, consulta el Paso 3. Si OS X 11.0 o posterior no soporta Rosetta, consulta el Paso 4 para instalar el controlador dmg.

Antes de la instalación, dirígete a "Preferencias del Sistema" -> "Seguridad y privacidad" -> página "General", debajo del título "Permitir apps descargadas de:" elige la opción 2 -> "App Store y desarrolladores identificados", entonces el controlador funcionará normalmente.

![IMG_257](media/2280ddabd30ae756e281ce22bc351117.png)

**Paso 3**: Para instalar el controlador en formato pkg, toca el archivo del controlador → Continuar → Instalar.

![IMG_258](media/f1bb8697ef7c872dc3ab8a218a751f01.png)

![IMG_259](media/061557391b0bd7ad8207204d1a4d8882.png)

Luego la instalación será exitosa.

![IMG_260](media/60bb24ba4d2c3cebd48448bdc78db7e1.png)

![IMG_261](media/4978c48ad8a09d8c0385790477852249.png)

Para instalar el controlador en formato pkg en OS X 11.0 y posteriores: Abre "LaunchPad" → "CH34xVCPDriver" → Instalar.

![IMG_262](media/3c06bb749fb85ba0c63615ca28a6caa2.png)

Al usar OS X 10.9 a OS X 10.15, haz clic en "Reiniciar" para reiniciar tu computadora, y realiza los siguientes pasos después del reinicio.

![](media/3fd75f71c0d4b5210034d7deac4aab23.png)

**Paso 4**: Para instalar el controlador dmg, toca el archivo dmg y arrastra "CH34xVCPDriver" para ingresar a la carpeta de aplicaciones del sistema operativo.

![](media/0acb0422b5dd20872534aca717c03df1.png)

Luego abre "LaunchPad" → "CH34xVCPDriver" → Instalar.

![](media/51d3db2d3cda79e414da48bc34b8e3d4.png)

Luego la instalación será exitosa.

![](media/7e52a1fe7974d968a26dd286455c3dd8.png)

Al insertar la placa de control CH340 en el puerto USB, abre Informe del sistema -> Hardware -> USB. A la derecha está el Árbol de dispositivos USB. Si el dispositivo USB funciona correctamente, encontrarás un dispositivo cuyo "Vendor ID" es [0x1a86].

![IMG_267](media/dc4720b8debe1b05d3ab010b68bed7a8.png)

Abre el programa "Terminal" en la carpeta Aplicaciones-Utilidades y escribe el comando "ls /dev/tty\*".

![IMG_268](media/e2a93eb1063946fd62ae1ef7319882a6.png)

Deberías ver el "tty.wchusbserialx" donde "x" es el número asignado al dispositivo similar a la asignación del puerto COM en Windows.

### 3. Configuración del Arduino IDE

Haz clic en el ícono ![IMG_274](media/291ed864a358d3c8bbcb44bb2a20e08b.png) para abrir Arduino IDE.

![](media/7aed791ac34372c448faec41fb5b3224.png)

1. "Archivo": Incluye Nuevo boceto, Abrir…, Cuaderno de bocetos, Ejemplos, Cerrar, Guardar (Guardar como…), Preferencias, Avanzado…, etc.

2. "Editar": Incluye Copiar, Pegar, Formato automático, Aumentar/Disminuir tamaño de fuente, etc. Comúnmente, puedes usar atajos para realizar estas operaciones.

3. "Boceto": Incluye Verificar/Compilar, Subir, Incluir biblioteca, etc.

4. "Herramientas": Incluye Placa y Puerto, que son dos de las funciones más importantes.

5. "Ayuda": Incluye Buscar actualizaciones así como algunas referencias oficiales de datos.

6. "Gráfica serial": Para mostrar los datos del puerto serial en forma de gráfico de líneas.

7. "Monitor serial": Para imprimir los datos del puerto serial.

8. Verificar código.

9. Verificar y subir código.

10. "Cuaderno de bocetos": Para crear un nuevo boceto, o iniciar sesión en Arduino Cloud para sincronizar y editar tus bocetos en la nube.

11. "Gestor de placas": Para instalar o eliminar placas de desarrollo.

12. "Gestor de bibliotecas": Para instalar o eliminar bibliotecas.

13. "Depurar": Para monitorear código y depurar puntos de interrupción.

14. Buscar.

15. Área de edición de bocetos.

16. Salida del IDE: Para reportar errores o carga exitosa, y para mostrar datos del monitor serial.

### 4. Subir código vía Arduino IDE

#### Para Windows

Subir código: Aquí se proporciona un código de ejemplo: imprimirá "Hello Keyestudio!" cada segundo.

Copia y pega el siguiente código en Arduino IDE:

```cpp
/*

keyestudio

Print "Hello Keyestudio!"

http://www.keyestudio.com

*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Set the serial port baud rate to 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Keyestudio!"); //Serial port printing
  delay(1000); //Delay of 1 second
}
```

![IMG_256](media/e95ea5b14321ab7257f9eaa38fae9a47.png)

Haz clic en "Herramientas" ——> "Placa" ——> Arduino AVR Boards, y aquí elegimos Arduino Uno como nuestra placa de desarrollo.

![IMG_257](media/7267fbefcfc10995f8e85bc26e54b49f.png)

Elige el puerto COM correcto.

Si hay muchos puertos y no sabes cuál es el correcto, puedes desconectar la placa para verificar cuál desaparece. Si no hay puerto COM, por favor verifica si el controlador está instalado.

![IMG_258](media/b03bcce79bae9d13d76a39e66f492838.jpeg)

En nuestra demostración, el puerto es COM3, así que hacemos clic en "Herramientas" para elegir "COM3" en "Puerto".

![IMG_259](media/b7a5fd0cde765bcbabcea31d055f0f73.png)

Si tu placa está conectada correctamente, aparecerá en la interfaz.

![IMG_260](media/d7fef58fae7f6d8f515f6476d5012c2a.png)

Haz clic en ![IMG_261](media/44a062aa272e21abb8308ad9bc3a1167.png) para compilar el código. Si tiene éxito, aparecerán las dos siguientes:

![IMG_262](media/fcf249833d7630efccf8e5bb9c2eade0.png)

Haz clic en ![IMG_263](media/84d060e66fbd48b08d74dc6a84c1785e.png) y configura la tasa de baudios a 9600, ¡y se imprimirá "Hello Keyestudio!"!

![IMG_264](media/c8e46fb53356400412788c518d5ae7d0.png)

1. "Alternar autodesplazamiento": Para configurar si seguir la impresión.

2. "Alternar marca de tiempo": Para configurar si mostrar la hora de impresión.

3. "Borrar salida": Para limpiar los datos de salida.

4. Entrada serial.

5. Formato de envío del puerto serial.

6. Tasa de baudios: Para configurar la tasa de baudios.

7. Caja de impresión.

¡Esto es el final de cómo subir código!

Ahora por favor importa las bibliotecas para el IDE, de lo contrario ocurrirá un error.

#### Para Mac

Subir código: Aquí se proporciona un código de ejemplo: imprimirá "Hello Keyestudio!" cada segundo.

Copia y pega el siguiente código en Arduino IDE:

```cpp
/*

keyestudio

Print "Hello Keyestudio!"

http://www.keyestudio.com

*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Set the serial port baud rate to 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Keyestudio!"); //Serial port printing
  delay(1000); //Delay of 1 second
}
```

![IMG_256](media/e95ea5b14321ab7257f9eaa38fae9a47.png)

Haz clic en "Herramientas" ——> "Placa" ——> Arduino AVR Boards, y aquí elegimos Arduino Uno como nuestra placa de desarrollo.

![IMG_257](media/f5b158d75c793076019c813d3ec2f8c1.png)

Elige el puerto COM correcto.

Si hay muchos puertos y no sabes cuál es el correcto, puedes desconectar la placa para verificar cuál desaparece. Si no hay puerto COM, por favor verifica si el controlador está instalado.

En "Herramientas", haz clic en "Puerto" para seleccionar "/dev/cu.usbderial-0001".

![IMG_258](media/e240db6aa07e8a7b90a0f255f9a018fb.png)

Si tu placa está conectada correctamente, aparecerá en la interfaz.

![IMG_259](media/5011e22deb0619b8fdcb418f11a2a6c5.png)

Haz clic en ![IMG_260](media/44a062aa272e21abb8308ad9bc3a1167.png) para compilar el código. Si tiene éxito, aparecerán las dos siguientes:

![IMG_261](media/8cf00ca48d5a99db25842c6e0d924744.png)

Haz clic en ![IMG_262](media/84d060e66fbd48b08d74dc6a84c1785e.png) y configura la tasa de baudios a 9600, ¡y se imprimirá "Hello Keyestudio!"!

![IMG_263](media/322f2c253c27b45bb00c348b8fde61bf.png)

1. "Alternar autodesplazamiento": Para configurar si seguir la impresión.

2. "Alternar marca de tiempo": Para configurar si mostrar la hora de impresión.

3. "Borrar salida": Para limpiar los datos de salida.

4. Entrada serial.

5. Formato de envío del puerto serial.

6. Tasa de baudios: Para configurar la tasa de baudios.

7. Caja de impresión.

¡Esto es el final de cómo subir código!

Ahora por favor importa las bibliotecas para el IDE, de lo contrario ocurrirá un error.
