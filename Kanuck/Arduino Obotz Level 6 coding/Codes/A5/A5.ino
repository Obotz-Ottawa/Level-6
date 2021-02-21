#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CHECKBIT(x,y)((x)&(y))
#define SETBIT(x,y)(x|=y)
#define CLEARBIT(x,y)(x&= ~y)
#define BITN(p)(0x01 << (p))
int x, y;
int count = 0;
int count_angle3, count_angle2, count_angle1;
void angle1(int a) //base servo
{
  count_angle1 = a + 46;
}

void angle2 (int a) //elbow servo
{
  count_angle2 = a + 46;
}

void angle3 (int a)//claw servo
{
  count_angle3 = a + 46;
}

int main(void)
{
  DDRD = 0xFF;
  DDRB = 0xF0;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while (true)
  {
  ADMUX = 0x42;
  ADCSRA = 0xC7;
  while (CHECKBIT(ADCSRA, BITN(ADSC)));
  x = ADCW;
  ADMUX = 0x43;
  ADCSRA = 0xC7;
  while (CHECKBIT(ADCSRA, BITN(ADSC)));
  y = ADCW;

  if(x > 800)
  {
    angle1(60);
    _delay_ms(100);
  }
  else if(x < 100)
  {
    angle2(60);
    _delay_ms(100);
  }
    if(y > 800)
  {
    angle2(110);
    angle1(10);
    _delay_ms(100);
  }
  else
  {
    angle2(170);
    angle1(10);
  }



ISR (TIMER1_COMPA_vect)
{
  count++;
  if (count <= count_angle1) {
    SETBIT(PORTB, 5);
  }
  else if ((count > count_angle1) && (count < 1818)) {
    CLEARBIT(PORTB, 5);
  }
  else if (count >= 1818) {
    count = 0;
  }
  if (count <= count_angle2) {
    SETBIT(PORTB, 6);
  }
  else if ((count > count_angle2) && (count < 1818)) {
    CLEARBIT(PORTB, 6);
  }
  else if (count >= 1818) {
    count = 0;
  }
  if (count <= count_angle3) {
    SETBIT(PORTB, 7);
  }
  else if ((count > count_angle3) && (count < 1818)) {
    CLEARBIT(PORTB, 7);
  }
  else if (count >= 1818) {
    count = 0;
  }
}
