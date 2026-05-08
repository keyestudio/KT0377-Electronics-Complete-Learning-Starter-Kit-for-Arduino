/*

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 17

LCD 1602

Editado por Keyes

*/

void loop() {

lcd.setCursor(0, 1);

lcd.print(millis() / 1000);

}