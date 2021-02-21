#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define setbit(x,y)(x|= y)
#define clearbit(x,y)(x&=~y)
#define bitn(p)(0x01 << (p))
#define potato 1000
int x;
int z;
int count = 0;
int count_angle;
int main (void)
{
  Serial.begin(2000000);
  DDRD = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  
  while (true)
  {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ADSC)));
    x = ADCW;
    compare();
  }
}
void compare()
{
  {
    x = x + 10;
    angle(x);
    _delay_ms(potato);
}
}
void angle(int a)
{
  count_angle = a + 46;
}
ISR(TIMER1_COMPA_vect)
{
  count++;
  if (count <= count_angle)
  {
    setbit(PORTB, bitn(4));
  }
  else if ((count > count_angle) && (count < 1818))
  {
    clearbit(PORTB, bitn(4));
  }
  else if (count >= 1818)
  {
    count = 0;
  }
}
