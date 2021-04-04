#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))

int c, d, x, y;
int p = 60, q = 60, r = 60;
int count = 0;
int btn = 0;
int count_angle1, count_angle2, count_angle3;

void servo1(int a) {
  count_angle1 = a + 46;


}
void servo2(int b) {
  count_angle2 = b + 46;


}
void servo3(int e) {
  count_angle3 = e + 46;


}
void antistepper() {
  if (c == 1) {
    PORTD = 0b11100000;
  }
  if (c == 2) {
    PORTD = 0b11010000;
  }
  if (c == 3) {
    PORTD = 0b10110000;
  }
  if (c == 4) {
    PORTD = 0b01110000;
    c = 0;
  }
}
void clkstepper() {
  if (d == 1) {
    PORTD = 0b01110000;
  }
  if (d == 2) {
    PORTD = 0b10110000;
  }
  if (d == 3) {
    PORTD = 0b11010000;
  }
  if (d == 4) {
    PORTD = 0b11100000;
    d = 0;
  }
}

int main(void) {
  DDRB = 0xF0;
  DDRD = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  servo1(60);
  servo2(60);
  servo3(60);


  while (true) {
    ADMUX = 0x42;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int y = ADCW;
    ADMUX = 0x43;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    int x = ADCW;
    if (y < 100) {
      p++;
      q--;
      servo1(p);
      servo2(q);
      _delay_ms(50);
    }
    if (y > 900) {
      p--;
      q++;
      servo1(p);
      servo2(q);
      _delay_ms(50);
    }
    if (checkbit(PINB, bit(0))) {
      btn++;
      _delay_ms(300);

    }
    if (btn == 1) {
      servo3(0);
    }
    if (btn == 2) {
      servo3(30);
      btn = 0;
    }
    if (x < 100) {
      c++;
      antistepper();
      _delay_ms(50);
    }
    if (x > 900) {
      d++;
      clkstepper();
      _delay_ms(50);
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

  if (count <= count_angle3) {
    setbit(PORTB, bit(6));
  }
  else if ((count > count_angle3) && (count < 1818)) {
    clearbit(PORTB, bit(6));
  }
  else if (count >= 1818) {
    count = 0;
  }
}
