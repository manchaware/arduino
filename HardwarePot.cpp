/*
 * HardwareButton.h
 * 26 March 2016 - Adrian Ortiz
 * Based on Arduino Smoothing tutorial https://www.arduino.cc/en/Tutorial/Smoothing
 *
 * Will only "fire" if pot value has changed. This is useful if you need to
 * continuously send pot values to another device such as bluetooth device
 */

#include "HardwarePot.h"

HardwarePot::HardwarePot(int potPin) {
  pin = potPin;
  for (int thisReading = 0; thisReading < SAMPLE_SIZE; thisReading++) {
    readings[thisReading] = 0;
  }
}

HardwarePot::HardwarePot() {
}

bool HardwarePot::changed() {
  total = total - readings[readIndex];

  readings[readIndex] = analogRead(pin);
  total = total + readings[readIndex];

  readIndex = readIndex + 1;

  if (readIndex >= SAMPLE_SIZE) {
    readIndex = 0;
  }

  value = total / SAMPLE_SIZE;

  if (abs(lastVal - value) > THRESHOLD) {
    lastVal = value;
    return true;
  }

  return false;
}
