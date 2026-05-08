# Проект 31: Модуль MPU6050


#### Описание

MPU6050 — это мощное 6-осевое устройство отслеживания движения, которое объединяет 3-осевой гироскоп и 3-осевой акселерометр на одном кремниевом кристалле. Он широко используется в дронах, балансировочных роботах и устройствах с управлением движением. В этом проекте мы научимся считывать данные ускорения и вращения с модуля MPU6050 с помощью протокола связи I2C.

#### Аппаратное обеспечение

1. Плата разработки UNO R3 (ch340) x1  
2. Модуль MPU6050 x1  
3. Макетная плата x1  
4. Соединительные провода

#### Принцип работы

MPU6050 состоит из двух основных датчиков:  
- **Акселерометр**: Измеряет силы ускорения, действующие на датчик по осям X, Y и Z. Это можно использовать для определения угла наклона датчика относительно земного притяжения.  
- **Гироскоп**: Измеряет скорость вращения вокруг осей X, Y и Z. Это помогает отслеживать ориентацию и вращательное движение.

Модуль взаимодействует с Arduino через протокол I2C (Inter-Integrated Circuit), который требует всего две линии данных: SDA (Serial Data) и SCL (Serial Clock). Arduino запрашивает данные из внутренних регистров MPU6050, а модуль отправляет обратно необработанные значения датчиков.

#### Схема подключения

1. Подключите VCC MPU6050 к 5V на плате.  
2. Подключите GND MPU6050 к GND на плате.  
3. Подключите SCL MPU6050 к A5 (или пину SCL) на плате.  
4. Подключите SDA MPU6050 к A4 (или пину SDA) на плате.  
![Img](../media/img-20260404102454.png)

#### Пример кода

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 31

MPU6050 Module

Edit By Keyes

*/

#include <Wire.h>

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  // equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  
  delay(500);
}
```

#### Объяснение кода

**Инициализация I2C**:  
```cpp
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B);  // PWR_MGMT_1 register
Wire.write(0);     // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
```
Библиотека `Wire` используется для связи по I2C. Сначала мы «пробуждаем» MPU6050, записывая `0` в его регистр управления питанием (`0x6B`).

**Чтение данных**:  
```cpp
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
```
Мы сообщаем MPU6050, что хотим начать чтение с регистра `0x3B` (который содержит старший байт ускорения по оси X). Затем запрашиваем всего 14 байт данных, что покрывает 3-осевое ускорение, температуру и 3-осевой гироскоп (каждое значение занимает 2 байта).

**Объединение байт**:  
```cpp
AcX=Wire.read()<<8|Wire.read();
```
Поскольку каждое значение датчика занимает 16 бит (2 байта), мы читаем старший байт, сдвигаем его влево на 8 бит (`<<8`) и используем побитовое ИЛИ (`|`) с младшим байтом, чтобы объединить их в одно 16-битное целое число.

#### Результат проекта

После загрузки кода откройте монитор порта и установите скорость передачи 9600 бод. Вы увидите непрерывный поток данных, показывающий значения ускорения (AcX, AcY, AcZ), температуры (Tmp) и гироскопа (GyX, GyY, GyZ). Попробуйте наклонять и вращать модуль MPU6050 и наблюдайте, как значения меняются в реальном времени!

![P31](../media/P31.gif)