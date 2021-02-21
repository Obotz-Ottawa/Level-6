#include<avr/io.h>
#include<util/delay.h>
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011};
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
