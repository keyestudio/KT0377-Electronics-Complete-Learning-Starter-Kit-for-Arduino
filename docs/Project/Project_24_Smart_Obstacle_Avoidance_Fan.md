# Проект 24: Умный вентилятор с обходом препятствий

## Описание
В этом проекте мы создадим «умный вентилятор», который реагирует на окружающую среду. Мы объединим **ультразвуковой датчик HC-SR04** с двигателем постоянного тока, управляемым микросхемой L293D. Ультразвуковой датчик выступает в роли датчика приближения: когда объект (например, ваша рука) слишком близко подходит к лопастям вентилятора, мотор автоматически останавливается, чтобы предотвратить травмы; когда препятствие убирается, вентилятор автоматически возобновляет вращение.

## Аппаратное обеспечение
1. Плата разработки UNO R3 (CH340) × 1  
2. **Ультразвуковой датчик HC-SR04 × 1**  
3. Микросхема драйвера мотора L293D × 1  
4. Двигатель постоянного тока 130 × 1  
5. Батарея 9В и держатель для батареи × 1 (для независимого питания мотора)  
6. Макетная плата × 1  
7. Соединительные провода × несколько  

## Принцип работы
1. **Измерение расстояния ультразвуком:** Датчик HC-SR04 излучает высокочастотные звуковые волны и измеряет время, за которое эхо возвращается обратно. Arduino рассчитывает физическое расстояние до объекта на основе времени прохождения звуковой волны туда и обратно.  
2. **Логика управления:** В коде мы задаём порог «безопасного расстояния» (например, 15 см). Arduino постоянно проверяет расстояние, измеренное ультразвуковым датчиком:  
   * Если расстояние **больше** 15 см: Arduino через функцию `setMotor` отправляет команды L293D для работы мотора на полной скорости.  
   * Если расстояние **меньше или равно** 15 см: Arduino сразу отправляет команду остановки L293D, и мотор мгновенно тормозит.  

## Схема подключения

**1. Контакты ультразвукового датчика HC-SR04**  
* `VCC` ➔ Подключить к 5V Arduino  
* `GND` ➔ Подключить к GND Arduino  
* `Trig (Trigger)` ➔ Подключить к **Arduino D8**  
* `Echo (Echo)` ➔ Подключить к **Arduino D7**  

**2. Контакты драйвера мотора L293D (следуя предыдущему безопасному способу подключения)**  
* `Pin 1 (Enable 1)` ➔ Подключить к **Arduino D10** *(для управления скоростью / запуска и остановки)*  
* `Pin 2 (Input 1)` ➔ Подключить к **Arduino D11** *(управление направлением 1)*  
* `Pin 7 (Input 2)` ➔ Подключить к **Arduino D9** *(управление направлением 2)*  
* `Pin 3 (Output 1)` ➔ Подключить к одному контакту мотора  
* `Pin 6 (Output 2)` ➔ Подключить к другому контакту мотора  
* `Pin 16 (VCC1)` ➔ Подключить к 5V Arduino *(питание логики)*  
* `Pin 8 (VCC2)` ➔ Подключить к положительному контакту батареи 9В *(независимое питание мотора)*  
* `Pin 4, 5 (GND)` ➔ Подключить к общему GND макетной платы (включая GND Arduino и отрицательный контакт батареи)  

![Img](../media/img-20260403133003.png)

## Пример кода

```cpp
/*

Electronics Learning Starter Kit for Arduino

Project 24

Smart Obstacle Avoidance Fan

Edit By Keyes

*/

// --- 1. Ultrasonic sensor pin definitions ---
const int trigPin = 8;  // Trigger pin
const int echoPin = 7;  // Echo pin

// --- 2. L293D motor driver pin definitions ---
const int enablePin = 10; // D10: motor speed control (PWM)
const int in1Pin = 11;    // D11: motor direction control 1
const int in2Pin = 9;     // D9:  motor direction control 2

// --- 3. Parameter settings ---
const int safeDistance = 15; // Safe distance threshold set to 15 cm

void setup() {
  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize motor control pins
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Start serial communication to monitor distance data on PC
  Serial.begin(9600);
}

void loop() {
  // ================= Step 1: Emit sound wave and measure distance =================
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Emit 10 microseconds high-frequency sound pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of echo pin being HIGH (microseconds)
  long duration = pulseIn(echoPin, HIGH);
  // Calculate distance (speed of sound approx. 0.034 cm/us, divide by 2 for round trip)
  int distance = duration * 0.034 / 2;
  
  // Print current distance to serial monitor
  Serial.print("Current distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // ================= Step 2: Control motor start/stop based on distance =================
  // Add distance > 0 to avoid misjudgment when sensor occasionally returns 0
  if (distance > 0 && distance <= safeDistance) {
    // Obstacle too close! Set speed to 0 and stop motor.
    setMotor(0, false);
    Serial.println(">>> Status: Danger! Braking <<<");
  } else {
    // Safe ahead! Set speed to 255, full speed forward.
    setMotor(255, false);
    Serial.println("Status: Running normally...");
  }
  
  // Short delay to avoid interference from too frequent measurements
  delay(100); 
}

// ================= Custom motor control function =================
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
```

## Объяснение кода

**1. Измерение расстояния (`pulseIn` функция):**  
```cpp
long duration = pulseIn(echoPin, HIGH);
int distance = duration * 0.034 / 2;
```
Функция `pulseIn()` измеряет, как долго пин Echo остаётся в состоянии HIGH. Мы умножаем это время на скорость звука (0.034 см за микросекунду), затем делим на 2, так как звук проходит путь туда и обратно, чтобы получить точное расстояние в сантиметрах в одну сторону.

**2. Логика безопасного обхода препятствий:**  
```cpp
if (distance > 0 && distance <= safeDistance)
```
Мы проверяем, меньше ли или равно расстояние порогу `safeDistance` (15 см). Условие `distance > 0` добавлено, потому что ультразвуковой датчик иногда возвращает 0, если объект вне зоны действия или эхо не получено. Без этой проверки вентилятор мог бы ошибочно остановиться при значении 0.

**3. Использование безопасного управления мотором:**  
Код продолжает использовать ранее написанную функцию `setMotor()`. Это гарантирует, что независимо от изменений в основной программе, базовая логика взаимного исключения, управляющая направлением (`!reverse`), защищает микросхему от коротких замыканий.

## Результат проекта
После загрузки кода в Arduino и подключения батареи 9В:  
1. Двигатель постоянного тока сразу начнёт вращаться.  
2. Поднесите руку или книгу примерно на 10–15 см перед ультразвуковым датчиком — мотор **немедленно остановится**.  
3. Отодвиньте руку — мотор **автоматически возобновит вращение**.  
4. Если открыть **Серийный монитор** в Arduino IDE (скорость передачи 9600 бод), можно увидеть в реальном времени измеренное расстояние и состояние работы вентилятора.

![P24](../media/P24.gif)