#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  int relayPin[4]={6,7,8,13}; //pin 6 drives first relay, ie one nearest to Gnd wire
  for (int i=0;i<4;i++)
     pinMode(relayPin[i],OUTPUT);
  
  int switchPin[4]={9,10,1,0); // Top most button mapped to digitalPin 9
  for (int j=0;j<4;j++)
    pinMode(switchPin[j],INPUT);
  
  
  lcd.clear();
  lcd.begin(16,2); //set up no of rows and columns
  lcd.print("Multi Source Power Supply");
  delay(200);
  scroll(200);
  lcd.clear();
}

void loop() {
  int Sw1,Sw2,Sw3,Sw4;
  Sw1 = analogRead(A0);
  Sw2 = analogRead(A1);
  Sw3 = analogRead(A4);
  Sw4 = analogRead(A5);
  
  lcd.print(Sw1);
  lcd.print(Sw2);
  lcd.print(Sw3);
  lcd.print(Sw4);
  delay(500);
  lcd.clear();
  

}

void scroll(int del) {
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(del);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(del);
  }
  // delay at the end of the full loop:
  delay(500);
}
