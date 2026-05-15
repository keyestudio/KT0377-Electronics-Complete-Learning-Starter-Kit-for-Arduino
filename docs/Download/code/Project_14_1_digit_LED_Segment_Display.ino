/ *

Набор для начинающих по электронике для Arduino

Проект 14

1-значный светодиодный сегментный дисплей

Редактировано Keyes

* / 

void displayNumber(int n) {

digitalWrite(a, num[n][0]);

...

digitalWrite(g, num[n][6]);

digitalWrite(dp, LOW); // Десятичная точка выключена

}