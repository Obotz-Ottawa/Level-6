#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CHECKBIT(x,y)((x)&(y))
#define SETBIT(x,y)(x|=y)
#define CLEARBIT(x,y)(x&= ~y)
#define BITN(p)(0x01 << (p))
int c = 0;
int d = 0;
int x, y;
int p = 60, q = 60, r = 60;
int count = 0;
int Press = 0;
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




void clkstepper() //stepper motor clockwise
{
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

void antistepper()  //stepper motor anticlockwise
{
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
    PORTD = 0b11100000;
    c = 0;
  }
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
  angle1(60);
  angle2(60);
  angle3(60);
  while (true)
  {
    if (CHECKBIT(PINB, BITN(PB0)))
    {
      Press++;
      _delay_ms(300);
    }
    if (Press == 1)
    {
      ADCconversion();
      PORTD = 0x01;
      if (y > 100)
      {
        p++;
        angle1(p);
      }
      if (y > 800)
      {
        p--;
        angle1(p);
      }
    }
    if (Press == 2)
    {
      ADCconversion();
      PORTD = 0x02;
      if (y < 100)
      {
        q++;
        angle2(q);
      }
      if (y > 800)
      {
        q--;
        angle2(q);
      }
    }
    if (Press == 3)
    {
      ADCconversion();
      PORTD = 0x03;
      if (y < 100)
      {
        r++;
        angle3(r);
      }
      if (y > 800)
      {
        r--;
        angle3(r);
      }
    }
    if (Press == 4)
    {
      ADCconversion();
      PORTD = 0x04;
      if (y < 100)
      {
        c++;
        antistepper();
        _delay_ms(50);
      }
      if (y > 800)
      {
        d++;
        clkstepper();
        _delay_ms(50);
      }
    }
    if (Press == 5)
    {
      Press = 1;
    }
  }
}
void ADCconversion()
{
  ADMUX = 0x42;
  ADCSRA = 0xC7;
  while (CHECKBIT(ADCSRA, BITN(ADSC)));
  x = ADCW;
  ADMUX = 0x43;
  ADCSRA = 0xC7;
  while (CHECKBIT(ADCSRA, BITN(ADSC)));
  y = ADCW;
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
