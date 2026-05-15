# Проект 32: Серво с управлением движением


#### Описание

В этом проекте мы совместим 6-осевой датчик движения MPU6050 с сервомотором SG90, чтобы создать систему с управлением движением. Наклоняя модуль MPU6050 вдоль оси X, Arduino будет считывать данные ускорения, преобразовывать их в угол и командовать сервомотору вращаться соответствующим образом. Это основной принцип работы стабилизации подвеса и роботизированных рук с управлением движением.

#### Аппаратное обеспечение

1. Плата разработки UNO R3 (ch340) x1  
2. Модуль MPU6050 x1  
3. Серво мотор SG90 x1  
4. Макетная плата x1  
5. Соединительные провода

#### Принцип работы

MPU6050 измеряет ускорение силы тяжести. Когда модуль расположен идеально горизонтально, оси X и Y показывают 0g, а ось Z — 1g. При наклоне модуля вектор гравитации распределяется по осям. Считывая необработанное значение ускорения по оси X, можно определить угол наклона.

Arduino считывает это необработанное значение по оси X (которое обычно варьируется от -17000 до +17000 в зависимости от наклона) и с помощью функции `map()` преобразует этот диапазон в значение угла от 0 до 180 градусов. Это значение затем передается сервомотору с помощью библиотеки `Servo`, заставляя рычаг мотора повторять наклон датчика.

#### Схема подключения

**MPU6050**:  
- VCC -> 5V  
- GND -> GND  
- SCL -> A5  
- SDA -> A4  

**Серво SG90**:  
- Коричневый/черный провод -> GND  
- Красный провод -> 5V  
- Оранжевый/желтый провод (сигнал) -> Цифровой пин 9  
![Img](../media/img-20260404102947.png)

#### Пример кода

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

#### Объяснение кода

**Преобразование значений**:  
```cpp
int servoAngle = map(AcX, -17000, 17000, 0, 180);
```
Функция `map()` принимает необработанное значение ускорения по оси X (`AcX`) и масштабирует его из исходного диапазона (-17000 до 17000) в целевой диапазон для сервомотора (0 до 180 градусов).

**Ограничение угла**:  
```cpp
servoAngle = constrain(servoAngle, 0, 180);
```
Функция `constrain()` гарантирует, что даже если датчик выдаст значение немного за пределами ожидаемого диапазона, значение `servoAngle` никогда не опустится ниже 0 или не превысит 180. Это защищает механические шестерни сервомотора от повреждений.

#### Результат проекта

После загрузки кода возьмите модуль MPU6050 в руку. При наклоне модуля влево и вправо вдоль оси X сервомотор SG90 будет вращаться синхронно, повторяя движение вашей руки. Вы можете открыть монитор порта, чтобы видеть необработанные значения ускорения и соответствующие им вычисленные углы.

![P32](../media/P32.gif)