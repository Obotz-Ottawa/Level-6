#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01 << (p))
int x, c , d;
int main(void)
{
  DDRD = 0xFF;
  while (1)
  {
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ADSC)))
      x = ADCW;
    if (x < 100)
    {
      c++;
      antistepper();
      _delay_ms(50);
    }
    else if (x > 800)
    {
      d++;
      clkstepper();
      _delay_ms(50);
    }
    else
    {
      PORTD = 0x00;
    }
  }
}
void clkstepper() //stepper motor clockwise
{
  if(d==1){
    PORTD = 0b01110000;
    }
  if(d==2){
    PORTD = 0b10110000;
    }
  if(d==3){
    PORTD = 0b11010000;
    }
  if(d==4){
    PORTD = 0b11100000;
    d = 0;
  }
}

void antistepper()  //stepper motor anticlockwise
{
  if(c==1){
    PORTD = 0b11100000;
    }
  if(c==2){
    PORTD = 0b11010000;
    }
  if(c==3){
    PORTD = 0b10110000;
    }
  if(c==4){
    PORTD = 0b11100000;
    c = 0;
  }
}
