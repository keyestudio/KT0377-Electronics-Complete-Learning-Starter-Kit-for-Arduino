/*

Electronics Learning Starter Kit for Arduino

Project 17

1602 LCD

Edit By Keyes

*/

void loop() {

lcd.setCursor(0, 1);

lcd.print(millis() / 1000);

}