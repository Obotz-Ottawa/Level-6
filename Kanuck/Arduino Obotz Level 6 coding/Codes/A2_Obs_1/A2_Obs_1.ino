#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x | = y)
#define clearbit(x,y)(x&=~y)
#define bitn(p) (0x01 <<(p))
#define key1 0x01FE50AF
#define key2 0x01FED827
#define key3 0x01FEF807
#define key4 0x01FE30CF
#define key5 0x01FEB04F
#define key6 0x01FE708F
#define key7 0x01FE00FF
#define key8 0x01FEF00F
int c = 0;
int d = 0;
int p = 60, q = 60, r = 60;
int count = 0;
int press = 0;
int count_angle3, count_angle1;
int count_angle2;
long keycode = 0;
int timervalue;
int bitposition = 0;
int var = 0;
int main (void)
{
  DDRB = 0x00;
  DDRD = 0xFF;
  TIMSK0 = 0x01;
  EICRA = 0x20;
  EIMSK = 0x04;
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1B = 0x03;
  TCCR1A = 0x00;
  TIMSK1 = 0x02;
  while (true)
  {
  }
}
void compare()
{
  if (keycode == key1)
  {
    p = p + 5;
    angle1(p);
  }

  if (keycode == key2)
  {
    p = p - 5;
    angle1(p);
  }

  if (keycode == key3)
  {
    q = q + 5;
    angle2(p);
  }

  if (keycode == key4)
  {
    q = q - 5;
    angle2(p);
  }

  if (keycode == key5)
  {
    angle3(50);
  }

  if (keycode == key6)
  {
    angle3(10);
  }

  if (keycode == key7)
  {
    c++;
    antistepper();
    _delay_ms(50);
  }

  if (keycode == key8)
  {
    d++;
    clkstepper();
    _delay_ms(50);
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
    PORTD = 0b11010000;
  }
  if (c == 3)
  {
    PORTD = 0b10110000;
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
