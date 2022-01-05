#ifndef SERIALPY_H
#define SERIALPY_H

#include "Arduino.h"

class SERIALPY {
public:
	SERIALPY(uint32_t baudrate);
	void begin(HardwareSerial *serial);
	void post(String data);
	String get();
private:
	HardwareSerial *_Serial;
	uint32_t _baudrate;
};
#endif
