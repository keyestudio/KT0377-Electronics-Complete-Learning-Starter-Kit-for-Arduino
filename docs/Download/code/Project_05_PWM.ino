/ *

Набор для изучения электроники для Arduino

Проект 5

ШИМ

Редактирование: Keyes

* /

void loop() {

analogWrite(ledPin, brightness); // Используйте analogWrite для управления яркостью светодиода

brightness = brightness + fadeAmount; // Регулировка яркости

if (brightness <= 0 || brightness >= 255) {

fadeAmount = -fadeAmount; // Изменение направления при достижении максимума/минимума

}

delay(30); // Задержка для контроля скорости изменения яркости

}