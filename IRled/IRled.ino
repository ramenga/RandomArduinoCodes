const int brightness = 160;
int analog,scale;
const int maxOC = 200;

void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  analog = analogRead(A5);
  scale = (analog/1023)*255;
  constrain(scale,0,maxOC);
  if(scale <= brightness)
  {
      analogWrite(5,brightness);
      analogWrite(6,brightness);
      analogWrite(10,brightness);
      analogWrite(11,brightness);
  }
  else if(scale > brightness)
  {
      analogWrite(5,scale);
      analogWrite(6,scale);
      analogWrite(10,scale);
      analogWrite(11,scale);
  }
}
