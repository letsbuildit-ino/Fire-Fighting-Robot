#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int rflamePin = A5;
const int lflamePin = A0;
int rFlame = HIGH;
int lFlame = HIGH;

void setup() {

  Serial.begin(9600);
  pinMode(rflamePin, INPUT);
  pinMode(lflamePin, INPUT);
  
  pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop() {

forward();
firefighting();

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void firefighting(){

  rFlame = digitalRead(rflamePin);
  lFlame = digitalRead(lflamePin);

  Serial.print(rFlame);
  Serial.println(lFlame);

  if (rFlame == 0){

   stop();
   motor4.setSpeed(255);
   motor4.run(FORWARD);
   
   }
  else{
   forward();
  }
  
  if (lFlame == 0){
   stop();
   motor1.setSpeed(255);
   motor1.run(BACKWARD);
   }
  else{
   forward();
  }
  
  if (rFlame == 0 || lFlame == 0){
   stop();
   motor1.setSpeed(255);
   motor1.run(BACKWARD);
   motor4.setSpeed(255);
   motor4.run(FORWARD);
  }
  else{
   forward();
  }
  
}

void forward(){

  motor2.setSpeed(135);
  motor3.setSpeed(135);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
    
} 

void stop(){

//  motor2.setSpeed(255);
//  motor3.setSpeed(255);
//  motor2.run(BACKWARD);
//  motor3.run(BACKWARD);
//  delay(200);
//  
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(2500);
}
