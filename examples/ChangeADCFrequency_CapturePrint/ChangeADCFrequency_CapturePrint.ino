#include <Utility.h>

unsigned long start_times[100];
unsigned long stop_times[100];
unsigned long values[100];

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("*ADC_DIV2*");
  adc_capture_print(ADC_DIV2);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV4*");
  adc_capture_print(ADC_DIV4);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV8*");
  adc_capture_print(ADC_DIV8);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV16*");
  adc_capture_print(ADC_DIV16);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV32*");
  adc_capture_print(ADC_DIV32);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV64*");
  adc_capture_print(ADC_DIV64);
  delay(3000);
  
  Serial.println("\n\n*ADC_DIV128*");
  adc_capture_print(ADC_DIV128);
  delay(3000);
}

void adc_capture_print (int divisor) {
  setADCFrequency(divisor);
  // capture the values to memory
  for(int i = 0;i < 100;i++) {
    start_times[i] = micros();
    values[i] = analogRead(0);
    stop_times[i] = micros();
  }
  // print out the results
  Serial.println("--- Results ---"); 
  for(int i = 0;i < 100;i++) {
    Serial.print(values[i]);
    Serial.print(" elapse = ");
    Serial.print(stop_times[i] - start_times[i]);
    Serial.print(" us\n");
  }
}
