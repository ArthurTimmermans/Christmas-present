
unsigned long loopPrev = 0;

unsigned long chase1Prev = 0;
int chase1State = 0;
int chase1PrevState;

int chase2Reset = 0;

unsigned long chase4Prev = 0;

void setup() {
  // Pin setup
  // Green LED: 2,4,6,8,10,12
  // Red LED: 3,5,7,9,11,13
  
  for(int x = 2; x <= 13; x++){
    pinMode(x,OUTPUT);
  }
}

void fullOn(){
  for(int z = 0; z <= 13; z++){
    digitalWrite(z, HIGH);
  }
}
void fullOff(){
  for(int y = 0; y <= 13; y++){
    digitalWrite(y, LOW);
  }
}

void chase1(){
   unsigned long chase1Time = millis();
   int chase1Interval = 500;
   if(chase1Time - chase1Prev >= chase1Interval){
      if(chase1State == 0){
         for(int c11 = 2; c11 <= 13; c11++){
            if(c11%2 == 0){
               digitalWrite(c11, HIGH);
            }else{
               digitalWrite(c11, LOW);
            }
         }
         chase1State = 1;
         delay(500);
       }else{
         for(int c12 = 2; c12 <= 13; c12++){
            if(c12%2 == 0){
              digitalWrite(c12, LOW);
            }else{
              digitalWrite(c12, HIGH);
            }
         }
         chase1State = 0;
         delay(500);
       }
    }
}

void chase2(){
  if(chase2Reset == 0){
    fullOff();
    chase2Reset = 1;
  }
  for(int c2 = 2; c2 <= 14; c2++){
    digitalWrite(c2, HIGH);
    digitalWrite(c2-1, LOW);
    delay(100);
  }
}

void chase3(){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
}

void chase4(){
  unsigned long chase4Time = millis();
  int chase4Interval = 500;

  if(chase4Time - chase4Prev <= chase4Interval){
    for(int c41 = 2; c41 <= 13; c41++){
      digitalWrite(c41, HIGH);
    }
    delay(500);
  }else{
    for(int c42 = 2; c42 <= 13; c42++){
      digitalWrite(c42, LOW);
    }
    delay(500);
    chase4Prev = chase4Time;    
  }
}

void loop() {
  if(analogRead(A0) >= 200){
    unsigned long loopTime = millis();

    if(loopTime - loopPrev <= 8000){
      fullOn();
    }else if ((loopTime - loopPrev >= 8000) && (loopTime - loopPrev <= 13000)){
    //fullOff();
      chase1();
    }else if((loopTime - loopPrev >= 13000) && (loopTime - loopPrev <= 16000)){
      chase2();
    }else if((loopTime - loopPrev >= 16000) && (loopTime - loopPrev <= 21000)){
      chase3();
    }else if((loopTime - loopPrev >= 21000) && (loopTime - loopPrev <= 26000)){
      chase4();
    }else{
      chase2Reset = 0;
      loopPrev = loopTime;
    }
  }else{
    for(int x = 2; x <= 13; x++){
      digitalWrite(x, LOW);
    }
  }
}
