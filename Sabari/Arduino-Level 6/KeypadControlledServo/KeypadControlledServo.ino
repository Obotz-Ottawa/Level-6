
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int i, data, count, count_angle1, angle, attempt;
long result, average;
String password = "1244";
String userPassword = "";
String closePassword = "AAAA";
int numbers[14] = {0xF6, 0x60, 0xD5, 0xF1, 0x63, 0xB3, 0xB7, 0xE0, 0xF7, 0xF3, 0xE7, 0x96, 0x67, 0xFF};
boolean servoCheck = false;
void servo1(int a) {
  count_angle1 = a + 46;
}
void servoOpen() {
  PORTD = 0x02;
  for (int x = 15; x <= 90; x+=15) {
    servo1(x);
    _delay_ms(200);
  }
  servoCheck == true;
}
void servoClose() {
  for (int x = 90; x <= 15; x-=15) {
    servo1(x);
    _delay_ms(200);
  }
  servoCheck == false;
}
int main(void) {
  DDRB = 0xFF;
  DDRD = 0xFF;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  while (true) {
    if (attempt == 3) {
      while (true) {
        PORTD = 0x01;
        _delay_ms(250);
        PORTD = 0x00;
        _delay_ms(250);
      }
    }
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    result = result + ADCW;
    i++;
    if (i > 99) {
      average = result / 100;
      compare();
      _delay_ms(150);
      if (userPassword.length() == 4) {
        if (userPassword == password) {
          servoOpen();
        }
        else if (userPassword == closePassword && servoCheck == true ) {
          servoClose();
        }
        else {
          attempt++;
          PORTD = 0x01;
          _delay_ms(300);
          PORTD = 0x00;
        }
        userPassword = "";
      }
      result = 0;
      average = 0;
      i = 0;
    }
  }
}

void compare() {
  PORTC = 0x00;
  _delay_ms(20);
  if (servoCheck == true && average != 0) {
    servoClose();
  }
  else {
    if (average >= 592 && average <= 594) {
      userPassword += "0";
      PORTC = numbers[0];
    }
    if (average >= 515 && average <= 519) {
      userPassword += "1";
      PORTC = numbers[1];
    }
    if (average >= 692 && average <= 693) {
      userPassword += "2";
      PORTC = numbers[2];
    }
    if (average >= 746 && average <= 751) {
      userPassword += "3";
      PORTC = numbers[3];
    }
    if (average >= 486 && average <= 489) {
      userPassword += "4";
      PORTC = numbers[4];
    }
    if (average >= 639 && average <= 640) {
      userPassword += "5";
      PORTC = numbers[5];
    }
    if (average >= 685 && average <= 687) {
      userPassword += "6";
      PORTC = numbers[6];
    }
    if (average >= 470 && average <= 473) {
      userPassword += "7";
      PORTC = numbers[7];
    }
    if (average >= 613 && average <= 614)  {
      userPassword += "8";
      PORTC = numbers[8];
    }
    if (average >= 654 && average <= 656) {
      userPassword += "9";
      PORTC = numbers[9];
    }
    if (average >= 1010 && average <= 1020) {
      userPassword += "A";
      PORTC = numbers[10];
    }
    if (average >= 907 && average <= 908) {
      userPassword += "B";
      PORTC = numbers[8];
    }
    if (average >= 854 && average <= 856) {
      userPassword += "C";
      PORTC = numbers[11];
    }
    if (average >= 816 && average <= 818) {
      userPassword += "D";
      PORTC = numbers[0];
    }
    if (average >= 631 && average <= 633) {
      userPassword += "#";
      PORTC = numbers[12];
    }
    if (average >= 458 && average <= 460) {
      userPassword += "*";
      PORTC = numbers[13];
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
}
