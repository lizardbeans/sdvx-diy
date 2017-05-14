#include <Arduino.h>

typedef union{
	uint8_t whole8[5];
	uint16_t buttonContainer;
	struct{
		uint16_t buttons;
		int8_t xAxis;
		int8_t yAxis;
		int8_t zAxis;
	};
} iivxReportType;

class iivx_{
public:
	iivx_(void);
	void begin(void);
	void end(void);
	size_t buttons(uint16_t b);
	size_t xAxis(int8_t x);
	size_t yAxis(int8_t y);
	size_t zAxis(int8_t z);
	uint8_t ledLow(void);
	uint8_t ledHigh(void);
private:
	void sendReport(iivxReportType* data);
	iivxReportType _report;
};
extern iivx_ iivx;
