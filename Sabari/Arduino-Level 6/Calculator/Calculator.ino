#include <LCD.h>
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
int i;
long result, average;
String a = "";
String b = "";
String userOperation = "";
boolean operation = false;
void getAnswer() {
  if(userOperation=="addition") {
    Serial.print('\n');
    Serial.print(a.toInt() + b.toInt());
  }
  if(userOperation=="subtraction") {
    Serial.print('\n');
    Serial.print(a.toInt() - b.toInt());
  }
  if(userOperation=="multiplication") {
    Serial.print('\n');
    Serial.print(a.toInt() * b.toInt());
  }
  if(userOperation=="division") {
    Serial.print('\n');
    Serial.print(a.toInt() / b.toInt());
  }
  a = "";
  b = "";
  operation = false;
  userOperation = "";
}
void clearCalculator() {
 
  
}
int main(void) {
  Serial.begin(2000000);
  while (true) {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bit(ADSC)));
    result = result + ADCW;
    i++;
    if (i > 99) {
      average = result / 100;
      compare();
      _delay_ms(200);
      result = 0;
      average = 0;
      i = 0;
    }
  }
}

void compare() {
  if (average >= 592 && average <= 594) {
    if (operation == false) {
      if (a.length() != 0) {
        a += "0";
        Serial.print("0");
      }

    }
    else {
      if (b.length() != 0) {
        b += "0";
        Serial.print("0");

      }

    }

  }
  if (average >= 515 && average <= 519) {
    if (operation == false) {
      a += "1";
    }
    else {
      b += "1";
    }
    Serial.print("1");
  }
  if (average >= 692 && average <= 693) {
    if (operation == false) {
      a += "2";
    }
    else {
      b += "2";
    }
    Serial.print("2");
  }
  if (average >= 743 && average <= 751) {
    if (operation == false) {
      a += "3";
    }
    else {
      b += "3";
    }
    Serial.print("3");
  }

  if (average >= 486 && average <= 489) {
    if (operation == false) {
      a += "4";
    }
    else {
      b += "4";
    }
    Serial.print("4");
  }
  if (average >= 639 && average <= 640) {
    if (operation == false) {
      a += "5";
    }
    else {
      b += "5";
    }
    Serial.print("5");
  }
  if (average >= 682 && average <= 687) {
    if (operation == false) {
      a += "6";
    }
    else {
      b += "6";
    }
    Serial.print("6");
  }
  if (average >= 470 && average <= 473) {
    if (operation == false) {
      a += "7";
    }
    else {
      b += "7";
    }
    Serial.print("7");
  }
  if (average >= 613 && average <= 614)  {
    if (operation == false) {
      a += "8";
    }
    else {
      b += "8";
    }
    Serial.print("8");
  }
  if (average >= 652 && average <= 656) {
    if (operation == false) {
      a += "9";
    }
    else {
      b += "9";
    }
    Serial.print("9");
  }
  if (average >= 1010 && average <= 1020) {
    userOperation = "addition";
    operation = true;
    Serial.print(" + ");

  }
  if (average >= 907 && average <= 908) {
    userOperation = "subtraction";
    operation = true;
    Serial.print(" - ");

  }
  if (average >= 854 && average <= 856) {
    userOperation = "multiplication";
    operation = true;
    Serial.print(" * ");

  }
  if (average >= 816 && average <= 818) {
    userOperation = "division";
    operation = true;
    Serial.print(" / ");

  }
  if (average >= 629 && average <= 633) {
    if(a.length()!=0 && b.length()) {
      getAnswer();
    }
  

  }
  if (average >= 458 && average <= 460) {
    clearCalculator();
    
    

  }
}
