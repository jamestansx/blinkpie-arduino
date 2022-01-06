#ifndef BLINKPIE_H
#define BLINKPIE_H

#include "Arduino.h"

class BLINKPIE {
public:
	BLINKPIE(uint32_t baudrate, String UUID);
	void begin(HardwareSerial *serial);
	void post(String data);
	void notify(String data);
	String get();
	bool checkServerAvail();
private:
	HardwareSerial *_Serial;
	uint32_t _baudrate;
	String _UUID;
};
#endif
