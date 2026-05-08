# Proyecto 32: Servo Controlado por Movimiento


#### Descripción

En este proyecto, combinaremos el sensor de movimiento de 6 ejes MPU6050 con un motor servo SG90 para crear un sistema controlado por movimiento. Al inclinar el módulo MPU6050 a lo largo de su eje X, el Arduino leerá los datos de aceleración, los mapeará a un ángulo y ordenará al motor servo que gire en consecuencia. Este es el principio básico detrás de la estabilización de gimbals y brazos robóticos controlados por movimiento.

#### Hardware

1. Placa de desarrollo UNO R3 (ch340) x1  
2. Módulo MPU6050 x1  
3. Motor Servo SG90 x1  
4. Protoboard x1  
5. Cables jumper

#### Principio de Funcionamiento

El MPU6050 mide la aceleración de la gravedad. Cuando el módulo está perfectamente plano, los ejes X e Y leen 0g, y el eje Z lee 1g. Cuando inclinas el módulo, el vector de gravedad se distribuye entre los ejes. Al leer el valor bruto de aceleración del eje X, podemos determinar el ángulo de inclinación.

El Arduino lee este valor bruto del eje X (que típicamente varía entre -17000 y +17000 dependiendo de la inclinación) y utiliza la función `map()` para convertir este rango en un valor de ángulo entre 0 y 180 grados. Este valor de ángulo se envía luego al motor servo usando la librería `Servo`, haciendo que el brazo del motor imite la inclinación del sensor.

#### Diagrama de Conexiones

**MPU6050**:  
- VCC -> 5V  
- GND -> GND  
- SCL -> A5  
- SDA -> A4  

**Servo SG90**:  
- Cable Marrón/Negro -> GND  
- Cable Rojo -> 5V  
- Cable Naranja/Amarillo (Señal) -> Pin Digital 9  
![Img](../media/img-20260404102947.png)

#### Código de Ejemplo

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 32

Motion Controlled Servo

Edit By Keyes

*/

#include <Wire.h>
#include <Servo.h>

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ;

Servo myServo;  // create servo object to control a servo

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6, true);  // request a total of 6 registers
  
  AcX = Wire.read()<<8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY = Wire.read()<<8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read()<<8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  
  // Map the X-axis acceleration (-17000 to 17000) to Servo angle (0 to 180)
  // Note: You may need to adjust the -17000 and 17000 values based on your specific sensor's calibration
  int servoAngle = map(AcX, -17000, 17000, 0, 180);
  
  // Constrain the angle to prevent servo damage
  servoAngle = constrain(servoAngle, 0, 180);
  
  myServo.write(servoAngle);  // tell servo to go to position in variable 'servoAngle'
  
  Serial.print("AcX: ");
  Serial.print(AcX);
  Serial.print(" => Angle: ");
  Serial.println(servoAngle);
  
  delay(50);  // small delay for stability
}
```

#### Explicación del Código

**Mapeo de los Valores**:  
```cpp
int servoAngle = map(AcX, -17000, 17000, 0, 180);
```
La función `map()` toma la lectura bruta de aceleración del eje X (`AcX`) y la escala desde su rango original (-17000 a 17000) al rango objetivo para el motor servo (0 a 180 grados).

**Limitación del Ángulo**:  
```cpp
servoAngle = constrain(servoAngle, 0, 180);
```
La función `constrain()` asegura que, incluso si el sensor entrega un valor ligeramente fuera del rango esperado, el `servoAngle` nunca caerá por debajo de 0 ni excederá 180. Esto protege los engranajes físicos dentro del motor servo de daños.

#### Resultado del Proyecto

Después de subir el código, sostiene el módulo MPU6050 en tu mano. Al inclinar el módulo hacia la izquierda y derecha a lo largo de su eje X, el motor servo SG90 girará de forma sincronizada, reflejando el movimiento de tu mano. Puedes abrir el Monitor Serial para ver los valores brutos de aceleración y los ángulos calculados correspondientes.

![P32](../media/P32.gif)