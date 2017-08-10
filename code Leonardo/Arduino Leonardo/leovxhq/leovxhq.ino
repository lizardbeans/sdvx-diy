#include "iivx_leo.h"
iivxReport_t report; 

#define REPORT_DELAY 2000
// Number of microseconds between HID reports
// 2000 = 500hz

#define ENC_L_A 0
#define ENC_L_B 1
#define ENC_L_B_ADDR 3
#define ENC_R_A 2
#define ENC_R_B 3
#define ENC_R_B_ADDR 0
#define ENCODER_SENSITIVITY (double) 2.34375
#define ENCODER_PORT PIND
// encoder sensitivity = number of positions per rotation (600/256) / number of positions for HID report (256)
/*
 * connect encoders
 * VOL-L to pins 0 and 1
 * VOL-R to pins 2 and 3
 */

int tmp;
uint8_t buttonCount = 7;
uint8_t lightMode = 0;
// 0 = reactive lighting, 1 = HID lighting
uint8_t ledPins[] = {6,7,8,9,10,11,12};
uint8_t buttonPins[] = {13,18,19,20,21,22,23};
uint8_t sysPin = 5;
uint8_t reactiveLightPin = 21;
uint8_t hidLightPin = 22;
uint8_t sysInputPins[] = {13,18,19,20};
int32_t encL=0, encR=0;
/* current pin layout
 *  pins 6 to 12 = LED 1 to 7
 *    connect pin to + termnial of LED
 *    connect ground to resistor and then - terminal of LED
 *  pins 13, A0 to A5 = Button input 1 to 7
 *    connect button pin to ground to trigger button press
 *  pins 5 = system pin
 *    connect system pin to ground with a small button
 *      press together with other buttons to change lighting scheme
 *    system button + button 1 = reactive lighting
 *    system button + button 3 = HID lighting
 */
 

void doEncL(){
  if((ENCODER_PORT >> ENC_L_B_ADDR)&1){
    encL++;
  } else {
    encL--;
  }
}

void doEncR(){
  if((ENCODER_PORT >> ENC_R_B_ADDR)&1){
    encR++;
  } else {
    encR--;
  }
}

void lights(uint8_t lightDesc){
  for(int i=0;i<buttonCount;i++){
     if((lightDesc>>i)&1){
         digitalWrite(ledPins[i],HIGH);
     } else {
         digitalWrite(ledPins[i],LOW);
     }
  }
}

void setup() {
  delay(1000);
  // Setup I/O for pins
  for(int i=0;i<buttonCount;i++){
    pinMode(buttonPins[i],INPUT_PULLUP);
    pinMode(ledPins[i],OUTPUT);
  }
  pinMode(sysPin,INPUT_PULLUP);
  //setup interrupts
  pinMode(ENC_L_A,INPUT_PULLUP);
  pinMode(ENC_L_B,INPUT_PULLUP);
  pinMode(ENC_R_A,INPUT_PULLUP);
  pinMode(ENC_R_B,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENC_L_A), doEncL, RISING);
  attachInterrupt(digitalPinToInterrupt(ENC_R_A), doEncR, RISING);
}

void loop() {
  // Read buttons
  for(int i=0;i<buttonCount;i++){
    if(digitalRead(buttonPins[i])!=HIGH){
      report.buttons |= (uint16_t)1 << i;
    } else {
      report.buttons &= ~((uint16_t)1 << i);
    }
  }
  // Read Encoders
  report.xAxis = (uint8_t)((int32_t)(encL / ENCODER_SENSITIVITY) % 256);
  report.yAxis = (uint8_t)((int32_t)(encR / ENCODER_SENSITIVITY) % 256);
  // Light LEDs
  if(lightMode==0){
    lights(report.buttons);
  } else {
    lights(iivx_led);
  }
  // Detect Syspin Entries
  if(digitalRead(sysPin)!=HIGH){
    report.buttons = 0;
    for(int i=0;i<4;i++){
      if(digitalRead(sysInputPins[i])!=HIGH){
        report.buttons |= (uint16_t)1 << (i+buttonCount);
      } else {
        report.buttons &= ~((uint16_t)1 << (i+buttonCount));
      }
    }
    if(digitalRead(reactiveLightPin)!=HIGH){
      lightMode = 0;
    } else if (digitalRead(hidLightPin)!=HIGH){
      lightMode = 1;
    }
  }
  // Send report and delay
  iivx.setState(&report);
  delayMicroseconds(REPORT_DELAY);
}

