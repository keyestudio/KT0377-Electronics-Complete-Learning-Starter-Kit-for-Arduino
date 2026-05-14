/*

Electronics Learning Starter Kit for Arduino

Project 12

Temperature Sensor

Edit By Keyes

*/

int ThermistorPin = A0;
int Vo;
float R1 = 10000; // Fixed resistor value 10K
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; // Steinhart-Hart coefficients

void setup() {
  Serial.begin(9600);
}

void loop() {
  Vo = analogRead(ThermistorPin);
  
  // Calculate resistance of the thermistor
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  
  // Calculate temperature using Steinhart-Hart equation
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15; // Convert Kelvin to Celsius
  
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 
  
  delay(1000);
}
