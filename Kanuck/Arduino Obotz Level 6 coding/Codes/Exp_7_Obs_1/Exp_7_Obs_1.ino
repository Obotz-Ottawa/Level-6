#include<avr/io.h> //header
#include<util/delay.h> //header for dealy
int main(void)
{
  int period = 20; //creates a variable valued at 20
  DDRD = 0xF0; // Set PD4 to PD7
  while (1)
  {
    for (int i = 0; i < 12; i++) //repeat 12 times
    {
      PORTD = 0b11100000; // clockwise 1 step
      _delay_ms(period); //wait 20ms
      PORTD = 0b11010000;
      _delay_ms(period);
      PORTD = 0b10110000;
      _delay_ms(period);
      PORTD = 0b01110000;
      _delay_ms(period);

    }
    for (int i = 0; i < 12; i++) //repeat 12 times

    {
      PORTD = 0b01110000; // antoclockwise 1 step
      _delay_ms(period); //wait 20ms
      PORTD = 0b10110000;
      _delay_ms(period);
      PORTD = 0b11010000;
      _delay_ms(period);
      PORTD = 0b11100000;
      _delay_ms(period);
    }
  }
}
