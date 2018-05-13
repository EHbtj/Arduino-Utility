/*
 Utility.cpp - Arduino Utility library
 Copyright (c) EHbtj<contact at ehbtj.com>.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 Version 001 17 May 2013
 */

#include "Utility.h"

int division = 0x03;


void i2c_faster(void) {
	TWBR = 12;
}

void i2c_default(void) {
	TWBR = 72;
}

void setPWMFrequency(uint8_t pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
			division = mode;
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void setADCFrequency(int divisor) {
	ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
	switch (divisor) {
		case 2: ADCSRA |= (1 << ADPS0); break;
		case 4: ADCSRA |= (1 << ADPS1); break;
		case 8: ADCSRA |= (1 << ADPS1) | (1 << ADPS0); break;
		case 16: ADCSRA |= (1 << ADPS2); break;
		case 32: ADCSRA |= (1 << ADPS2) | (1 << ADPS0); break;
		case 64: ADCSRA |= (1 << ADPS2) | (1 << ADPS1); break;
		default: ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); break;
	}
}

void forPinMode(int pinArray[], unsigned int num, uint8_t mode) {
	for (int i = 0; i < num;i++) {
		pinMode(pinArray[i], mode);
	}
}

double analogReadVoltage(uint8_t pin, double vref) {	// the 2nd parameter is option
	double val = analogRead(pin);
	if (bit_is_set(ADMUX, 7) && bit_is_set(ADMUX, 6)) {
		return val * 1.1 * 1000 / 1024;			// INTERNAL(0x03) -> 1.1V
	} else {															// DEFAULT(0x01) or EXTERNAL(0x00)
		return val * vref * 1000 / 1024;		
	}
}

unsigned long adjustMicros(void) {
  unsigned long m = micros();
	switch (division) {
		case 1: return m >> 6;
		case 2: return m >> 3;
		case 4: return m << 2;
		case 5: return m << 4;
		default: return m;
	}
}


unsigned long adjustMillis(void) {
  unsigned long m = millis();
	switch (division) {
		case 1: return m >> 6;
		case 2: return m >> 3;
		case 4: return m << 2;
		case 5: return m << 4;
		default: return m;
	}
}

void adjustDelay(unsigned long ms) {
  unsigned long end = adjustMillis() + ms;
  while (adjustMillis() < end);
}