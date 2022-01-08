#pragma once
#ifndef BLINKPIE_H
#define BLINKPIE_H

#include "Arduino.h"
#define MAX_SIZE 3

class BLINKPIE
{
public:
	BLINKPIE(uint32_t baudrate, String UUID);
	void begin(HardwareSerial *serial);
	void post(String method, String param, String value);
	String get(String method, String value);
	bool checkServerAvail();
	bool checkMethod(String method);

private:
	HardwareSerial *_Serial;
	uint32_t _baudrate;
	String _UUID;
	String _METHOD[MAX_SIZE];
};
#endif
