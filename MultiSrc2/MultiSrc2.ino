#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pinState[4] = {HIGH,HIGH,HIGH,HIGH}; //Variables for Debouncing of Input Pins
int buttonState[4];
int lastButtonState[4] = {LOW,LOW,LOW,LOW};
long lastDebounceTime[4] = {0,0,0,0}; // the last time the output pin was toggled
long debounceDelay = 50; // the debounce time; increase if the output flickers
  
const int relayPin[4]={6,7,8,13}; //pin 6 drives first relay, ie one nearest to Gnd wire
const int switchPin[4]={9,10,1,0}; // Top most button mapped to digitalPin 9

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
}

void loop() {
  int powerSense = analogRead(A0); // Sensing the presence of power through ADC
  int reading[4];
  for (int j=0;j<4;j++){
    reading[j] = digitalRead(switchPin[j]);
  }
  for (int j=0;j<4;j++){
    reading[j] = digitalRead(switchPin[j]);
    if (reading[j] != lastButtonState[j]){
       lastDebounceTime[j] = millis();
    }
    if ((millis() - lastDebounceTime[j]) > debounceDelay ) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading[j] != buttonState[j]) {
      buttonState[j] = reading[j];

      // only toggle the LED if the new button state is HIGH
      if (buttonState[j] == HIGH) {
        pinState[j] = !pinState[j];
      }
    }
  }
  for (int j=0;j<4;j++){
    lcd.print(reading[j]);
  }
    
  }
 
  //lcd.print(pinState[1]);
  //lcd.print(pinState[2]);
  //lcd.print(pinState[3]);
  //delay(500);
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
