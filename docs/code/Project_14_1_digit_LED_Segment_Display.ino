/*

Electronics Learning Starter Kit for Arduino

Project 14

1 digit LED Segment Display

Edit By Keyes

*/

void displayNumber(int n) {

digitalWrite(a, num[n][0]);

...

digitalWrite(g, num[n][6]);

digitalWrite(dp, LOW); // Decimal point off

}