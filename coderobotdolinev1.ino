#include <AFMotor.h>

#include <AFMotor.h>
// Robot model line simplely
 
//Libraries
#include <AFMotor.h>

#define left A0
#define right A1

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

void setup() {
  
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);
  
}

void loop(){

  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));
 
  if(digitalRead(left)==0 && digitalRead(right)==0){
    // Robot go straingt
    motor1.run(FORWARD);
    motor1.setSpeed(80); // Robot movement speed from a range 0 to 255
    motor2.run(FORWARD); 
    motor2.setSpeed(80);// Robot movement speed from a range 0 to 255
    motor3.run(FORWARD);
    motor3.setSpeed(80);// Robot movement speed from a range 0 to 255
    motor4.run(FORWARD);
    motor4.setSpeed(80);// Robot movement speed from a range 0 to 255
  }
  // Comparing robot 2 sensor
  else if(digitalRead(left)==0 && !analogRead(right)==0){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(80);
    motor2.run(FORWARD);
    motor2.setSpeed(80);
    motor3.run(BACKWARD);
    motor3.setSpeed(80);
    motor4.run(BACKWARD);
    motor4.setSpeed(80);
    
  }
  //Comparing robot 2 sensor 
  else if(!digitalRead(left)==0 && digitalRead(right)==0){
    //rẽ phải 
    motor1.run(BACKWARD);
    motor1.setSpeed(80);
    motor2.run(BACKWARD);
    motor2.setSpeed(80);
    motor3.run(FORWARD);
    motor3.setSpeed(80);
    motor4.run(FORWARD);
    motor4.setSpeed(80);
   
  }
  //when 2 sensor not signal to return
  else if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //stopped 
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }
  
}
