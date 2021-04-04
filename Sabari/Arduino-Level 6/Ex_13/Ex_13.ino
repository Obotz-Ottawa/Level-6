#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define key1 0x01FE50AF
#define key2 0x01FED827
#define key3 0x01FEF807
long keycode = 0;
int timervalue = 0;
int bitposition = 0; 
int var = 0;

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
  
  DDRB = 0x00;
  DDRD = 0x0F;
  TIMSK0 = 0x01;
  EICRA = 0x20;
  EIMSK = 0x04;    
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03;  
  Serial.begin(2000000);           
  

while(true) {
  
}
}
void compare () {
  if(keycode==key1) {
    PORTD = 0x04;
    
  }
  if(keycode==key2) {
    PORTD = 0x08;
  }
  if(keycode==key3) {
    PORTD = 0x0C;
  
}
}
