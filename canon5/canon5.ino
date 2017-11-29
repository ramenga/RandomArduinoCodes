#include<SPI.h>
const int chipSelectPin = 4;
int myInts[100];
void setup() {
  delay(300);
  CLKPR = B10000000; // Divide the clock frequency
  CLKPR = B00000001; // on 2

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV128);
  SPI.setDataMode(SPI_MODE3);
}

void loop() {
  for(j = 0; j <51; j = j + 1 ){ 
      myInts[j] = SPI.transfer(0xA0);
      }

}
