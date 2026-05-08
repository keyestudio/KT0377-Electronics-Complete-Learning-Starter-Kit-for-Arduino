/*

Electronics Learning Starter Kit for Arduino

Project 3

LED Flowing Light

Edit By Keyes

*/

void loop() {

for (int i = 0; i < ledCount; i++) {

digitalWrite(ledPins[i], HIGH); // Turn on the current LED

delay(delayTime); // Delay

digitalWrite(ledPins[i], LOW); // Turn off the current LED

}

for (int i = ledCount - 2; i > 0; i--) {

digitalWrite(ledPins[i], HIGH); // Turn on the current LED

delay(delayTime); // Delay

digitalWrite(ledPins[i], LOW); // Turn off the current LED

}

}