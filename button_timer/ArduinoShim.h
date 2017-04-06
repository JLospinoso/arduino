#pragma once
#include <iostream>
#include <array>
#include <thread>
#include <chrono>

#define LED_BUILTIN 0

enum PowerSetting {
  LOW,
  HIGH
};

enum InputSetting {
  INPUT,
  OUTPUT
};

namespace _internal {
  std::array<PowerSetting, 13> pin_states{};
}

inline void manuallySet(int pin, PowerSetting value) {
  _internal::pin_states[pin] = value;
}

inline int digitalRead(int pin) {
  std::cout << "DigitalRead: Reading " << pin << " -> " << _internal::pin_states[pin] << std::endl;
  return _internal::pin_states[pin];
}

inline void digitalWrite(int pin, PowerSetting setting) {
  std::cout << "DigitalWrite: Setting " << pin << " -> " << setting << std::endl;
  _internal::pin_states[pin] = setting;
}

inline void pinMode(int pin, InputSetting setting) {
  std::cout << "PinMode: Configuring " << pin << " -> " << setting << std::endl;
}

inline void delay(int ms) {
  std::this_thread::sleep_for(std::chrono::duration<int, std::milli>{ ms });
}