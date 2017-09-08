#include "iivx_leo.h"
#include "Encoder.h"
iivxReport_t report;

//source code here: https://github.com/4yn/iivx

#define REPORT_DELAY 2000
// Number of microseconds between HID reports
// 2000 = 500hz

// Options, change only these values

uint8_t buttonCount = 7;
//*uint8_t sysPin = 5;
uint8_t lightMode = 0;
// 0 = reactive lighting, 1 = HID lighting
uint8_t buttonPins[] = { 13, 18, 19, 20, 21, 22, 23};
uint8_t ledPins[] = {6,7,8,9,10,11,12};
/* current pin layout
    pins 6 to 12 = LED 1 to 7 //{6,7,8,9,10,11,12}
    pins 13, A0 to A5 = Button input 1 to 7
   
    pins 5 = system pin
      connect system pin to ground with a small button
        press together with other buttons to change lighting scheme
      system button + button 1 = reactive lighting
      system button + button 3 = HID lighting
*/

#define ENCODER_SENSITIVITY (double) 0.375
// encoder sensitivity = number of positions per rotation times 4 (24*4) / number of positions for HID report (256)
Encoder encL(0, 1), encR(2, 3);
/*
   connect encoders
   VOL-L to pins 0 and 1
   VOL-R to pins 2 and 3
*/

void lights(uint8_t lightDesc) {
  for (int i = 0; i < buttonCount; i++) {
    if ((lightDesc >> i) & 1) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void setup() {
  delay(1000);
  // Setup I/O for pins
  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  //  pinMode(sysPin,INPUT_PULLUP);
  //setup interrupts
}

void loop() {
  // Read buttons
  for (int i = 0; i < buttonCount; i++) {
    if (digitalRead(buttonPins[i]) != HIGH) {
      report.buttons |= (uint16_t)1 << i;
    } else {
      report.buttons &= ~((uint16_t)1 << i);
    }
  }
  // Read Encoders
  report.xAxis = (uint8_t)((int32_t)(encL.read() / ENCODER_SENSITIVITY) % 256);
  report.yAxis = (uint8_t)((int32_t)(encR.read() / ENCODER_SENSITIVITY) % 256);
  // Light LEDs
  if (lightMode == 0) {
    lights(report.buttons);
  } else {
    lights(iivx_led);
  }
  // Detect lighting changes
  // if(digitalRead(sysPin)!=HIGH){
  //   if(report.buttons == 1){
  //     lightMode = 0;
  //  } else if (report.buttons == 4){
  //    lightMode = 1;
  //  } else if (report.buttons == 16){
  //    report.buttons = (uint16_t)1 << (buttonCount);
  //   } else if (report.buttons == 64){
  //     report.buttons = (uint16_t)1 << (buttonCount+1);
  //   }
  //  }
  // Send report and delay
  iivx.setState(&report);
  delayMicroseconds(REPORT_DELAY);
}
