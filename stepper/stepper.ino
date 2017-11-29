#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(5,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  myStepper.setSpeed(80);
}

void loop() {
  // step one step:
  if(digitalRead(5)==0){
  
  myStepper.step(2);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  }
  if(digitalRead(4)==0){
    myStepper.step(Serial.read());
  }
  Serial.println(analogRead(A5));
  //delay(500);
}

