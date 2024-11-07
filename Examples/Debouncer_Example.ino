#include "Debouncer.h"

// Define buttons and LED pins
#define BUTTON_1 2
#define BUTTON_2 3
#define LED_1 12
#define LED_2 13

// Define Debouncer instance with how many
// inputs you want to 'debounce'
Debouncer debouncer(2);

void setup() {
  // Setup LED pins
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  // Setup Debouncer pins
  // Both 'INPUT' and 'INPUT_PULLUP' supported
  // See that we only defined 2 pins above
  debouncer.addPin(BUTTON_1, INPUT);
  debouncer.addPin(BUTTON_2, INPUT_PULLUP);

  // Turn off the LEDs by default
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
}

void loop() {
  // Poll the latest state of the 'debounced' pins
  debouncer.update();

  // Get the current state of the button
  // Assume the button is connected to a pulldown resister
  if (debouncer.getState(BUTTON_1)) {
    digitalWrite(LED_1, HIGH);
  }
  else {
    digitalWrite(LED_1, LOW);
  }


  // If the 'INPUT_PULLUP' button goes 'LOW'
  if (!debouncer.getState(BUTTON_2)) {
    digitalWrite(LED_2, HIGH);
  }
  else {
    digitalWrite(LED_2, LOW);
  }
}
