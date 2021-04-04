#include <avr/io.h>
#include <avr/delay.h>

int main(void) {
  DDRD = 0xF0;
  int period =62;
while(true) {
  for(int i=0;i<12; i++) {
    PORTD =0b11100000;
    _delay_ms(period);
     PORTD =0b11010000;
    _delay_ms(period);
     PORTD =0b10110000;
    _delay_ms(period);
     PORTD =0b01110000;
    _delay_ms(period);

  }
    for(int i=0;i<12; i++) {
    PORTD =0b01110000;
    _delay_ms(period);
     PORTD =0b10110000;
    _delay_ms(period);
     PORTD =0b11010000;
    _delay_ms(period);
     PORTD =0b11100000;
    _delay_ms(period);
}

}
}
