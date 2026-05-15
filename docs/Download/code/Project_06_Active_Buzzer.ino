/*

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 6

Zumbador Activo

Editado por Keyes

*/

void loop() {

// Hacer sonar el zumbador

digitalWrite(BUZZER_PIN, HIGH);

delay(1000); // Sonar durante 1 segundo

// Detener el sonido

digitalWrite(BUZZER_PIN, LOW);

delay(1000); // Pausa de 1 segundo

}