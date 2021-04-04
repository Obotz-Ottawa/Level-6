#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int count;
int count_angle
int main(void) {
  
  DDRD = 0xFF;
  DDRC = 0xFF;
  Serial.begin(2000000);
  while (true) {
 
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
   angle(0);
   _delay_ms(500);
   angle(90);
   _delay_ms(500);
    



  }
}
void angle(int a) {
  count_angle = a+46;
  
  
}
ISR(TIMER1_COMPA_vect) {
  count++;
  if (count <= count_angle) {
    setbit(PORTB, bit(4));
  }
  else if ((count > count_angle) && (count < 1818)) {
    clearbit(PORTB, bit(4));
  }
  else if (count >= 1818) {
    count = 0;
  }
