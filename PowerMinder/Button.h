//------------------------------------------------------------------------------
//   Copyright 2014 Janick Bergeron
//   All Rights Reserved Worldwide
//
//   Licensed under the Apache License, Version 2.0 (the
//   "License"); you may not use this file except in
//   compliance with the License.  You may obtain a copy of
//   the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in
//   writing, software distributed under the License is
//   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//   CONDITIONS OF ANY KIND, either express or implied.  See
//   the License for the specific language governing
//   permissions and limitations under the License.
//------------------------------------------------------------------------------


#include <stdint.h>

namespace PowerMinder {

  /** Class to manage & debounce a button connected to a digital pin */
  class Button_t {

  public:
    /** Initialize the button */
    void init();

    /** Is the button pressed? */
    bool is_pressed();

    /** Has the button been pressed since last time? */
    bool has_been_pressed();

    /** Has the button been released since last time? */
    bool has_been_released();

    /** Button Service loop method: Call in the main loop() or interrupt service routine to detect changes */
    void loop();

  // Looks like Sketches don't support private constructors...
  //private:
    /** Create a button control class */
    Button_t(uint8_t pin,                     ///< Pin number controlling the LED
	     uint8_t when_pressed = HIGH,     ///< digital value when pressed
	     uint8_t pulled       = LOW);     ///< Pull up/down
    ~Button_t();

  private:
    /** Check the state of the button, with SW debouncing */
    bool m_is_pressed();

    uint8_t  m_pin;
    uint8_t  m_pulled;
    bool     m_previous_state;
    bool     m_was_pressed;
    bool     m_was_released;

    uint8_t  m_HIGH;
  };

}
