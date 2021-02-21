#include<avr/io.h>
int main(void)
{
  DDRD = 0x01; // initiallises DDRD
  while (1) // while loop
  {
    PORTD = 0x00; // off
    waitms(500); // function to have a delay
    PORTD = 0x01; // on
    waitms(20); //// function to have a delay
  }
}

void waitms(int a) // function to inizialize the delay
{
  int count = 0;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  while(!(count == a)) // stops delay
  {
    if (TCNT0 == 249) // one milli seecond
    {
      count ++;
      TCNT0 = 0;
    }
  }
}

