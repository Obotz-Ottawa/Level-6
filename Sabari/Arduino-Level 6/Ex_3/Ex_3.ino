#include <avr/io.h>
#include <util/delay.h>
void waitms(int a) {
  int count = 0; 
  
  while(count<=a) 
  if(TCNT0 == 249) {
    count++;
    TCNT0 = 0;
  }
}
int main(void) {
  DDRD =0xFF;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  PORTD = 0x00;

  while(true) {

    PORTD = 0x00;
    waitms(500);
    
    PORTD = 0x01;
    waitms(200);
  }
}
