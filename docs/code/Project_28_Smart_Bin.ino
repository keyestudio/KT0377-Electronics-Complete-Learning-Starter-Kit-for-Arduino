/*

Electronics Learning Starter Kit for Arduino

Project 28

Smart Bin

Edit By Keyes

*/

// Send a 10-microsecond high pulse to trigger the ultrasonic sensor

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Read the high duration on the Echo pin

duration = pulseIn(echoPin, HIGH);