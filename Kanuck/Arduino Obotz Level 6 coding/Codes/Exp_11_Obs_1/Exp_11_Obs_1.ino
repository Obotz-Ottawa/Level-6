#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y)(x|= y)
#define clearbit(x,y)(x&=~y)
#define bitn(p)(0x01 << (p))
int count = 0;
int count_angle1 = 0;
int count_angle2 = 0;
int count_angle3 = 0;
int main(void)
{
  DDRB  = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while (1)
  {
    angle1(0);
    _delay_ms(500);
    angle2(30);
    _delay_ms(500);
    angle3(60);
    _delay_ms(500);
    angle1(90);
    _delay_ms(500);
    angle2(120);
    _delay_ms(500);
    angle3(180);
    _delay_ms(500);
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
ISR(TIMER1_COMPA_vect)
{
  count++;
  if (count <= count_angle1)
  {
    setbit(PORTB, bitn(5));
  }
  else if ((count > count_angle1) && (count < 1818))
  {
    clearbit(PORTB, bitn(5));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
    if (count <= count_angle2)
  {
    setbit(PORTB, bitn(6));
  }
  else if ((count > count_angle2) && (count < 1818))
  {
    clearbit(PORTB, bitn(6));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
    if (count <= count_angle3)
  {
    setbit(PORTB, bitn(7));
  }
  else if ((count > count_angle3) && (count < 1818))
  {
    clearbit(PORTB, bitn(7));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
}
