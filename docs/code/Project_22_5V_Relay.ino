/*

Electronics Learning Starter Kit for Arduino

Project 22

5V Relay

Edit By Keyes

*/

void loop() {

digitalWrite(relayPin, HIGH); // output high to trigger the relay

delay(1000); // delay 1s

digitalWrite(relayPin, LOW); //output low to disable the relay

delay(1000); // delay 1s

}