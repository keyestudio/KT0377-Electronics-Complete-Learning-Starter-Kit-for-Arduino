/ *

Kit de inicio para aprendizaje de electrónica con Arduino

Proyecto 9

Potenciómetro

Editado por Keyes

* /

void loop() {

potValue = analogRead(potPin); // Leer el valor del potenciómetro (rango 0-1023)

ledValue = map(potValue, 0, 1023, 0, 255); // mapear el valor del potenciómetro al brillo del LED (0-255)

analogWrite(ledPin, ledValue); // establecer el brillo del LED

delay(10); // retraso

}