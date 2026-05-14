/*

Electronics Learning Starter Kit for Arduino

Project 26

IR Remote Fan

Edit By Keyes

*/

#include <IRremote.h> // 引入红外库 (需 2.0.1 版本)

// --- 1. 红外接收器引脚定义及对象创建 ---
const int RECV_PIN = 2; // 红外接收器信号引脚 D2
IRrecv irrecv(RECV_PIN); // 创建红外接收对象
decode_results results;  // 存放解码结果的对象

// --- 2. L293D 电机控制引脚定义 ---
const int enablePin = 10; // D10: 控制电机速度 (PWM)
const int in1Pin = 11;    // D11: 控制电机方向1
const int in2Pin = 9;     // D9:  控制电机方向2

void setup() {
  Serial.begin(9600);      // 初始化串口，波特率 9600
  irrecv.enableIRIn();     // 启动红外接收器

  // 设置电机引脚为输出模式
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  Serial.println("系统初始化完毕，等待红外信号...");
}

void loop() {
  // 如果成功接收并解码了红外信号
  if (irrecv.decode(&results)) { 
    // 在串口打印接收到的十六进制(HEX)红外代码
    Serial.print("收到红外代码: 0x");
    Serial.println(results.value, HEX); 

    // 根据收到的按键代码执行相应动作
    switch (results.value) {
      
      // 按键 1 (示例代码)：正转 (您可以改成遥控器上的"上"键代码)
      case 0xFF629D: 
        setMotor(255, false); // 全速正转
        Serial.println("动作: 风扇正转 (FORWARD)");
        break;

      // 按键 2 (示例代码)：反转 (您可以改成遥控器上的"下"键代码)
      case 0xFFA857: 
        setMotor(255, true);  // 全速反转
        Serial.println("动作: 风扇反转 (BACKWARD)");
        break;

      // 按键 3 (示例代码)：停止 (您可以改成遥控器上的"OK"或"停止"键代码)
      case 0xFF02FD: 
        setMotor(0, false);   // 速度设为 0，停止
        Serial.println("动作: 风扇停止 (STOP)");
        break;
        
      default:
        // 未知按键不执行任何操作
        break;
    }
    
    // 恢复接收下一个信号
    irrecv.resume(); 
  }
  
  delay(100); // 略微延时，避免按键连发过度读取
}

// --- 3. 自定义电机控制函数 ---
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
