/*

Electronics Learning Starter Kit for Arduino

Project 30

Joystick Motion Control

Edit By Keyes

*/

#include <Stepper.h>

// 定义步进电机旋转一圈的步数 (28BYJ-48 通常为 2048 步)
const int stepsPerRevolution = 2048; 

// 初始化步进电机对象，注意引脚顺序为 8, 10, 9, 11
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // 设置步进电机的转速为 10 RPM (转/分钟)
  myStepper.setSpeed(10);
  
  // 初始化串口通信，方便观察摇杆数值
  Serial.begin(9600);
}

void loop() {
  // 1. 读取摇杆 X 轴的模拟值 (范围 0 - 1023)
  int xValue = analogRead(A0);
  
  // 在串口打印当前数值，方便调试
  Serial.print("摇杆 X 轴数值: ");
  Serial.println(xValue);

  // 2. 判断摇杆推拉方向，并控制电机
  if (xValue < 300) {
    // 摇杆被向一侧推动：电机正向步进
    myStepper.step(10); 
  }
  else if (xValue > 800) {
    // 摇杆被向另一侧推动：电机反向步进
    myStepper.step(-10); 
  } 
  else {
    // 摇杆处于中间自然状态 (300 ~ 800)
    // 释放电机的所有线圈，防止步进电机在待机时严重发热
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
