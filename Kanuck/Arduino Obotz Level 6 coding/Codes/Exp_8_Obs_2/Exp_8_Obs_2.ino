#include<avr/io.h> //header files
#include<util/delay.h>
int main(void)
{
  int period = 50; //
  DDRD = 0xF0; //ports
  int count = 0;
  int angle = 90;
  int pulses = 0;
  while (true)
  {
    pulses = angle / 7.5;
    for(int i=0;i<pulses;i+=4) //check if i is less then pulses it increments by 4
    {
      PORTD = 0b11100000; moves the motor
      _delay_ms(period); //delay of 50 ms
      count++; //add count 1

      PORTD = 0b11010000;
      _delay_ms(period);
      count++;

      PORTD = 0b10110000;
      _delay_ms(period);
      count++;

      PORTD = 0b01110000;
      _delay_ms(period);
      count++;
    }
  }
}
