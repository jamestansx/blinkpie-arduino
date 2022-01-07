#include "Arduino.h"
#include "blinkpie.h"

BLINKPIE::BLINKPIE(uint32_t baudrate, String UUID)
{
	_baudrate = baudrate;
	_Serial = NULL;
	_UUID = UUID;
}

void BLINKPIE::begin(HardwareSerial *serial)
{
	_Serial = serial;
	_Serial->begin(_baudrate);
	do
	{
		String content = String("{\"profile\": \"" + _UUID + "\"}\r\n");
		_Serial->print(content);
	} while (!checkServerAvail());
}

void BLINKPIE::post(String data)
{
	do
	{
		_Serial->print(String(String("{\"data\": \"") + data + "\"}\r\n"));
	} while (!checkServerAvail());
}

String BLINKPIE::get()
{
	_Serial->print(String(String("data\r\n")));
	String data;
	do
	{
		data = _Serial->readString();
		data.trim();
	} while (data.length() == 0);
	_Serial->print(String("200\r\n"));
	return data;
}

void BLINKPIE::notify(String data)
{
	do
	{
		_Serial->print(String(String("{\"notification\":\"") + data + "\"}\r\n"));
	} while (!checkServerAvail());
}

bool BLINKPIE::checkServerAvail()
{
	while (_Serial->readString().equals(String("200\r\n")) != 1)
		if (millis() > 60000)
			return false;
	return true;
}
