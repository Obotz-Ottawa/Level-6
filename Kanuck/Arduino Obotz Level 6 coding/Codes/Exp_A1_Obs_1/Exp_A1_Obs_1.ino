#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|=y)
#define clearbit(x,y) (x&=~y)
#define bitn(p)(0x01 <<(p))
int c = 0;
int d = 0;
int count = 0;
int count_angle3, count_angle1, count_angle2;
int main (void)
{
  DDRD = 0xFF;
  DDRB = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while(1)
  {
    angle1(60);
    angle2(60);
    angle3(60);
    _delay_ms(500);
    angle3(10);
    _delay_ms(500);
    for (int i = 0; i < 12; i ++)
    {
      c++;
      antistepper();
      _delay_ms(50);
    }
    _delay_ms(500);
    angle3(60);
    _delay_ms(500);
    for (int i = 0; 1 < 12; i++)
    {
      d++;
      clkstepper();
      _delay_ms(500);
    }
    _delay_ms(500);
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
void angle1(int a)
{
  count_angle1 = a + 46;
}
void angle2(int b)
{
  count_angle2 = b + 46;
}
void angle3(int c)
{
  count_angle3 = c + 46;
}



