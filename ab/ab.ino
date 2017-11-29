//Test code for determining aperture
#include<Stepper.h>
Stepper aperture(180,7,8,9,10);
int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(13,OUTPUT);
  aperture.setSpeed(90);
  

}

void loop() {
  if(Serial.available()>0)
  {
    a = Serial.parseInt();
    Serial.println(a);
    if( a == 'A'){
        
        digitalWrite(6,HIGH);
        aperture.step(6);
      }
     else if( a == 'B' ){
        digitalWrite(6,HIGH);
        aperture.step(-6);
     }
     else if( a == 'C'){
        digitalWrite(6,HIGH);
        aperture.step(-12);
     }
     else if( a== 'D'){
        digitalWrite(6,HIGH);
        aperture.step(-24);
     }
     else if( a== 'E'){
        digitalWrite(6,HIGH);
        aperture.step(-36);
     }
     else if( a== 'F'){
        digitalWrite(6,HIGH);
        aperture.step(-42);
     }
     else if( a== 'G'){
        digitalWrite(6,HIGH);
        aperture.step(-48);
     }
     else if( a== 'H'){
        digitalWrite(6,HIGH);
        aperture.step(-60);
     }
     else if( a== 'I'){
        digitalWrite(6,HIGH);
        aperture.step(-66);
     }
     else if( a== 'J'){
        digitalWrite(6,HIGH);
        aperture.step(-78);
     }
     else if( a== 'K'){
        digitalWrite(6,HIGH);
        aperture.step(-84);
     }
     else if( a== 'L'){
        digitalWrite(6,HIGH);
        aperture.step(-90);
     }
     else if( a== 'M'){
        digitalWrite(6,HIGH);
        aperture.step(-96);
     }
     else if( a== 'N'){
        digitalWrite(6,HIGH);
        aperture.step(-102);
     }
     else if( a== 'O'){
        digitalWrite(6,HIGH);
        aperture.step(-108);
     }
     else if( a== 'P'){
        digitalWrite(6,HIGH);
        aperture.step(-114);
     }
     else
     {
      digitalWrite(6,HIGH);
      aperture.step(-a);
     }
     digitalWrite(6,LOW);
  }

}
