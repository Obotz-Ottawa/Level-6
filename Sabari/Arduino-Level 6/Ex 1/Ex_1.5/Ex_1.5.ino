#include <avr/io.h>
#include <util/delay.h>
int count = 0;
int main(void) {
  DDRD = 0x0F;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  PORTD = 0x01; // Led Red on
  while(true) {
    if(TCNT0 == 249) {
      count++;
      TCNT0 = 0;
    }
    if(count == 500) {
      PORTD ^=0x05; //Toggling between Led Red and Led Blue
      count = 0;
    }
  }
}
