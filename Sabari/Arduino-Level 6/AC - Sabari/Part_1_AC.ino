#include <LCD.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define setbit(x,y)(x|=y)
#define clearbit(x,y) (x&=~y)
#define checkbit(x,y)((x) &(y))
// Initialize macros for corresponding buttons on the ir remote
#define powerKey 0x1FE48B7
#define volUp 0x1FE609F
#define volDown 0x1FEA05F
LCD lcd; // create LCD object
// initalize variables
double logR2, R2, T, Tc;
long keycode = 0;
int timervalue = 0;
int bitposition = 0;
int var = 0;
int desiredTemp = 22;
boolean power = false;
int temp = 22;
int var1 = 0;
float c1 = 0.001125308852122;
float c2 = 0.000234711863267;
float c3 = 0.000000085663516;
// Get hexacode value from ir remote
ISR(TIMER0_OVF_vect) {
  var++;
  TCNT0 = 125;

}
ISR(INT2_vect) {
  timervalue = var;
  var = 0;
  bitposition++;
  if (timervalue >= 100) {
    bitposition = -2;
    keycode = 0;
  }
  if ((bitposition >= 0) && (bitposition < 32)) {
    if (timervalue > 3) {
      keycode |= (long)1 << (31 - bitposition);
    }
  }
  else if (bitposition >= 32) {
    bitposition = 0;
    compare();

  }
}

int main(void) {
  lcd.init(); // initalize  lcd
  lcd.cmd(0x0C); // turn off cursor
  DDRD = 0xFF;
  DDRB = 0x00;
  TIMSK0 = 0x01;
  EICRA = 0x20;
  EIMSK = 0x04;
  SREG = 0x80;
  TCCR0A = 0x00;
  TCCR0B = 0x03;
  clearbit(PORTD, bit(7));

  while (true) {
    if (power == true) {
      // ADC conversion for thermistor
      ADMUX = 0x40;
      ADCSRA = 0xC7;
      while (checkbit(ADCSRA, bit(ADSC)));
      R2 = (10000 / (1023 - ADCW)) * ADCW;
      logR2 = log(R2);
      T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
      Tc = T - 273.15;
      // Show Actual temperature
      int TcShow = Tc * 100;
      lcd.string("Actual:  ");
      lcd.showvalue(TcShow);
      lcd.line1(11);
      lcd.string(".");
      // Show desired tempreture
      lcd.line2(0);
      int desiredTempShow = desiredTemp * 100;
      lcd.string("Desired: ");
      lcd.showvalue(desiredTempShow);
      lcd.line2(11);
      lcd.string(".");
      _delay_ms(200);
      lcd.cmd(0x01);
      if (Tc > desiredTemp) { // If actual temp is greater then desired temp(If AC should be turned on)
        setbit(PORTD, bit(7));
      }
      else {
        clearbit(PORTD, bit(7));
      }

    }
    else { // else(power is off) turn off motor and clear lcd display
      clearbit(PORTD, bit(7));  
      lcd.cmd(0x01);


    }
  }
}
void compare() {
  if (keycode == powerKey) {
    if (power == false) { // If power button clicked where AC is off
      power = true;
      _delay_ms(200);
    }
    else { // If power button clicked where AC is oon
      power = false;
      _delay_ms(200);
    }

  }


  if (power == true) {
    if (keycode == volUp) {
      desiredTemp++;
      _delay_ms(200);



    }
    if (keycode == volDown) {
      desiredTemp--;
      _delay_ms(200);
    }

  }


}
