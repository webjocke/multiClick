#include <multiClick.h>

// Init button object
MultiClick button1(12);

void setup() {
  Serial.begin(9600);

  button1.setSingleClickFunction(singleclick);
  button1.setDoubleClickFunction(doubleclick);
  button1.setLongClickFunction(longclick);
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
   button1.tick();
   delay(10);
}

