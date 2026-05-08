/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 5

PWM

Editado por Keyes

* /

void loop() {

analogWrite(ledPin, brightness); // Usa analogWrite para controlar el brillo del LED

brightness = brightness + fadeAmount; // Ajusta el brillo

if (brightness <= 0 || brightness >= 255) {

fadeAmount = -fadeAmount; // Invierte la dirección al alcanzar el máximo/mínimo

}

delay(30); // Retardo para controlar la velocidad del cambio de brillo

}