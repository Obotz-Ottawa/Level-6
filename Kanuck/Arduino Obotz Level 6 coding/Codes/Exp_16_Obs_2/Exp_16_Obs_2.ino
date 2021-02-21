#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
int main (void)
{
  int x;
  int y;
  Serial.begin(2000000);
  DDRD = 0xFF;
  DDRC = 0xFF;
  DDRB = 0x00;
  while (true)
  {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (ADCSRA & (1 << ADSC));
    y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (ADCSRA & (1 << ADSC));
    x = ADCW;
    Serial.print("Y-axis:");
    Serial.print(y);
    Serial.print("x-axis:");
    Serial.println(x);
    if (PINB & 0x01)
    {
      PORTC = 0xFF;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    else
    {
      PORTC = 0x00;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    if(x < 100)
    {
      PORTB = 0b00000001;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    if(x < 800)
    {
      PORTD = 0b00000010;
       _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    else if(y > 100)
    {
      PORTD = 0b00000100;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    else if(y > 800)
    {
      PORTD = 0b00001000;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
    else
    {
      PORTD = 0b00000000;
      _delay_ms(500);
      PORTD = 0b00000000;
      _delay_ms(500);
    }
}
}
