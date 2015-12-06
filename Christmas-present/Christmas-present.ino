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
  delay(5000);
}
void fullOff(){
  for(int y = 0; y <= 13; y++){
    digitalWrite(y, LOW);
  }
  delay(5000);
}
void loop() {
  // temporary not needed analogRead statement if(analogRead(A)) >= 400){
    fullOn();
    fullOf();
    
  // temporary not needed bracket analogread }
}
