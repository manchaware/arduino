/*
 * HardwareButton.h
 * 26 March 2016 - Adrian Ortiz
 * Based on Arduino Smoothing tutorial https://www.arduino.cc/en/Tutorial/Smoothing
 *
 * Will only "fire" if pot value has changed. This is useful if you need to
 * continuously send pot values to another device such as bluetooth device
 */

#include <Arduino.h>

#ifndef HardwarePot_h
#define HardwarePot_h

#define HARDWARE_POT_SAMPLE_SIZE 10
#define HARDWARE_POT_THRESHOLD 1

class HardwarePot {
  public:
    HardwarePot(int potPin);
    HardwarePot();
    bool changed();

    int value;

  private:
    int pin;
    int lastVal;

    int readings[10];
    int readIndex = 0;              // the index of the current reading
    int total = 0;                  // the running total
    int average = 0;
};

#endif
