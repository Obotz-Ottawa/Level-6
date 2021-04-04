#include <avr/io.h>
#include <avr/interrupt.h>
int count0 = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;

int main(void) {
  DDRD = 0x0F;
  SREG= 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x0B; // Set prescaler as 8 while maintaining CTC mode
  TIMSK0 = 0x06;
  TCCR2A = 0x00;
  TCCR2B = 0X0B;
  TIMSK2 = 0x06;

while(true) {
  
}

}

ISR(TIMER0_COMPA_vect) {
  count0++;
  if(count0==200) { // Multiplied count0 by 8(orginally 250) to make up for the prescaler being 8 times as fast
    PORTD ^=0x01;
    
    count0 =0;
  }
}
ISR(TIMER0_COMPB_vect) { 
  count1++;
  if(count1==400) { //  Multiplied count2 by 8(orginally 1000) to make up for the prescaler being 8 times as fast
    PORTD ^=0x02;
 
    count1 =0;
  }
}
ISR(TIMER2_COMPA_vect) { 
  count2++;
  if(count2==600) { //  Multiplied count2 by 8(orginally 1000) to make up for the prescaler being 8 times as fast
    PORTD ^=0x04;
 
    count2 =0;
  }
}
ISR(TIMER2_COMPB_vect) { 
  count3++;
  if(count3==100) { //  Multiplied count2 by 8(orginally 1000) to make up for the prescaler being 8 times as fast
    PORTD ^=0x08;
 
    count3 =0;
  }
}
