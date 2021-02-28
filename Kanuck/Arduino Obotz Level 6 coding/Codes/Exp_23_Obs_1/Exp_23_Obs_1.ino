#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y)((x) & (y))
#define bitn(p)(0x01 << (p))
int i = 0;
long result,averege;
int number[]={0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011, 0b00111101, 0b00110111, 0b10010110, 0b01110101, 0b01100110, 0b10010000};
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
      compare();
      result = 0;
      averege = 0;
      i = 0;
    }
  }
}

void compare()
{
  if (averege > 425 && averege < 520)
  {
    PORTC = number[1];
  }
  if (averege > 600 && averege < 624)
  {
    PORTC = number[2];
  }
  if (averege > 769 && averege < 770)
  {
    PORTC = number[3];
  }
  if (averege > 779 && averege < 987)
  {
    PORTC = number[10];
  }
  if (averege > 489 && averege < 337)
  {
    PORTC = number[4];
  }
  if (averege > 509 && averege < 575)
  {
    PORTC = number[5];
  }
  if (averege > 789 && averege < 706)
  {
    PORTC = number[6];
  }
  if (averege > 789 && averege < 886)
  {
    PORTC = number[11];
  }
  if (averege > 307 && averege < 473)
  {
    PORTC = number[7];
  }
  if (averege > 488 && averege < 518)
  {
    PORTC = number[8];
  }
  if (averege > 673 && averege < 675)
  {
    PORTC = number[9];
  }
  if (averege > 677 && averege < 844)
  {
    PORTC = number[12];
  }
  if (averege > 276 && averege < 462)
  {
    PORTC = number[15];
  }
  if (averege > 492 && averege < 502)
  {
    PORTC = number[0];
  }
  if (averege > 596 && averege < 650)
  {
    PORTC = number[14];
  }
  if (averege > 792 && averege < 808)
  {
    PORTC = number[13];
  }
}
