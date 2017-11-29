#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const int relayPin[4]={6,7,8,13}; //pin 6 drives first relay, ie one nearest to Gnd wire
const int switchPin[4]={9,10,1,0}; // Top most button mapped to digitalPin 9
const int senseThr = 3.3;
boolean loadOn = false;
boolean mainsOn = true;
boolean mainsState = false;
char* sourceNames[]={"Source: Mains","Source: Solar","Source: Inverter","Source: Generator"};

int scroller = 0;

void setup() {
  for (int i=0;i<4;i++)
     pinMode(relayPin[i],OUTPUT);
  
  for (int j=0;j<4;j++)
    pinMode(switchPin[j],INPUT);

  lcd.clear();
  lcd.begin(16,2); //set up no of rows and columns
  lcd.print("Multi Source Power Supply"); // Startup Message
  delay(200);
  scroll(200);
  lcd.clear();
  resetRelays(); 
  //Switch to Mains first
  lcd.print("Source: Mains");
  digitalWrite(relayPin[0],HIGH);
  scroll(200);                         
  
}

void loop() {
  
  int reading[4];
  
  for (int j=0;j<4;j++){
    reading[j] = digitalRead(switchPin[j]);
  }
  checkMains();
  if (mainsOn == true && mainsState==false){
    lcd.clear();
    mainsState = true;
    resetRelays();
    lcd.print("Source: Mains");
    digitalWrite(relayPin[0],HIGH);
    
  }
    
  
  checkPower(); //update loadOn
  
  
  if (loadOn == false){
    lcd.clear();
    resetRelays();
    mainsState = false;
    lcd.print("Source: Solar Power");
    digitalWrite(relayPin[1],HIGH);
    delay(550);
    
  }

 checkMains();
  if (mainsOn == true && mainsState==false){
    lcd.clear();
    mainsState = true;
    resetRelays();
    lcd.print("Source: Mains");
    digitalWrite(relayPin[0],HIGH);
    
  }
  
  checkPower(); //update loadOn
  if (loadOn == false){
    lcd.clear();
    resetRelays();
    mainsState = false;
    lcd.print("Source: Inverter");
    digitalWrite(relayPin[2],HIGH);
    delay(550);
  }

  checkMains();
  if (mainsOn == true && mainsState==false){
    lcd.clear();
    mainsState = true;
    resetRelays();
    lcd.print("Source: Mains");
    digitalWrite(relayPin[0],HIGH);
    
  }
  
  checkPower(); //update loadOn
  if (loadOn == false){
    lcd.clear();
    mainsState = false;
    resetRelays();
    lcd.print("Source: Generator");
    digitalWrite(relayPin[3],HIGH);
    delay(550);
  }
  
  checkMains();
  if (mainsOn == true && mainsState==false){
    lcd.clear();
    mainsState = true;
    resetRelays();
    lcd.print("Source: Mains");
    digitalWrite(relayPin[0],HIGH);
    
  }
  checkPower(); //update loadOn
  
  if (loadOn == false){
    lcd.clear();
    resetRelays();
    mainsState = true;
    lcd.print("Source: Mains");
    digitalWrite(relayPin[0],HIGH);
    delay(550);
  }
  

  //Switch Action
  for (int i=0;i<4;i++){
    if (reading[i] == 0){
      resetRelays();
      lcd.clear();
      lcd.print(sourceNames[i]);
      digitalWrite(relayPin[i],HIGH);
      delay(500);
      
    }
  }
  
  // global scroll
  if (scroller > 12){
    scroller = 0;
  }
  if (scroller <6){
    lcd.scrollDisplayRight();
    scroller+=1;
  }
  else if(scroller>6){
    lcd.scrollDisplayLeft();
    scroller+=1;  
  }
  

}

void resetRelays(){
  for (int i=0;i<4;i++){
    digitalWrite(relayPin[i],LOW);
  }
}

void checkPower(){
  int powerSense = analogRead(A5); // Sensing the presence of power through ADC
  if (powerSense > senseThr)
    loadOn = true;
  else
    loadOn = false;
}

void checkMains(){
  int mainsSense = analogRead(A1);
  if(mainsSense > senseThr)
    mainsOn = true;
  else
    mainsOn = false;  
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
