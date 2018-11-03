#include <avr/io.h>
#include <util/delay.h>
 
enum {
 BLINK_DELAY_MS = 10000,
};
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 DDRB |= _BV(DDB5);
 
 while(1) {
  /* set pin 1 high to turn led on */
  PORTB |= _BV(PORTB1);
  _delay_ms(BLINK_DELAY_MS);
 
  /* set pin 1 low to turn led off */
  PORTB &= ~_BV(PORTB1);
  _delay_ms(BLINK_DELAY_MS);
 }
 
 return 0;
}
