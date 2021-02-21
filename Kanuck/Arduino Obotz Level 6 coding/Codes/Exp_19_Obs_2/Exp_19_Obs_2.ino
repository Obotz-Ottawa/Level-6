#include<avr/io.h>
#include<util/delay.h>
int number[] = {0xF1, 0x63, 0xF1, 0xB3, 0xF6, 0xF6, 0xF6, 0x60, 0xF6, 0xF3};
int main (void)
{
  int i = 0;
  DDRC = 0xFF;
  while (1)
  {
    if(i < 10)
    {
      PORTC = number[i];
      _delay_ms(1000);
      i++;
    }
  }
}
