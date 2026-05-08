/*

Electronics Learning Starter Kit for Arduino

Project 16

8x8 LED Matrix

Edit By Keyes

*/

void Clear() {

for (int i = 0; i < 8; i++) {

digitalWrite(R[i], LOW);

digitalWrite(C[i], HIGH);

}

}