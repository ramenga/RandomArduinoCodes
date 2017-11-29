void setup() {
  pinMode(SCK,OUTPUT);
  pinMode(MOSI,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  byte a=Serial.read();
  Serial.println(a);
  shiftOut(MOSI,SCK,LSBFIRST,a);

}
