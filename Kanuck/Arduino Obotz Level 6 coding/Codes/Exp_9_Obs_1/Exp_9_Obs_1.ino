#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x) & (y))
#define bitn(p) (0x01 << (p))
int c = 0;
int d = 0;
int main (void)
{
  DDRD = 0xFF;
  DDRB = 0x00;
  while (1)
  {
    if (checkbit(PINB, bitn(PB0)))
    {
      d++;
      clkstepper();
      _delay_ms(50);
    }
    if (checkbit(PINB, bitn(PB1)))
    {
      c++;
      antistepper();
      _delay_ms(50);
    }
  }
}
void antistepper()
{
  if (c == 1)
  {
    PORTD = 0b11100000;
  }
  if (c == 2)
  {
    PORTD = 0b10110000;
  }
  if (c == 3)
  {
    PORTD = 0b11010000;
  }
  if (c == 4)
  {
    PORTD = 0b11100000;
    c = 0;
  }
}
void clkstepper()
{
  if (d == 1)
  {
    PORTB = 0b01110000;
  }
  if (d == 2)
  {
    PORTB = 0b10110000;
  }
  if (d == 3)
  {
    PORTB = 0b11010000;
  }
  if (d == 1)
  {
    PORTB = 0b11100000;
    d = 0;
  }
}



