# MultiClick
A simple Arduino library that makes it eazy to detect single, double and long clicks.

**OBS!** *This project is under development, more precise the debounce is not implemented yet. Everything else works.* **OBS!**

## Tested hardware
* NodeMCU V1.0 / ESP8266: <i style="color:lightgreen">**Works!**</i>

## How to use
First download and install this library in your IDE and include it in your sketch by typing `#include <multiClick.h>` at the top of the document.

You can then create an object of the MultiClick class with it's constructur that can take four arguments but only the first one (*pin*) is required, the other are optional and have default values (see below list).
```cpp
MultiClick button(int pin, int debounce_t, int double_t, int long_t)
```
* **pin** is the pin of the button that you wanna use (required)
* **debounce_t** is the button debounce time in ms, *default 20* (optional)
* **double_t** is the max time between two clicks that should register as a double click, in ms, *default 250* (optional)
* **long_t** is the minimum time from that a button is pressed down to that a long press action is fired, in ms, *default 1600* (optional)

There are tree functions that let's you set your callback function for when the different events are created, `.setSingleClickFunction`, `.setDoubleClickFunction` and `.setLongClickFunction`. They all take a function as a argument.

At last. The `.tick()` method needs to be run inside you main loop. Be aware tho, for the best performance, you should not use any delay/sleep methods in your loop as this will make the buttons feel more unresponsive.

## Example
```cpp
#include <multiClick.h>

MultiClick button(12);

void setup() {
  Serial.begin(9600);
  button.setSingleClickFunction(singleclick);
  button.setDoubleClickFunction(doubleclick);
  button.setLongClickFunction(longclick);
}

void singleclick() {
  Serial.println("Single click just happend");
}
void doubleclick() {
  Serial.println("Double click just happend");
}
void longclick() {
  Serial.println("Long click just happend");
}

void loop() {
   button.tick();
   delay(10);
}
```
Now open your serial monitor at baudrate 9600 and click the button you have connected to pin 12!