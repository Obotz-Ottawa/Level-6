#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define checkbit(x,y)((x) &(y))

int i = 0;
int numbers[14] = {0xF6,0x60,0xD5,0xF1, 0x63,0xB3,0xB7,0xE0,0xF7,0xF3, 0xE7, 0x96, 0x67, 0x08};
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
    result = 0;
    average = 0;
    i = 0;
   }
  }
}

  
