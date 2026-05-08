/ *

Kit de Inicio de Aprendizaje de Electrónica para Arduino

Proyecto 8

LED Controlado por Botón

Editado por Keyes

* /

void loop() {

buttonState = digitalRead(buttonPin); // Lee el estado del botón y lo almacena en la variable buttonState

if (buttonState == LOW) { // Si el botón está en estado no presionado (nivel bajo)

digitalWrite(ledPin, LOW); // Pone el LED en estado apagado

} else { // De lo contrario (el botón está en estado presionado, nivel alto)

digitalWrite(ledPin, HIGH); // Pone el LED en estado encendido

}

}