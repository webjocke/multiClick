#ifndef mc
#define mc

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// ----- Callback function types -----
extern "C" {
  typedef void (*callbackFunction)(void);
}

class MultiClick {
  public:
    // Constructor
    MultiClick(int pin, int debounce_time=20, int double_time=250, int long_time=1600);
    
    // Methods
    void tick();
    void setSingleClickFunction(callbackFunction new_function);
    void setDoubleClickFunction(callbackFunction new_function);
    void setLongClickFunction(callbackFunction new_function);
    
  private:

    // Variables
    int btnPin;
    
    int longpress_ms;
    int doublepress_ms;
    int debunce_ms;

    unsigned long current_time;
    unsigned long last_time;
    unsigned long last_up;

    bool button1_last;
    bool clicked;
    bool long_clicked;
    bool now;

    callbackFunction single_function;
    callbackFunction double_function;
    callbackFunction long_function;
};

#endif