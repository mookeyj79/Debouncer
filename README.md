# Debouncer
Simple, yet flexible 'Debouncer' library for Arduino

## Usage
| Command                                     | Description                                                                                                       | Default |
|---------------------------------------------|-------------------------------------------------------------------------------------------------------------------|---------|
|            Debouncer(int maxPins)           | Constructor that sets the amount of pins you want 'debouncing' for.                                               |         |
|                  ~Debouncer                 | De-constructor that deletes the pin array.                                                                        |         |
|    Debouncer.setDebounceDelay(int delay)    | Sets a custom 'debounce' delay in milliseconds.                                                                   | 50      |
| Debouncer.addPin(int pin, int mode) => bool | Adds a pin to 'debounce' with the output mode. Returns 'True' if successful. **MUST HAVE ROOM IN THE PIN ARRAY!** |         |
|       Debouncer.removePin(int pin) =>       | Removes a pin from the pin array. Returns 'True' if successful.                                                   |         |
|              Debouncer.update()             | Updates the current state of the pins.                                                                            |         |
|     Debouncer.getState(int pin) => bool     | Returns a boolean value representing the current state of the given pin.                                          |         |

## Examples
Please see the [Examples](https://github.com/mookeyj79/Debouncer/tree/main/Examples) directory for a quick and easy demo.
