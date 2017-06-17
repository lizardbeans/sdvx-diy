/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2013 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef USBarcade_h_
#define USBarcade_h_

#include "usb_desc.h"

#if defined(ARCADE_INTERFACE)

#include <inttypes.h>

// C language implementation
#ifdef __cplusplus
extern "C" {
#endif
int usb_arcade_recv(void *buffer, uint32_t timeout);
uint32_t usb_arcade_available(void);
int usb_arcade_send(void);
extern uint8_t usb_arcade_data[3];
#ifdef __cplusplus
}
#endif

// C++ interface
#ifdef __cplusplus
class usb_arcade_class
{
  public:
  void begin(void) { }
  void end(void) { }
  void button(uint8_t button, bool val) {
    if (--button >= 8) return;
    if (val) usb_arcade_data[0] |= (1 << button);
    else usb_arcade_data[0] &= ~(1 << button);
    if (!manual_mode) usb_arcade_send();
  }
  void X(unsigned int val) {
    if (val > 255) val = 255;
    usb_arcade_data[1] = val;
    if (!manual_mode) usb_arcade_send();
  }
  void Y(unsigned int val) {
    if (val > 255) val = 255;
    usb_arcade_data[2] = val;
    if (!manual_mode) usb_arcade_send();
  }
  void position(unsigned int x, unsigned int y) {
    if (x > 255) x = 255;
    if (y > 255) y = 255;
    usb_arcade_data[1] = x;
    usb_arcade_data[2] = y;
    if (!manual_mode) usb_arcade_send();
  }
  void useManualSend(bool mode) {
    manual_mode = mode;
  }
  void send_now(void) {
    usb_arcade_send();
  }
  int recv(void *buffer, uint16_t timeout) {
    return usb_arcade_recv(buffer, timeout);
  }
  uint32_t available(void){
    return usb_arcade_available();
  }
  private:
  static boolean manual_mode;
};
extern usb_arcade_class Arcade;

#endif // __cplusplus

#endif // JOYSTICK_INTERFACE

#endif // USBjoystick_h_

