/*
  Line Follower Robot
  Components: Arduino Uno, 2x IR Sensors,
  L298N Motor Driver, 2x DC Motors
  Author: Abhinav B
*/

// ── IR Sensor Pins ──
int leftIR  = 2;
int rightIR = 3;

// ── Motor Pins ──
int ENA = 9;   // Left motor speed (PWM)
int IN1 = 4;   // Left motor direction
int IN2 = 5;
int ENB = 10;  // Right motor speed (PWM)
int IN3 = 6;   // Right motor direction
int IN4 = 7;

// ── Speed Settings ──
int straightSpeed = 150;
int turnSpeed     = 120;

void setup() {
  pinMode(leftIR,  INPUT);
  pinMode(rightIR, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

void moveForward() {
  analogWrite(ENA, straightSpeed);
  analogWrite(ENB, straightSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 0);
  analogWrite(ENB, turnSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopBot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  int left  = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  if (left == LOW && right == LOW) {
    moveForward();
  }
  else if (left == HIGH && right == LOW) {
    turnLeft();
  }
  else if (left == LOW && right == HIGH) {
    turnRight();
  }
  else {
    stopBot();
  }
}
