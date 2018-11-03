// This will blink pin 13 1 time for one second then 2 times for 2 seconds, on until 5 seconds, then repeat
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void delay_ms(uint16_t count) {
  while(count--) {
    _delay_ms(1);
  }
}


int main(int argc, char* argv[]) {
    while(1) {
 
    int delay = 0; 
    DDRB |= ((1 << DDB5));
     
    for(delay = 1000; delay < 6000; delay += 500) {
       PORTB ^= (( 1 << PB5)); 
       delay_ms(delay);
    }
  }
     return 0;
}
