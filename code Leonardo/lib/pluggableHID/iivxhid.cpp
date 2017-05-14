#include "iivxhid.h"

#define REPORT_ID 0x01

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  /*Header */ 
    0x05, 0x01,                    /* USAGE_PAGE (Generic Desktop) */ 
    0x09, 0x05,                    /* USAGE (Game Pad) */ 
    0xa1, 0x01,                    /* COLLECTION (Application) */ 
    0x85, REPORT_ID,				 /*   REPORT_ID */ 
    /*Buttons */ 
    0x05, 0x09,                    /*     USAGE_PAGE (Button) */ 
    0x19, 0x01,                    /*     USAGE_MINIMUM (Button 1) */ 
    0x29, 0x0f,                    /*     USAGE_MAXIMUM (Button 16) changed to 15*/ 
    0x15, 0x00,                    /*     LOGICAL_MINIMUM (0) */ 
    0x25, 0x01,                    /*     LOGICAL_MAXIMUM (1) */ 
    0x95, 0x0f,                    /*     REPORT_COUNT (16)  changed to 15*/ 
    0x75, 0x01,                    /*     REPORT_SIZE (1) */ 
    0x81, 0x02,                    /*     INPUT (Data,Var,Abs) */ 
    /* Reserved byte */ 
    0x95, 0x01,                      /*   REPORT_COUNT (1) */ 
    0x75, 0x01,                      /*   REPORT_SIZE (8) */ 
    0x81, 0x03,                      /*   INPUT (Cnst,Var,Abs) */ 
    /*Axis */ 
    0x05, 0x01,                    /*     USAGE_PAGE (Generic Desktop) */ 
    0x09, 0x30,                    /*     USAGE (X) */ 
    0x09, 0x31,                    /*     USAGE (Y) */ 
    0x09, 0x32,                    /*     USAGE (Z) */ 
    0x15, 0x81,                    /*     LOGICAL_MINIMUM (-127) */ 
    0x25, 0x7f,                    /*     LOGICAL_MAXIMUM (127) */ 
    0x95, 0x02,                    /*     REPORT_COUNT (3) */ 
    0x75, 0x08,                    /*     REPORT_SIZE (8) */ 
    0x81, 0x02,                    /*     INPUT (Data,Var,Abs) */ 
	/*Lights config*/ 
    0x85, 0x02,				 /*   REPORT_ID set to 2*/ 
    0x15, 0x00,                    /*     LOGICAL_MINIMUM (0) */ 
    0x25, 0x01,                    /*     LOGICAL_MAXIMUM (1) */ 
    /*Led 1 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x01,                    /*     USAGE (Instance 1) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 2 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x02,                    /*     USAGE (Instance 2) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 3 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x03,                    /*     USAGE (Instance 3) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 4 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x04,                    /*     USAGE (Instance 4) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 5 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x05,                    /*     USAGE (Instance 5) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 6 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x06,                    /*     USAGE (Instance 6) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 7 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x07,                    /*     USAGE (Instance 7) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 8 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x08,                    /*     USAGE (Instance 8) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 9 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x09,                    /*     USAGE (Instance 9) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 10 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0a,                    /*     USAGE (Instance 10) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 11 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0b,                    /*     USAGE (Instance 11) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
  	/*  Reserved 5 bits */ 
  	0x95, 0x01,						 /*   REPORT_COUNT (1) */ 
  	0x75, 0x05,						 /*   REPORT_SIZE (5) */ 
  	0x91, 0x03,						 /*   OUTPUT (Cnst,Var,Abs) */ 
    /*Footer */ 
    0xc0                          /* END_COLLECTION */ 
};

//append descriptor
iivx_::iivx_(void){
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
};

//blank begin and end
void iivx_::begin(void){};
void iivx_::end(void){};

//set data
size_t iivx_::buttons(uint16_t b){
	_report.buttons = b;
};
size_t iivx_::xAxis(int8_t x){
	_report.xAxis = x;
};
size_t iivx_::yAxis(int8_t y){
	_report.yAxis = x;
};
size_t iivx_::zAxis(int8_t z){
	_report.zAxis = x;
};

//send data
void iivx_::sendReport(iivxReportType* data){
	//HID().sendReport(1,data,sizeof(iivxReportType));
};

//read data
uint8_t iivx_::ledLow(void);
uint8_t iivx_::ledHigh(void);
