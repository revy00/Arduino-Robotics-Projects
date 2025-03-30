#include <AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4); 

#define LEFT_SENSOR A0
#define MIDDLE_SENSOR A1
#define RIGHT_SENSOR A2

void setup() {
    Serial.begin(9600);
    motor1.setSpeed(150);
    motor2.setSpeed(150);
    motor3.setSpeed(150);
    motor4.setSpeed(150);
}

void moveForward() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void moveLeft() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void moveRight() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void stopMotors() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void loop() {
    int left = digitalRead(LEFT_SENSOR);
    int middle = digitalRead(MIDDLE_SENSOR);
    int right = digitalRead(RIGHT_SENSOR);

    if (middle == 1) {
        moveForward();
    } else if (left == 1) {
        moveLeft();
    } else if (right == 1) {
        moveRight();
    } else {
        stopMotors();
    }
}
