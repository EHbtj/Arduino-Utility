// This sketch does not work in this state.
// Unless otherwise noted, all frequencies are in Hz and assume a 16MHz system clock.

// include the Utility library:
#include <Utility.h>

 ---------- Change PMW Frequency ---------- 
  // ex.
  setPWMFrequency(11, PWM_DIV32);

         Pins 5 and 6                  Pins 9 and 10                  Pins 3 and 11
    Divisor   |  Frequency        Divisor   |   Frequency        Divisor   |   Frequency
 -------------+--------------  -------------+---------------  -------------+---------------
  PWM_DIV1    |  62500          PWM_DIV1    |  31250           PWM_DIV1    |  31250
  PWM_DIV8    |  7812.5         PWM_DIV8    |  3906.25         PWM_DIV8    |  3906.25
  PWM_DIV64   |  976.5625       PWM_DIV64   |  488.28125       PWM_DIV32   |  976.5625
  PWM_DIV256  |  244.140625     PWM_DIV256  |  122.0703125     PWM_DIV64   |  488.28125
  PWM_DIV1024 |  61.03515625    PWM_DIV1024 |  30.517578125    PWM_DIV128  |  244.140625
                                                               PWM_DIV256  |  122.0703125
                                                               PWM_DIV1024 |  30.517578125
   
  // analogWrite() of all PWM pins are set to PWM_DIV64 by default.
  // Changing the prescale factor on Timer0 (Pins 5 and 6) will affect functions
        millis(), micros(), delay(), delayMicroseconds(), ...
  // To adjust millis() and delay() you can use these functions:
        adjustMillis(), adjustDelay()
  
   
 ---------- Change ADC Frequency ---------- 
  // ex.
  setADCFrequency(ADC_DIV4);

    Divisor   |  Frequency(kHz)
  ------------+------------------
   ADC_DIV2   |      8000
   ADC_DIV4   |      4000
   ADC_DIV8   |      2000
   ADC_DIV16  |      1000
   ADC_DIV32  |      500
   ADC_DIV64  |      250
   ADC_DIV128 |      125
   // analogRead() of all ADC pins use a prescale factor which is set to 128 by default.
   // Caution : Accuracy is less at higher frequencies.


 ---------- Repeatedly executing the pinMode() ----------
  int pin[5] = {2, 3, 4, 5, 6};
 
  forPinMode(pin, 5, OUTPUT);
 
  // work of the same
  for (int i = 0;i < 5;i++) {
    pinMode(pin[i], OUTPUT);
  }
 
 
 ---------- The analogRead() that returns a voltage value ----------
  // ex.
  double val = analogReadVoltage(A0);
  
  // analogReadVlotage() returns a double value (ex. 0 ~ 5000[mV])
  // If argument of analogReferece() has "EXTERNAL", "INTERNAL1V1" or "INTERNAL2V56"
  // writing the 2nd parameter of the function is required.


 ---------- Change I2C Frequency ---------- 
  // call after Wire.begin()
  // I2C 400kHz Mode:
  i2c_faster();
  
  // I2C 100kHz Mode (default):
  i2c_default();


 ---------- Appendix : Port Manipulation ---------- 
 
 DDRD |= 0b11111100;   // pins 2 to 7 as outputs
 
 PORTD = 0b10101000;   // sets digital pins 7,5,3 HIGH and 6, 4, 2, 1, 0 LOW
 
 PORTD |= 0b10101000;  // this is safer as it sets digital pins 7,5,3 HIGH
 PORTD |= _BV(7) | _BV(5) | _BV(3);
 
 PORTD &= ~b01010000; // this is safer as it sets digital pins 6, 4 LOW
 PORTD &= ~(_BV(6) | _BV(4));
 
 val = PIND & _BV(2)  // read the input pin (return HIGH or LOW)

  PORTD maps to Arduino digital pins 0 to 7
//     DDRD - The Port D Data Direction Register - read/write
//     PORTD - The Port D Data Register - read/write
//     PIND - The Port D Input Pins Register - read only

  PORTB maps to Arduino digital pins 8 to 13 
// (The two high bits (6 & 7) map to the crystal pins and are not usable.)
//     DDRB - The Port B Data Direction Register - read/write
//     PORTB - The Port B Data Register - read/write
//     PINB - The Port B Input Pins Register - read only

  PORTC maps to Arduino analog pins 0 to 5
// (Pins 6 & 7 are only accessible on enabled devices. (Arduino Mini etc.))
//     DDRC - The Port C Data Direction Register - read/write
//     PORTC - The Port C Data Register - read/write
//     PINC - The Port C Input Pins Register - read only
