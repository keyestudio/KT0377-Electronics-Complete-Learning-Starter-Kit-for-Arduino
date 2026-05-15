/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 22

Relé de 5V

Editado por Keyes

* /

void loop() {

digitalWrite(relayPin, HIGH); // salida alta para activar el relé

delay(1000); // retraso de 1s

digitalWrite(relayPin, LOW); // salida baja para desactivar el relé

delay(1000); // retraso de 1s

}