/* 
*Analog Input, Digital Output
* This program acts as a counter for the times a particular analog input was interrupted.
* Can also select a secondary mode in which it can be used as a simple alarm
*/
long int ms,msp;  //Uptime Temporary Storage
const int N=625; //Analog Threshold Value
int count=0;    //Global count storage
const int time=2020;   //Threshold Time
int s1,s2;    
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,INPUT_PULLUP); //Selecting Mode
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);
  //For Parallel Binary Output
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  //Serial.begin(9600); Serial.println(count);
  PORTD=count;
}

void loop(){
  delay(300);
  if(digitalRead(12)==0)
    {
        s1 = analogRead(A5);                      
        s2 = analogRead(A1);
        count=0;
        if((s1<N)||(s2<N))
          {
            digitalWrite(11,HIGH);
            delay(2000);
            digitalWrite(11,LOW);
          }
         
    }
  else
  {
    msp = millis();
    s1 = analogRead(A5);
    s2 = analogRead(A1);
    if(s1<=N)
      {  
         digitalWrite(8,HIGH);
         hasentered();
         //Serial.println("hasentered");
      }
    else if(s2<=N)
      { digitalWrite(8,HIGH); 
        hasexited();
        //Serial.println("hasexited");
      }
  }
}

void hasentered(){
  HAY:delay(20);
  ms = millis();
  int x2;
  x2 = analogRead(A1);
  if(x2 <= N)
    {  increment();
        //Serial.print("incerment");Serial.println(x2);
     }
  else if((ms-msp) < time)
    {
      //Serial.print(x2);Serial.print("Recur-Hastentered");Serial.println(ms-msp);
      goto HAY;}
    digitalWrite(8,LOW);
}
void hasexited(){
  HAY2:delay(10);
  ms = millis();
  s1 = analogRead(A5);
  if(s1 <= N)
    {  decrement();
        //Serial.println("decerment");
      }
  else if((ms-msp) < time)
    {
        //Serial.print("Recur-Hasexited");Serial.println(ms-msp);
        goto HAY2;}
    digitalWrite(8,LOW);
}
void increment(){
  if ((count>=0)&&(count < 255))
    count=count+1;
  else
    count=0;
  digitalWrite(13,LOW);
  digitalWrite(13,HIGH);
  delay(400);
  digitalWrite(13,LOW);
  PORTD=count;
  //Serial.println(count);
}

void decrement(){
  if ((count>=0)&&(count <255))
    count=count-1;
  else
    count=0;
  digitalWrite(13,LOW);
  digitalWrite(13,HIGH);
  delay(400);
  digitalWrite(13,LOW);
  //Serial.println(count);
  PORTD=count;
}
