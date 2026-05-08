/*

Electronics Learning Starter Kit for Arduino

Project 10

Photoresistor

Edit By Keyes

*/

void loop() {

int lightValue = analogRead(lightSensorPin); // Read the analog value of the light sensor

Serial.println(lightValue); // Print the value of the light sensor on the serial monitor

if (lightValue < threshold) {

digitalWrite(ledPin, HIGH); // If the light intensity is less than the threshold, turn on the LED

} else {

digitalWrite(ledPin, LOW); // If the light intensity is greater than or equal to the threshold, turn off the LED

}

delay(100); // Delay for 100 milliseconds

}