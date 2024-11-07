#include "Debouncer.h"

Debouncer::Debouncer(int maxPins) {
  this->maxPins = maxPins;
  pins = new DebouncePin[maxPins];  // Allocate memory for pins array

  // Initialize all entries to an invalid pin number
  for (int i = 0; i < maxPins; i++) {
    pins[i].pin = -1;
  }
}

Debouncer::~Debouncer() {
  delete[] pins;  // Free allocated memory
}

void Debouncer::setDebounceDelay(int delay) {
  debounceDelay = delay;
}

bool Debouncer::addPin(int pin, int mode) {
  for (int i = 0; i < maxPins; i++) {

    // Find an empty slot
    if (pins[i].pin == -1) {
      pins[i].pin = pin;
      pinMode(pin, mode);
      pins[i].lastState = digitalRead(pin);
      pins[i].lastReading = pins[i].lastState;
      pins[i].lastDebounceTime = 0;
      return true;
    }
  }
  return false;  // No slots available
}

bool Debouncer::removePin(int pin) {
  for (int i = 0; i < maxPins; i++) {
    if (pins[i].pin == pin) {
      pins[i].pin = -1;  // Mark pin as unused
      return true;
    }
  }
  return false;  // Pin not found
}

void Debouncer::update() {
  unsigned long currentTime = millis();

  for (int i = 0; i < maxPins; i++) {
    if (pins[i].pin == -1) continue;  // Skip unused slots

    bool currentReading = digitalRead(pins[i].pin);

    if (currentReading != pins[i].lastReading) {
      pins[i].lastDebounceTime = currentTime;
    }

    if ((currentTime - pins[i].lastDebounceTime) > debounceDelay) {
      if (currentReading != pins[i].lastState) {
        pins[i].lastState = currentReading;
      }
    }
    pins[i].lastReading = currentReading;
  }
}

bool Debouncer::getState(int pin) {
  for (int i = 0; i < maxPins; i++) {
    if (pins[i].pin == pin) {
      return pins[i].lastState;
    }
  }
  return HIGH;
}
