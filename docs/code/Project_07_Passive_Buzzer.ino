/*

Electronics Learning Starter Kit for Arduino

Project 7

Passive Buzzer

Edit By Keyes

*/

void loop() {

for (int thisNote = 0; thisNote < 8; thisNote++) {

int noteDuration = 1000 / noteDurations[thisNote]; // Calculate the note duration

tone(buzzerPin, melody[thisNote], noteDuration); // Play the note

int pauseBetweenNotes = noteDuration * 1.30; // Calculate the pause between notes

delay(pauseBetweenNotes); // Wait for the pause duration

noTone(buzzerPin); // Stop playing the note

}

}