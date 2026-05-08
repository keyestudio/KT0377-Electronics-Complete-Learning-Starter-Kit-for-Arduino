/ *

Kit de inicio para aprendizaje de electrónica con Arduino

Proyecto 21

Motor paso a paso

Editado por Keyes

* /

void loop() {

Serial.println("clockwise"); // Mostrar información de rotación en sentido horario

myStepper.step(stepsPerRevolution); // Girar el motor en sentido horario una revolución

delay(500); // Pausa de 500 milisegundos

Serial.println("counterclockwise"); // Mostrar información de rotación en sentido antihorario

myStepper.step(-stepsPerRevolution / 2);// Girar el motor en sentido antihorario media revolución

delay(500); // Pausa de 500 milisegundos

}