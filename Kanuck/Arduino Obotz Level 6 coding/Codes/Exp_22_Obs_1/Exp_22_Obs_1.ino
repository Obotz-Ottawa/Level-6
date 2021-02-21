#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x) & (y))
#define bitn(p)(0x01 << (p))
int i = 0;
long result, averege;
int main (void)
{
  Serial.begin(2000000);
  while (1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ADSC)));
    result = result + ADCW;
    i++;
    if (i > 99)
    {
      averege = result / 100;
      Serial.println(averege);
      _delay_ms(500);
      result = 0;
      averege = 0;
      i = 0;
    }
  }
}
