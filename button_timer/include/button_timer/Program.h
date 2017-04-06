#pragma once


struct Program {
  Program()
    : signaled{} {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    clock.reset();
  }
  void step() {
    if (button_is_pressed()) {
      turn_signal_on();
    }
    else {
      turn_signal_off();
    }
    if (signaled) {
      clock.increment();
    }
  }

  void turn_signal_on() {
    signaled = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }

  void turn_signal_off() {
    signaled = false;
    digitalWrite(LED_BUILTIN, LOW);
  }
private:
  bool button_is_pressed() const {
    return HIGH == digitalRead(2);
  }

  Clock clock;
  bool signaled;
};


