/*

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 10

Fotoresistor

Editado por Keyes

*/

void loop() {

int lightValue = analogRead(lightSensorPin); // Leer el valor analógico del sensor de luz

Serial.println(lightValue); // Imprimir el valor del sensor de luz en el monitor serial

if (lightValue < threshold) {

digitalWrite(ledPin, HIGH); // Si la intensidad de luz es menor que el umbral, encender el LED

} else {

digitalWrite(ledPin, LOW); // Si la intensidad de luz es mayor o igual al umbral, apagar el LED

}

delay(100); // Retardo de 100 milisegundos

}