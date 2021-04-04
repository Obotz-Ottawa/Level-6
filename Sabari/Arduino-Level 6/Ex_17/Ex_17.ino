#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int c = 0;
int d = 0;

int count = 0;
int count_angle = 0;

int main(void) {
  DDRB = 0xFF;
  DDRD = 0xFF;
  DDRC = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  Serial.begin(2000000);
  angle(0);
  while (true) {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bit(ADSC)));
    int y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while(checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
    Serial.println(x);
    while (y >= 900) {
     
      ADMUX = 0x42;
      ADCSRA = 0xC7;
      while (checkbit(ADCSRA, bit(ADSC)));
      y = ADCW;
      angle(c);
      _delay_ms(300);
      if(c== 90) {
        
      }
      else {
        c+= 10;
        
      }
      

    }
    while (y <= 10) {
     
      ADMUX = 0x42;
      ADCSRA = 0xC7;
      while (checkbit(ADCSRA, bit(ADSC)));
      y = ADCW;
      angle(c);
      _delay_ms(300);
      c-= 10;
      Serial.println(c);

    }


  }
}
void angle(int a) {
  count_angle = a + 46;


}

ISR(TIMER1_COMPA_vect) {
  count++;
  if (count <= count_angle) {
    setbit(PORTB, bit(0));
  }
  else if ((count > count_angle) && (count < 1818)) {
    clearbit(PORTB, bit(0));
  }
  else if (count >= 1818) {
    count = 0;
  }
}
