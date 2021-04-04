#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int c = 0;
int d = 0;
int angle1;
int count = 0;
int count_angle1 = 0;
int count_angle2 = 0;
int count_angle3 = 0;
int main(void) {
  DDRB = 0x0F;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while (true) {
    servo1(90);
    servo2(90);
    servo3(0);
    
    while (!(checkbit(PINB, bit(0))));
    servo1(20);
    _delay_ms(200);
    while (!(checkbit(PINB, bit(0))));
    servo1(160);
    servo2(0);
    _delay_ms(200);
    while (!(checkbit(PINB, bit(0))));
    servo2(90);
    _delay_ms(200);
  /*
    while (!(checkbit(PINB, bit(0))));
    servo2(0);
    _delay_ms(30);
    while (!(checkbit(PINB, bit(0))));
    servo2(50);
    _delay_ms(30);
    while (!(checkbit(PINB, bit(0))));
    servo2(90);
    _delay_ms(30);

    while (!(checkbit(PINB, bit(0))));
    servo3(0);
    _delay_ms(30);
    while (!(checkbit(PINB, bit(0))));
    servo3(180);
    _delay_ms(30);
    while (!(checkbit(PINB, bit(0))));
    servo3(90);
    _delay_ms(30);



    
      for (int i = 0; i < 12; i++) {
      c++;
      antistepper();
      _delay_ms(50);
      }
      _delay_ms(500);
      servo3(60);
      _delay_ms(500);
      for (int i = 0; i < 12; i++) {
      d++;
      clkstepper();
      _delay_ms(50);
      }
      _delay_ms(500);
    */
  }
}
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
