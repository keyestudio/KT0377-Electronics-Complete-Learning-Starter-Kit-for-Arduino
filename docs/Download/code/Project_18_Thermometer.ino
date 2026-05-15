/ *

Набор для изучения электроники для Arduino

Проект 18

Термометр

Редактирование: Keyes

* /

void loop() {

int sensorValue = analogRead(sensorPin);

float voltage = sensorValue * (5000.0 / 1023.0);

float temperatureC = voltage / 10.0;

lcd.setCursor(0, 1);

lcd.print(temperatureC);

lcd.print(" C ");

delay(1000);

}