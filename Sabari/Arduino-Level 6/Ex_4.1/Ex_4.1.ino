#include <avr/io.h>
#include <avr/interrupt.h>
int count0 = 0;
int count2 = 0;

int main(void) {
  DDRD = 0xFF;
  SREG= 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03; // Set prescaler as 8 while maintaining CTC mode
  TIMSK0 = 0x01;
  TCNT0 = 200;
  TCNT2 = 100;
  TCCR2A = 0x00;
  TCCR2B = 0x03;
  TIMSK2 = 0x01;

while(true) {
  
}

}

ISR(TIMER0_OVF_vect) {
  count0++;
  if(count0==2000) { // Multiplied count0 by 8(orginally 250) to make up for the prescaler being 8 times as fast
    PORTD ^=1<<0;
    
    count0 =0;
    
  }
  TCNT0 = 200;
}
ISR(TIMER2_OVF_vect) { 
  count2++;
  if(count2==2000) { //  Multiplied count2 by 8(orginally 1000) to make up for the prescaler being 8 times as fast
    PORTD ^=1<<1;
 
    count2 =0;
    
  }
  TCNT2 = 100;
}
