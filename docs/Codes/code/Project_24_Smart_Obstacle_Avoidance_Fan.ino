/*

Electronics Learning Starter Kit for Arduino

Project 24

Smart Obstacle Avoidance Fan

Edit By Keyes

*/

// --- 1. 超声波传感器引脚定义 ---
const int trigPin = 8;  // 发射引脚
const int echoPin = 7;  // 接收引脚

// --- 2. L293D 电机驱动引脚定义 ---
const int enablePin = 10; // D10: 控制电机速度 (PWM)
const int in1Pin = 11;    // D11: 控制电机方向1
const int in2Pin = 9;     // D9:  控制电机方向2

// --- 3. 参数设置 ---
const int safeDistance = 15; // 安全距离阈值设为 15 厘米

void setup() {
  // 初始化超声波引脚
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // 初始化电机控制引脚
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // 开启串口通信，用于在电脑上观察距离数据
  Serial.begin(9600);
}

void loop() {
  // ================= 步骤 1：发射声波并测量距离 =================
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // 发射 10 微秒的高频声波脉冲
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // 测量回声引脚高电平持续的时间（微秒）
  long duration = pulseIn(echoPin, HIGH);
  // 计算距离 (声速约 0.034 cm/us，往返距离所以除以 2)
  int distance = duration * 0.034 / 2;
  
  // 在串口监视器打印当前距离
  Serial.print("当前距离: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // ================= 步骤 2：根据距离控制电机启停 =================
  // 加入 distance > 0 是为了防止传感器偶尔测距失败返回 0 导致误判
  if (distance > 0 && distance <= safeDistance) {
    // 障碍物太近！速度设为 0，停止电机。
    setMotor(0, false);
    Serial.println(">>> 状态: 危险！已刹车 <<<");
  } else {
    // 前方安全！速度设为 255，全速正转。
    setMotor(255, false);
    Serial.println("状态: 正常运行中...");
  }
  
  // 稍作延时，避免测距频率过高互相干扰
  delay(100); 
}

// ================= 自定义电机控制函数 =================
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse); 
  digitalWrite(in2Pin, reverse);  
}
