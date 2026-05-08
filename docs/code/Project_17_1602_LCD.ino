/*

Набор для изучения электроники для Arduino

Проект 17

1602 LCD

Редактирование: Keyes

*/ 

void loop() {

lcd.setCursor(0, 1);

lcd.print(millis() / 1000);

}