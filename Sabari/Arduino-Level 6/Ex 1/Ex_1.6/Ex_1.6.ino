#include <avr/io.h>
#include <util/delay.h>
int count = 0;

int main(void) {
  DDRD = 0x01;
  TCCR1A = 0x00; // Using TCCR1
  TCCR1B = 0x05; // Using prescaler 1024
  
  while(true) {
   if(TCNT1 == 249) {
      count++;
      TCNT1 = 0;
    }
   if(count==63) { // Prescaler 1024 is 16 times slower than Prescaler 64 therfore you would divide
    PORTD ^= 0x01;
    count = 0;
   }
    
    
  
  }
}
