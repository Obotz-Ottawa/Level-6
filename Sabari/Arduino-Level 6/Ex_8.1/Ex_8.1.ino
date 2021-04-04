#include <avr/io.h>
#include <avr/delay.h>
#define checkbit(x,y)((x) &(y))
int main(void) {
  DDRD = 0xF0;
  int period = 50;
  int angle = 90;
  int angleC= 90/7.5; 
  int count = 0;
while(true) {
   if(checkbit(PINB, bit(0))) {
    count =0;
    while(count< angleC) {
      PORTD =0b11100000;
    _delay_ms(period);
     PORTD =0b11010000;
    _delay_ms(period);
     PORTD =0b10110000;
    _delay_ms(period);
     PORTD =0b01110000;
    _delay_ms(period);
    count+=4;

    }
}
}
}
    
