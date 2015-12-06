void setup() {
  // Pin setup
  // Green LED: 2,4,6,8,10,12
  // Red LED: 3,5,7,9,11,13
   
  for(int x = 2; x <= 13; x++){
    pinMode(x,OUTPUT);
  }
}

void loop() {

}
