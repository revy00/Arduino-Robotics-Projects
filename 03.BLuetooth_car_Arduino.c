#include<AFmotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

void setup() {
  // put your setup code here, to run once:
 pinMode(A0,OUTPUT); //headlight
 pinMode(A1,OUTPUT); //taillight
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    command=Serial.read();
    Stop();
    switch(command)
    {
      case 'F';
      forward();
      break;
      case 'B';
      backward();
      break;
      case 'R';
      right();
      break;
      case 'L';
      left();
      break;
      case 'S';
      stop();
      break;
      case 'L';
      left();
      break;
      case 'W';
      HeadlightOn();
      break;
      case 'X';
      HeadlightOff();
      break;
      case 'Y';
      TaillightOn();
      break;
      case 'Z';
      TaillightOff();
      break;
      


    }
  }
}

void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void backward()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void HeadlightOn()
{
  digitalWrite(A0,HIGH);
}

void HeadlightOff()
{
  digitalWrite(A0,LOW);
}
