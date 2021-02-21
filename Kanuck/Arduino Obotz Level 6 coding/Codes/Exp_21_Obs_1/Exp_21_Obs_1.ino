#include<avr/io.h>
#include<util/delay.h>
int data;
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b1100011, 0b10110011, 0b10110111, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011};
int main(void)
{
  DDRC = 0xFF;
  SREG = 0x80;
  while (true)
  {
    ADMUX = 0x41;
    ADCSRA = 0xCF;
    _delay_ms(500);
  }
}
ISR(ADC_vect)
{
  data = ADCW;
  compare();
}
void compare()
{
  if (data > 0 && data < 10)
  {
    PORTC = number[0];
  }
  if (data > 10 && data < 20)
  {
    PORTC = number[1];
  }
  if (data > 20 && data < 30)
  {
    PORTC = number[2];
  }
  if (data > 30 && data < 40)
  {
    PORTC = number[3];
  }
  if (data > 40 && data < 50)
  {
    PORTC = number[4];
  }
  if (data > 50 && data < 60)
  {
    PORTC = number[5];
  }
  if (data > 60 && data < 70)
  {
    PORTC = number[6];
  }
  if (data > 70 && data < 80)
  {
    PORTC = number[7];
  }
  if (data > 80 && data < 90)
  {
    PORTC = number[8];
  }
  if (data > 100)
  {
    PORTC = number[9];
  }
}
