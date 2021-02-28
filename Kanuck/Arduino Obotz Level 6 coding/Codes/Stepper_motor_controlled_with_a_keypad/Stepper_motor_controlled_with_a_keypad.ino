#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x) & (y))
#define bitn(p)(0x01 << (p))
int i = 0;
int c = 0;
int d = 0;
long result, averege;
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
    PORTD = 0b01110000;
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
int main (void)
{
  Serial.begin(2000000);
  while (1)
  {
    DDRD = 0xF0;
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;
    if (i > 99)
    {
      averege = result / 100;
      Serial.println(averege);
      _delay_ms(500);
      result = 0;
      averege = 0;
      i = 0;
    }
    if (averege > 465 && averege < 480)
    {
      d++;
      clkstepper();
      _delay_ms(50);
      PORTD = 0x01;
    }
    if (averege > 690 && averege < 700)
    {
      c++;
      antistepper();
      _delay_ms(50);
      PORTD = 0x01;
    }
  }
}
