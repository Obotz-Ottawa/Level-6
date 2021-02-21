#include<avr/io.h>
#include<util/delay.h>
int count = 0;
int main (void)
{
  DDRD = 0x01;
  TCCR2A = 0x00;
  TCCR2B = 0x03;
  while(1)
  {
    if (TCNT2 == 249)
    {
      count++;
      TCNT2 = 0;
    }
    if (count == 1000)
    {
      PORTD ^=0x01;
      count = 0;
    }
  }
}
