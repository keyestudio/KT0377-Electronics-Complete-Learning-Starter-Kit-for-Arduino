/*

Electronics Learning Starter Kit for Arduino

Project 32

Motion Controlled Servo

Edit By Keyes

*/

#include <Wire.h>
#include <Servo.h>

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ;

Servo myServo;  // create servo object to control a servo

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6, true);  // request a total of 6 registers
  
  AcX = Wire.read()<<8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY = Wire.read()<<8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read()<<8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  
  // Map the X-axis acceleration (-17000 to 17000) to Servo angle (0 to 180)
  // Note: You may need to adjust the -17000 and 17000 values based on your specific sensor's calibration
  int servoAngle = map(AcX, -17000, 17000, 0, 180);
  
  // Constrain the angle to prevent servo damage
  servoAngle = constrain(servoAngle, 0, 180);
  
  myServo.write(servoAngle);  // tell servo to go to position in variable 'servoAngle'
  
  Serial.print("AcX: ");
  Serial.print(AcX);
  Serial.print(" => Angle: ");
  Serial.println(servoAngle);
  
  delay(50);  // small delay for stability
}
