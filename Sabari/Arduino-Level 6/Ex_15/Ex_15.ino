#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int count = 0;
int count_angle = 0;
int main(void) {
  Serial.begin(2000000);
  while(true) {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bit(ADSC)));
    int y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
    Serial.println(x);
    _delay_ms(1000);

    

    
  }
}
void angle(int a) {
  count_angle = a + 46;


}

ISR(TIMER1_COMPA_vect) {
  count++;
  if (count <= count_angle) {
    setbit(PORTA, bit(0));
  }
  else if ((count > count_angle) && (count < 1818)) {
    clearbit(PORTA, bit(0));
  }
  else if (count >= 1818) {
    count = 0;
  }
}
