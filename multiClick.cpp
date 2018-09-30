#include "multiClick.h"

// Constructor
MultiClick::MultiClick(int pin, int debounce_time, int double_time, int long_time) {
  
  btnPin = pin;
  debunce_ms = debounce_time;
  doublepress_ms = double_time;
  longpress_ms = long_time;

  pinMode(btnPin, INPUT); // declare push button as input
  
  current_time = millis();
  last_time = millis();
  
}

// Methods
void MultiClick::tick() {
  
  current_time = millis();
  now = digitalRead(btnPin);

  // Check if we should execute a single press
  if (clicked == true and current_time - last_up > doublepress_ms) {
    clicked = false;
    single_function();
  }

  // Check if it went up
  if (button1_last != now and now == false) {
    if (clicked == true) {
      clicked = false;
      double_function();
    } else if (long_clicked == false){
      clicked = true;
    }
    long_clicked = false;
    last_up = current_time;
  }

  // Check if still pressed
  if (button1_last == now and now == true) {
    if (current_time - last_up > longpress_ms and current_time - last_up < longpress_ms + 5 and last_up != 0) { // Check for a long click
      last_up = current_time;
      long_clicked = true;
      long_function();
    }
  }

  last_time = current_time;
  button1_last = now;
  
}

void MultiClick::setSingleClickFunction(callbackFunction new_function) {
  single_function = new_function;
}

void MultiClick::setDoubleClickFunction(callbackFunction new_function) {
  double_function = new_function;
}

void MultiClick::setLongClickFunction(callbackFunction new_function) {
  long_function = new_function;
}

