#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
int numbers[10] = {0xF6,0x60,0xD5,0xF1, 0x63,0xB3,0xB7,0xE0,0xF7,0xF3};


int main(void) {
  DDRC = 0xFF;

  while (true) {
    for(int i = 0;i<10;i++) {
      PORTC = numbers[i];
      _delay_ms(500);
    }
  }
}
