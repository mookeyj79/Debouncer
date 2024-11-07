#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <Arduino.h>

class Debouncer {
  private:
    struct DebouncePin {
      int pin;
      bool lastState;
      bool lastReading;
      unsigned long lastDebounceTime;
    };

    DebouncePin* pins;       // Pointer to dynamically allocated array
    int maxPins;             // Maximum number of pins, set during initialization
    int debounceDelay = 50;  // Debounce delay in milliseconds

  public:
    Debouncer(int maxPins);
    ~Debouncer();
    void setDebounceDelay(int delay);
    bool addPin(int pin, int mode=INPUT_PULLUP);
    bool removePin(int pin);
    void update();
    bool getState(int pin);
};

#endif  // DEBOUNCER_H