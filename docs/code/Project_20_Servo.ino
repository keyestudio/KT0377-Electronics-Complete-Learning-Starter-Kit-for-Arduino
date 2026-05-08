/ *

Kit de inicio para aprendizaje de electrónica con Arduino

Proyecto 20

Servo

Editado por Keyes

* /

void loop() {

myservo.write(0); // Gira el servo a 0 grados

delay(1000); // Retardo de 1 segundo

myservo.write(90); // Gira el servo a 90 grados

delay(1000); // Retardo de 1 segundo

myservo.write(180); // Gira el servo a 180 grados

delay(1000); // Retardo de 1 segundo

}