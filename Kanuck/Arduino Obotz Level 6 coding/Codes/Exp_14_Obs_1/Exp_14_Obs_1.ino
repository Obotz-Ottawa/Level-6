#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define key1 0x1FE50AF
#define key2 0x1FED827
#define key3 0x1FEF807
#define key4 0x1FE30CF
#define key5 0x1FEB04F
#define key6 0x1FE48B7
long keycode = 0;
int timervalue;
int bitposition = 0;
int var = 0;
int c = 0;
int d = 0;
ISR(TIMER0_OVF_vect)
{
  var++;
  TCNT0 = 125;
}
ISR(INT2_vect)
{
  timervalue = var;
  var = 0;
  bitposition++;
  if (timervalue >= 100)
  {
    bitposition = -2;
    keycode = 0;
  }
  if ((bitposition >= 0) && (bitposition < 32))
  {
    if (timervalue > 3)
    {
      keycode |= (long)1<<(31-bitposition);
    }
  }
  else if (bitposition>= 32)
  {
    bitposition = 0;
    compare();
  }
}
int main (void)
{
  Serial.begin(2000000);
  DDRB = 0x00;
  DDRD = 0xFF;
  TIMSK0 = 0x01;
  EICRA = 0x20;
  EIMSK = 0x04;
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  while (1)
  {
  }
}
void compare()
{
  Serial.println(keycode, HEX);
  if (keycode == key6)
  {
    d++;
    clkstepper();
    _delay_ms(50);
  }
  if (keycode == key2)
  {
    c++;
    antistepper();
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
  if (d == 4)
  {
    PORTB = 0b11100000;
    d = 0;
  }
}
