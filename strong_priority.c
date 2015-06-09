/* This is an attempt to implement a hard priority system for interacting with a microcontroller
 * learning about using interrupts with atmega328p (arduino uno)
 * */
//#include <strong_priority.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

short RED_PIN, YELLOW_PIN, GREEN_PIN, BUZZER_PIN;
const int DELAY_TIME = 300;
bool interrupted;

enum LEDS {RED,YELLOW,GREEN};
void setup(){
    interrupted = false;
    RED_PIN = PB3; YELLOW_PIN = PB2; GREEN_PIN = PB1; BUZZER_PIN = PB4;
    // set thee following ports to output
    DDRB |= _BV(RED_PIN);
    DDRB |= _BV(YELLOW_PIN); 
    DDRB |= _BV(GREEN_PIN); 
    DDRB |= _BV(BUZZER_PIN);
    //set pot as input
    DDRD &= ~(1 << PD2); 
}

void flipSwitch() {
    //read pot input
    //if potInput > 2.5V set interrupted to true
    if(PIND & (1<<PD2)) {
        interrupted = true;
    }
}

void soundBuzzer() {
    PORTB |= _BV(PORTB4);
    _delay_ms(DELAY_TIME);
    PORTB &= ~_BV(PORTB4);
    _delay_ms(DELAY_TIME); 
};


void blinkRedLED() {
    PORTB |= _BV(PORTB3);
    _delay_ms(DELAY_TIME);
    PORTB &= ~_BV(PORTB3);
    _delay_ms(DELAY_TIME);
}

void blinkYelloLED() {
    PORTB |= _BV(PORTB2);
    _delay_ms(DELAY_TIME);
    PORTB &= ~_BV(PORTB2);
    _delay_ms(DELAY_TIME);
}

void  blinkGreenLED() {
    PORTB |= _BV(PORTB1);
    _delay_ms(DELAY_TIME);
    PORTB &= ~_BV(PORTB1);
    _delay_ms(DELAY_TIME);
}

void blinkLED(enum LEDS led){
    switch (led){
        case RED:
            blinkRedLED();
            break;
        case YELLOW:
            blinkYelloLED();
            break;
        case GREEN:
            blinkGreenLED();
            break;
    }
    PORTB |= _BV(PORTB5);
}


void runScheduler(){
    while(!interrupted) {
        blinkLED(RED);
        blinkLED(YELLOW);
        blinkLED(GREEN);
        //soundBuzzer();
    }
    soundBuzzer();
    _delay_ms(DELAY_TIME);
}

int main(){
    setup();
    runScheduler();
    return 0;
}
