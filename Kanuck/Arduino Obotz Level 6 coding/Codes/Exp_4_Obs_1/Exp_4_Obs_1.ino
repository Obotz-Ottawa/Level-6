#include <avr/io.h>
#include <avr/interrupt.h>
int count0 = 0;
int count2 = 0;
int main(void)
{
  DDRD = 0xFF;
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x0B;
  TIMSK0 = 0x06;
  OCR0A = 249;
  OCR0B = 249;
  PORTB = 0x09;
  while(1)
{
}
}

ISR(TIMER0_COMPA_vect)
{
  count0++;
  if (count0 == 250)
  {
    PORTD ^= 1 << 2;
    PORTD ^= 1 << 3;
    count0 = 0;
  }
}
ISR(TIMER0_COMPB_vect)
{
  count2++;
  if (count2 == 1000)
  {
    PORTD ^= 1 << 0;
    PORTD ^= 1 << 1;
    count2 = 0;
  }
}


