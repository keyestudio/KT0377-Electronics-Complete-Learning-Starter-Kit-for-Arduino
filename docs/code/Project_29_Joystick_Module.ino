/ *

Набор для изучения электроники для Arduino

Проект 29

Модуль джойстика

Редактировал Keyes

* /

void loop() {

int xValue = analogRead(xPin); // Считать значение потенциометра по оси X

int yValue = analogRead(yPin); // Считать значение потенциометра по оси Y

int buttonState = digitalRead(buttonPin); // Считать состояние кнопки

Serial.print("X: ");

Serial.print(xValue);

Serial.print(" Y: ");

Serial.print(yValue);

Serial.print(" Button: ");

Serial.println(buttonState);

delay(100); // Задержка на 100 миллисекунд

}