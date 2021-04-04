#include <avr/io.h>
#include <util/delay.h>
int offcount =0;
int oncount = 0;
int main(void) {
  DDRD = 0x01;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  TCCR1A = 0x00;
 
  while(true) {
    
    if(TCNT0 == 249) {
      offcount++;
      TCNT0 = 0;
    }
    if(offcount == 1000) {
      PORTD =0x01;
      offcount = 0;
      TCCR0B = 0;
      TCCR1B = 0x03;
    }
    if(TCNT1 == 249) {
      oncount++;
      TCNT1 = 0;
    }
    if(oncount == 100) {
      PORTD = 0x00;
      oncount = 0;
      TCCR1B = 0;
      TCCR0B = 0x03;
    }
  }
}
