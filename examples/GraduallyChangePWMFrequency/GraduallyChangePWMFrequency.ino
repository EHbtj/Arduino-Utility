#include <Utility.h>

int pin = 5;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  setPWMFrequency(pin, PWM_DIV1);
  analogWrite(pin, 127);
  adjustDelay(5000);
  
  setPWMFrequency(pin, PWM_DIV8);
  analogWrite(pin, 127);
  adjustDelay(5000);
  
  if (pin == 3 || pin == 11) {
    setPWMFrequency(pin, PWM_DIV32);
    analogWrite(pin, 127);
    adjustDelay(5000);
  }
  
  setPWMFrequency(pin, PWM_DIV64);
  analogWrite(pin, 127);
  adjustDelay(5000);
  
  if (pin == 3 || pin == 11) {
    setPWMFrequency(pin, PWM_DIV128);
    analogWrite(pin, 127);
    adjustDelay(5000);
  }
  
  setPWMFrequency(pin, PWM_DIV256);
  analogWrite(pin, 127);
  adjustDelay(5000);
  
  setPWMFrequency(pin, PWM_DIV1024);
  analogWrite(pin, 127);
  adjustDelay(5000);
}
