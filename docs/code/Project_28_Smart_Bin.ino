/ *

Набор для изучения электроники для Arduino

Проект 28

Умная корзина

Редактировал Keyes

* /

// Отправить высокий импульс длительностью 10 микросекунд для запуска ультразвукового датчика

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Считать длительность высокого сигнала на выводе Echo

duration = pulseIn(echoPin, HIGH);