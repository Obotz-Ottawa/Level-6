#include <avr/io.h>
#include <util/delay.h>
int count = 0;
bool state = false;
int main(void) {
  DDRD = 0x01;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
 
  while(true) {
   if(TCNT0 == 249) {
      count++;
      TCNT0 = 0;
    }
    if(count == 100 && state == false) {
      PORTD = 0x01;
      count = 0;
      state = true;
    }
    if(count == 400 && state == true) {
      PORTD = 0x00;
      count = 0;
      state = false;
    }
    
    
  
  }
}
