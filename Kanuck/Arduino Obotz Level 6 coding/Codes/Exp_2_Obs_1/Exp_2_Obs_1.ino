#include<avr/io.h>
#include<util/delay.h>
int oncount = 0;
int offcount = 0;
int main (void)
{
  DDRD = 0x01;
  TCCR2A = 0x00;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  while (1)
  {
    if (TCNT0 == 249)
    {
      offcount++;
      TCNT0 = 0;
    }
    if (offcount == 1000)
    {
      PORTD = 0x01;
      offcount = 0;
      TCCR0B = 0;
      TCCR2B = 0x03;
    }
    if (TCNT2 == 249)
    {
      oncount++;
      TCNT2 = 0;
    }
    if (oncount == 100)
    {
      PORTD = 0x00;
      oncount = 0;
      TCCR2B = 0;
      TCCR0B = 0x03;
    }
  }
}
