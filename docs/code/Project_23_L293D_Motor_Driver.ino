/*

Electronics Learning Starter Kit for Arduino

Project 23

L293D Motor Driver

Edit By Keyes

*/

// 定义引脚
const int enablePin = 10; // D10: 控制电机速度 (PWM)
const int in1Pin = 11;    // D11: 控制电机方向1
const int in2Pin = 9;     // D9:  控制电机方向2

void setup() {
  // 设置控制引脚为输出模式
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  // 1. 全速正转，持续2秒
  setMotor(255, false); 
  delay(2000);

  // 2. 停止运转，持续1秒
  setMotor(0, false);   
  delay(1000);

  // 3. 全速反转，持续2秒
  setMotor(255, true);  
  delay(2000);

  // 4. 停止运转，持续1秒
  setMotor(0, false);   
  delay(1000);
}

// 自定义电机控制函数
// 参数 speed: 转速 (0~255)
// 参数 reverse: 转向 (false 为正转，true 为反转)
void setMotor(int speed, boolean reverse) {
  // 发送 PWM 信号设定转速
  analogWrite(enablePin, speed);
  
  // 利用取反逻辑控制转向，确保两个引脚电平始终相反
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
