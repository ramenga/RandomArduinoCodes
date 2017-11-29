void setup() {
  Serial.begin(9600);
 
  pinMode(13, OUTPUT);
  pinMode(11,OUTPUT);
  

}
byte data=0x01;
void loop() {
  shiftOut(11,13,MSBFIRST,data);
  Serial.println(data);
  data++;
  if(data>=255){
    data=0;
  }
  
  delay(1000);
  

}
