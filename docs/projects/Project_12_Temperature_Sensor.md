# Proyecto 12: Sensor de Temperatura

#### Descripción

El Termistor (NTC) es un sensor de temperatura ampliamente utilizado cuyo valor de resistencia disminuye a medida que la temperatura aumenta. Usando un circuito divisor de voltaje con una resistencia conocida, podemos medir el cambio de voltaje y calcular la temperatura usando la ecuación de Steinhart-Hart.

Este proyecto tiene como objetivo crear un sistema de monitoreo de temperatura usando la placa de desarrollo UNO R3 （ch340） y un Termistor NTC-MF52AT 10K.

#### Hardware

1. Placa de desarrollo UNO R3 （ch340） x1  
2. Termistor NTC-MF52AT 10K x1  
3. Resistencia de 10K x1  
4. Protoboard x1  
5. Cables jumper

#### Principio de Funcionamiento

Un termistor de coeficiente de temperatura negativo (NTC) es una resistencia cuya resistencia disminuye a medida que la temperatura aumenta. Para medir este cambio con un Arduino, usamos un circuito divisor de voltaje. Conectamos el termistor NTC en serie con una resistencia fija de 10K.

El pin analógico del Arduino lee el voltaje en la unión entre el termistor y la resistencia de 10K. A medida que la temperatura cambia, la resistencia del termistor cambia, lo que a su vez cambia el voltaje leído por el pin analógico.

Para convertir esta lectura de voltaje en una temperatura en grados Celsius, usamos la **ecuación de Steinhart-Hart**, que modela la resistencia de un semiconductor a diferentes temperaturas.

#### Diagrama de Conexiones

1. Conectar una pata del Termistor a 5V.  
2. Conectar la otra pata del Termistor al Pin Analógico A0.  
3. Conectar una resistencia de 10K desde el Pin Analógico A0 a GND.  
![Img](../media/img-20260401184903.png)

#### Código de Ejemplo

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 12

Temperature Sensor

Edit By Keyes

*/

int ThermistorPin = A0;
int Vo;
float R1 = 10000; // Fixed resistor value 10K
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; // Steinhart-Hart coefficients

void setup() {
  Serial.begin(9600);
}

void loop() {
  Vo = analogRead(ThermistorPin);
  
  // Calculate resistance of the thermistor
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  
  // Calculate temperature using Steinhart-Hart equation
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15; // Convert Kelvin to Celsius
  
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 
  
  delay(1000);
}
```

#### Explicación del Código

**Cálculo del Divisor de Voltaje**:  
```cpp
R2 = R1 * (1023.0 / (float)Vo - 1.0);
```
Esta fórmula calcula la resistencia actual del termistor NTC basada en la lectura analógica (0-1023).

**Ecuación de Steinhart-Hart**:  
```cpp
logR2 = log(R2);
T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
T = T - 273.15;
```
Estas líneas aplican la ecuación de Steinhart-Hart para convertir la resistencia calculada en temperatura en Kelvin, y luego restan 273.15 para convertirla a Celsius.

#### Resultado del Proyecto

Después de cargar el código en la placa de desarrollo, abre el monitor serial del IDE de Arduino y configura la velocidad en baudios a 9600. Verás la temperatura ambiente actual impresa cada segundo en grados Celsius. ¡Intenta pellizcar el termistor con tus dedos para ver cómo sube la temperatura!

![P12](../media/P12.gif)