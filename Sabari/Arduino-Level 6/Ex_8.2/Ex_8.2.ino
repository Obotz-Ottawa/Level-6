#include <avr/io.h>
#include <avr/delay.h>
#define checkbit(x,y)((x) &(y))
int main(void) {
  DDRD = 0xF0;
  int period = 50;
  int angle = 90;
  int angleC= 90/7.5; 

while(true) {
   if(checkbit(PINB, bit(0))) {
    
    for(int i=0;i<angleC;i+=4) {
      PORTD =0b11100000;
    _delay_ms(period);
     PORTD =0b11010000;
    _delay_ms(period);
     PORTD =0b10110000;
    _delay_ms(period);
     PORTD =0b01110000;
    _delay_ms(period);

    }
}
}
}
    
