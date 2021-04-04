#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
int numbers[10] = {0xF6,0x60,0xD5,0xF1, 0x63,0xB3,0xB7,0xE0,0xF7,0xF3};
int data; 

int main(void) {
  DDRC = 0xFF;
  SREG = 0x80;
  Serial.begin(2000000);
  while (true) {
   ADMUX = 0x40;
   ADCSRA = 0xCF;
   data = ADCW;
   compare();
   _delay_ms(300);
  }
}
void compare() {
  if(data>0 && data<10) {
    PORTC = numbers[0];
  }
  if(data>10 && data<20) {
    PORTC = numbers[1];
  }
  if(data>20 && data<30) {
   PORTC = numbers[2];
  }
  if(data>30 && data<40) {
    PORTC = numbers[3];
  }
  if(data>40 && data<50) {
   PORTC = numbers[4];
  }
  if(data>50 && data<60) {
    PORTC = numbers[5];
  }
  if(data>60 && data<70) {
   PORTC =  numbers[6];
  }
  if(data>70 && data<80) {
   PORTC =  numbers[7];
  }
  if(data>80 && data<90) {
    PORTC = numbers[8];
  }
  if(data>90) {
    PORTC = numbers[9];
  }
  
}
