#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int c = 0;
int d = 0;
int main(void) {
  DDRD = 0xFF
  Serial.begin(2000000);
  angle(0);
  while (true) {
    
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
    if(x<=10) {
      c++
      antistepper();
      _delay_ms(50);
    }
    else if(x>1000) {
      d++
      clkstepper();
      _delay_ms(50);
    }
    else {
      PORTD = 0x00;
    }


  }
}
void antistepper() {
  if (c == 1) {
    PORTD = 0b11100000;
  }
  if (c == 2) {
    PORTD = 0b11010000;
  }
  if (c == 3) {
    PORTD = 0b10110000;
  }
  if (c == 4) {
    PORTD = 0b01110000;
    c = 0;
  }
}
void clkstepper() {
  if (d == 1) {
    PORTD = 0b01110000;
  }
  if (d == 2) {
    PORTD = 0b10110000;
  }
  if (d == 3) {
    PORTD = 0b11010000;
  }
  if (d == 4) {
    PORTD = 0b11100000;
    d = 0;
  }
}
