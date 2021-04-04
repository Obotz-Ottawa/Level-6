#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))

int x, y;
int count = 0;
int count_angle1, count_angle2;

void servo1(int a) {
  count_angle1 = a + 46;


}
void servo2(int b) {
  count_angle2 = b + 46;


}

int main(void) {
  DDRB = 0xF0;
  DDRD = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  servo1(10);
  servo2(170);


  while (true) {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
    if (x < 100) {
      servo2(110);
      _delay_ms(100);
    }
    else if (x > 800) {
      servo1(60);
      _delay_ms(100);
    }
    else if (y > 800) {
      servo1(60);
      servo2(110);
      _delay_ms(100);
    }
    else {
      servo1(10);
      servo2(170);
    }



  }
}

ISR(TIMER1_COMPA_vect) {
  count++;
  if (count <= count_angle1) {
    setbit(PORTB, bit(4));
  }
  else if ((count > count_angle1) && (count < 1818)) {
    clearbit(PORTB, bit(4));
  }
  else if (count >= 1818) {
    count = 0;
  }

  if (count <= count_angle2) {
    setbit(PORTB, bit(5));
  }
  else if ((count > count_angle2) && (count < 1818)) {
    clearbit(PORTB, bit(5));
  }
  else if (count >= 1818) {
    count = 0;
  }

}
