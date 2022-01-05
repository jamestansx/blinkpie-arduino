#ifndef BLINKPIE_H
#define BLINKPIE_H

#include "Arduino.h"

class BLINKPIE {
public:
	BLINKPIE(uint32_t baudrate);
	void begin(HardwareSerial *serial);
	void post(String data);
	String get();
private:
	HardwareSerial *_Serial;
	uint32_t _baudrate;
};
#endif
