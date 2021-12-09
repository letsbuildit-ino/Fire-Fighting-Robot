#define enA 5
#define in1 7
#define in2 4
#define in3 3
#define in4 2
#define enB 6

#define RM_S A0
#define R_S A1
#define M_S A2
#define L_S A3
#define LM_S A4

int lms,ls,ms,rs,rms ;
int check=0;


void setup() {
    
  pinMode(R_S, INPUT);
  pinMode(M_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(RM_S, INPUT);
  pinMode(LM_S, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  analogWrite(enA, 255);
  analogWrite(enB, 225);
  delay(200);
  
}

void loop() {
  
  readsensors();

  followline();


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


void readsensors(){
  lms = digitalRead(LM_S);
  ls = digitalRead(L_S);
  ms = digitalRead(M_S);
  rs = digitalRead(R_S);
  rms = digitalRead(RM_S);

    Serial.print(lms);
     Serial.print(ls);
     Serial.print(ms);
     Serial.print(rs);
     Serial.println(rms);

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
    analogWrite(enA, 115);
  analogWrite(enB, 115);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
    
} 

void turnLeft(){

  analogWrite(enA, 155);
  analogWrite(enB, 155);
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);

  }


void sharpturnLeft(){
  
  analogWrite(enA, 150);
  analogWrite(enB, 150);
 
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);

  }
  void midturnLeft(){

  analogWrite(enA, 50);
  analogWrite(enB, 150);
 
  
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
  }

void turnRight(){
 
   analogWrite(enA, 155);
  analogWrite(enB, 155);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

}
void sharpturnRight(){
  
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);


}

void midturnRight(){

  analogWrite(enA, 150);
  analogWrite(enB, 50);
  digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);

}

void stop(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}
