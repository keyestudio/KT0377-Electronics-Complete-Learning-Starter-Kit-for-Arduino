/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 29

Módulo Joystick

Editado por Keyes

* /

void loop() {

int xValue = analogRead(xPin); // Leer el valor del potenciómetro del eje X

int yValue = analogRead(yPin); // Leer el valor del potenciómetro del eje Y

int buttonState = digitalRead(buttonPin); // Leer el estado del botón

Serial.print("X: ");

Serial.print(xValue);

Serial.print(" Y: ");

Serial.print(yValue);

Serial.print(" Botón: ");

Serial.println(buttonState);

delay(100); // Retardo de 100 milisegundos

}