/*
 Utility.cpp - Arduino Utility library
 Copyright (c) EHbtj<contact at ehbtj.com>.  All right reserved.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 Version 001 17 May 2013
 */

#ifndef Utility_h
#define Utility_h

#include "Arduino.h"

#define PWM_DIV1 1
#define PWM_DIV8 8
#define PWM_DIV32 32
#define PWM_DIV64 64
#define PWM_DIV128 128
#define PWM_DIV256 256
#define PWM_DIV1024 1024

#define ADC_DIV2 2
#define ADC_DIV4 4
#define ADC_DIV8 8
#define ADC_DIV16 16
#define ADC_DIV32 32
#define ADC_DIV64 64
#define ADC_DIV128 128

unsigned long adjustMicros(void);
unsigned long adjustMillis(void);
void adjustDelay(unsigned long ms);
void forPinMode(int pinArray[],unsigned int num, uint8_t mode);
double analogReadVoltage(uint8_t pin, double vref = 5.0);
void setPWMFrequency(uint8_t pin, int divisor);
void setADCFrequency(int divisor);
void i2c_faster(void);
void i2c_default(void);

#endif