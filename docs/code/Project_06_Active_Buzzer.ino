/*

Набор для изучения электроники для Arduino

Проект 6

Активный зуммер

Редактировано Keyes

*/

void loop() {

// Включить звук зуммера

digitalWrite(BUZZER_PIN, HIGH);

delay(1000); // Звук в течение 1 секунды

// Остановить звук

digitalWrite(BUZZER_PIN, LOW);

delay(1000); // Пауза 1 секунда

}