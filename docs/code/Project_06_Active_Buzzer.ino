/*

Electronics Learning Starter Kit for Arduino

Project 6

Active Buzzer

Edit By Keyes

*/

void loop() {

// Make the buzzer sound

digitalWrite(BUZZER_PIN, HIGH);

delay(1000); // Sound for 1 second

// Stop the sound

digitalWrite(BUZZER_PIN, LOW);

delay(1000); // Stop for 1 second

}