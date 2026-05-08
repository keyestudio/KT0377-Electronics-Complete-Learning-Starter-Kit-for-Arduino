/*

Набор для изучения электроники для Arduino

Проект 23

Драйвер мотора L293D

Редактировал Keyes

*/

// Определение пинов
const int enablePin = 10; // D10: управление скоростью мотора (PWM)
const int in1Pin = 11;    // D11: управление направлением мотора 1
const int in2Pin = 9;     // D9:  управление направлением мотора 2

void setup() {
  // Установка пинов управления в режим вывода
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  // 1. Полная скорость вперед, 2 секунды
  setMotor(255, false); 
  delay(2000);

  // 2. Остановка, 1 секунда
  setMotor(0, false);   
  delay(1000);

  // 3. Полная скорость назад, 2 секунды
  setMotor(255, true);  
  delay(2000);

  // 4. Остановка, 1 секунда
  setMotor(0, false);   
  delay(1000);
}

// Пользовательская функция управления мотором
// Параметр speed: скорость (0~255)
// Параметр reverse: направление (false — вперед, true — назад)
void setMotor(int speed, boolean reverse) {
  // Отправка PWM сигнала для установки скорости
  analogWrite(enablePin, speed);
  
  // Использование инверсии логики для управления направлением, чтобы два пина всегда имели противоположные уровни
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}