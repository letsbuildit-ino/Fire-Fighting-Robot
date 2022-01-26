#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define RM_S A3
#define R_S A2
#define M_S A1
#define L_S A0
#define LM_S A4

int lms,ls,ms,rs,rms ;
int check=0;

const int rflamePin = A5;
const int lflamePin = 7;
int rFlame = HIGH;
int lFlame = HIGH;


void setup() {

  Serial.begin(9600);
  pinMode(rflamePin, INPUT);
  pinMode(lflamePin, INPUT);
  
  pinMode(R_S, INPUT);
  pinMode(M_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(RM_S, INPUT);
  pinMode(LM_S, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop() {

Serial.println(lms);
Serial.print(ls);
Serial.print(ms);
Serial.print(rs);
Serial.print(rms);

readsensors();
firefighting();
followline();

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void followline()
{

if (lms==LOW && ls==HIGH  && ms==HIGH && rs==HIGH && rms==LOW)                                     
{
 forward();
}
else if (lms==HIGH && ls==HIGH  && ms==HIGH && rs==HIGH && rms==HIGH)                                     
{
 forward();
}
else if (lms==LOW && ls==LOW  && ms==HIGH && rs==LOW && rms==LOW)                                     
{
 // check=0;
forward();
}
else if (lms==LOW && ls==LOW  && ms==HIGH && rs==HIGH && rms==LOW)                                     
{//check=0;
turnRight();
}
else if (lms==LOW && ls==LOW  && ms==LOW && rs==HIGH && rms==LOW)                                     
{//check=0;
turnRight();
}

else if (lms==LOW && ls==LOW  && ms==LOW && rs==HIGH && rms==HIGH)                                    
{//check=2;
turnRight();
}
else if (lms==LOW && ls==LOW  && ms==LOW && rs==LOW && rms==HIGH)                                      
{//check=2;
midturnRight();
}
else if (lms==LOW && ls==HIGH  && ms==HIGH && rs==HIGH && rms==HIGH)                                     
{//check=2;
turnRight();
}

else if (lms==LOW && ls==HIGH  && ms==HIGH && rs==LOW && rms==LOW)                                      
{//check=0;
turnLeft();
}
else if (lms==LOW && ls==HIGH  && ms==LOW && rs==LOW && rms==LOW)                                      
{
  //check=0;
turnLeft();
}
else if (lms==HIGH && ls==HIGH  && ms==LOW && rs==LOW && rms==LOW)                                      
{//check=1;
turnLeft();
}
else if (lms==HIGH && ls==LOW  && ms==LOW && rs==LOW && rms==LOW)                                      
{//check=1;
midturnLeft();
}

  else if (lms == LOW && ls == LOW  && ms == LOW && rs == LOW && rms == LOW)                            
  {
    if(check==1)
   {
   // readsensors();
        sharpturnLeft();
    
  }
  if(check==2)
  {
    //readsensors(); 
        sharpturnRight();
    
  }
  

  }
 

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


void readsensors(){
  lms = digitalRead(LM_S);
  ls = digitalRead(L_S);
  ms = digitalRead(M_S);
  rs = digitalRead(R_S);
  rms = digitalRead(RM_S);


if(lms==HIGH)
{
  check=1;
}
else if(rms==HIGH)
{
  check=2;
}
  
    
}

void forward(){

  motor2.setSpeed(160);
  motor3.setSpeed(160);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
    
} 

void turnRight(){

  motor3.setSpeed(155);
  motor3.run(FORWARD);

  }


void sharpturnRight(){
  
  motor2.setSpeed(155);
  motor3.setSpeed(155);

   motor2.run(BACKWARD);
   motor3.run(FORWARD);
   
  }
  void midturnRight(){

  motor3.setSpeed(255);
  motor2.setSpeed(255);
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  

  }

void turnLeft(){

  motor2.setSpeed(155);
  motor2.run(FORWARD);

}
void sharpturnLeft(){
  
  motor2.setSpeed(155);
  motor3.setSpeed(155);

  motor3.run(BACKWARD);
  motor2.run(FORWARD);
  
}

void midturnLeft(){

  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);

}

void stop(){

  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(2500);
 
}
