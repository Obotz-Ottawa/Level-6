#include <avr/io.h>
#include <avr/interrupt.h>
int count0 = 0;
int count2 = 0;

int main(void) {
  DDRD = 0x0F;
  SREG= 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x0A; // Set prescaler as 8 while maintaining CTC mode
  TIMSK0 = 0x06;

  PORTD = 0x09;

while(true) {
  
}

}

ISR(TIMER0_COMPA_vect) {
  count0++;
  if(count0==1600) { // Multiplied count0 by 8(orginally 250) to make up for the prescaler being 8 times as fast
    PORTD ^=0x0C;
    
    count0 =0;
  }
}
ISR(TIMER0_COMPB_vect) { 
  count2++;
  if(count2==8000) { //  Multiplied count2 by 8(orginally 1000) to make up for the prescaler being 8 times as fast
    PORTD ^=0x03;
 
    count2 =0;
  }
}
