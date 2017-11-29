#include<SPI.h>
int val1;
void setup() {
  Serial.begin(9600);

  // start the SPI library:
  SPI.begin();
  delay(100);
  
}
 void loop(){
    SPI.transfer(Serial.read());
   
   
   
 }
 
 void writer(int x){
   SPI.transfer(x);
 }
   
     
