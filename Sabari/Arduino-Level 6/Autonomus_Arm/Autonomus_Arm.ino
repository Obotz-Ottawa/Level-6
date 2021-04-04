#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int c = 0;
int d = 0;
int count = 0;
int count_angle3, count_angle1, count_angle2;,
int main(void) {
  DDRD = 0xFF;
  DDRB = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
while(true) {
  angle1(60);
  angle2(60);
  angle3(60);
  _delay_ms(500);
  angle3(10);
  _delay_ms(500);

  
}
}
void angle(int a) {
  count_angle = a+46;
  
  
}
