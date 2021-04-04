#include<avr/io.h>
#include<util/delay.h>
#include<LCD.h>
#define checkbit(x,y)((x) & (y))
#define bitn(p)(0x01 << (p))
LCD lcd;
int main(void) {
  Serial.begin(2000000);
  lcd.init();
  lcd.cmd(0x01);
  lcd.line1(0);

  while (true) {
    lcd.string("1");
    Serial.println("1");
    _delay_ms(500);
  }
}
