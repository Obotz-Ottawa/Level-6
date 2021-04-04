#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define key1 0x01FE50AF
#define key2 0x01FED827
#define key3 0x01FEF807
#define key4 0x01FE30CF
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
long keycode = 0;
int timervalue = 0;
int bitposition = 0; 
int var = 0;
int c = 0;
int d = 0;
int angle1;
int count = 0;
int count_angle1 = 0;
int count_angle2 = 0;
int count_angle3 = 0;
int x = 0;
int y = 0;
void servo1(int a) {
  count_angle1 = a + 46;


}
void servo2(int b) {
  count_angle2 = b + 46;


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

ISR(TIMER0_OVF_vect) {
  var++;
  TCNT0 = 125;
  
}
ISR(INT2_vect) {
  timervalue = var;
  var = 0;
  bitposition++;
  if(timervalue>=100) {
    bitposition = -2;
    keycode = 0;
  }
  if((bitposition>=0) && (bitposition<32)) {
    if(timervalue>3) {
      keycode |=(long)1<<(31-bitposition);
    }
  }
  else if(bitposition>=32) {
    bitposition = 0;
    compare();
  }
}

 
int main(void) {
  
  DDRB = 0xF0;
  DDRD = 0xFF;
  TIMSK0 = 0x01;
  EICRA = 0x20;
  EIMSK = 0x04;    
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03; 
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02; 
  Serial.begin(2000000);           
  

while(true) {
  
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
void compare () {
  if(keycode==key1) {
  
   
    x-= 10;
    servo2(x);
    _delay_ms(50);
    
  }
  if(keycode==key2) {
   
    x+= 10;
    servo2(x);
    _delay_ms(50);
  }
   if(keycode==key3) {
   
    y+= 10;
    servo1(y);
    _delay_ms(50);
  }
   if(keycode==key4) {
   
    y-= 10;
    servo1(y);
    _delay_ms(50);
  }
  
}
