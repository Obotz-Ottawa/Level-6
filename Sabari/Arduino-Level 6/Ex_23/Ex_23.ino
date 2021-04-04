#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define checkbit(x,y)((x) &(y))

int i = 0;
int numbers[14] = {0xF6,0x60,0xD5,0xF1, 0x63,0xB3,0xB7,0xE0,0xF7,0xF3, 0xE7, 0x96, 0x67, 0xFF};
int data; 
long result, average;

int main(void) {
  PORTC = 0xFF;
  Serial.begin(2000000);
  while (true) {
   ADMUX = 0x44;
   ADCSRA = 0xC7;
   while(checkbit(ADCSRA, bit(ADSC)));
   result = result + ADCW;
   i++;
   if(i>99) {
    average = result/100;
    Serial.println(average);
    compare();
    result = 0;
    average = 0;
    i = 0;
   }
  }
}
void compare() {
  if((average>=592 && average<=594) || (average>=764 && average<=766)) {
    PORTC = numbers[0];
  }
  if(average>=516 && average<=519) {
    PORTC = numbers[1];
  }
  if(average>=692 && average<=693) {
    PORTC = numbers[2];
  }
  if(average>=758 && average<=760) {
    PORTC = numbers[3];
  }
  if(average>=486 && average<=489) {
    PORTC = numbers[4];
  }
  if(average>=639 && average<=640) {
    PORTC = numbers[5];
  }
  if(average>=696 && average<=698) {
    PORTC = numbers[6];
  }
  if(average>=470 && average<=473) {
    PORTC = numbers[7];
  }
  if((average>=613 && average<=614) || (average>=844 && average<=845)) {
    PORTC = numbers[8];
  }
  if(average>=664 && average<=666) {
    PORTC = numbers[9];
  }
  if(average>=939 && average<=973) {
    PORTC = numbers[10];
  }
  if(average>=799 && average<=800) {
    PORTC = numbers[11];
  }
  if(average>=641 && average<=644) {
    PORTC = numbers[12];
  }
  if(average>=458 && average<=460) {
    PORTC = numbers[13];
  }

}
