
const int HotShoe_Pin = 8;
const int HotShoe_Gnd = 9;
const int LogicVDD_Pin = 10;
const int Cam2Lens_Pin = 11;
const int Clock_Pin = 13;
void setup() // initialization
{
  Serial.begin(9600);
pinMode(HotShoe_Pin, INPUT);
digitalWrite(HotShoe_Pin, HIGH);
pinMode(HotShoe_Gnd, OUTPUT);
digitalWrite(HotShoe_Gnd, LOW);
pinMode(LogicVDD_Pin, OUTPUT);
digitalWrite(LogicVDD_Pin, HIGH);
pinMode(Cam2Lens_Pin, OUTPUT);
pinMode(Clock_Pin, OUTPUT);
digitalWrite(Clock_Pin, HIGH);
delay(100);
send_signal(0xb0);
delay(100);
send_signal(0xA0);
}
byte data=0x00;
void loop()
{

send_signal(data);
data++;

}
void send_signal(byte signal) // SPI command generator
{
unsigned int i;
for(i = 0; i < 16; i++)
{
digitalWrite(Clock_Pin, i & 1);
if(i % 2 == 0)
{
digitalWrite(Cam2Lens_Pin, (signal >> (i / 2)) & 1);
}
}
}
