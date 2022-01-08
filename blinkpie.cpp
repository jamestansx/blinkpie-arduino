#include "Arduino.h"
#include "blinkpie.h"

BLINKPIE::BLINKPIE(uint32_t baudrate, String UUID)
{
	_baudrate = baudrate;
	_Serial = NULL;
	_UUID = UUID;
	_METHOD[0] = String("data");
	_METHOD[1] = String("notification");
	_METHOD[2] = String("profile");
}

void BLINKPIE::begin(HardwareSerial *serial)
{
	_Serial = serial;
	_Serial->begin(_baudrate);
	do{
		String data;
		data = String("{\"profile\":\"" + String(_UUID) + "\"}\r\n");
		_Serial->print(data);
	} while(!checkServerAvail());
}

void BLINKPIE::post(String method, String param, String value)
{
	do
	{
		String data = String("{\"" + String(method + "\":{\"") + String(param + "\":\"") + String(value + "\"}}\r\n"));
		_Serial->print(data);
	} while (!checkServerAvail());
}

String BLINKPIE::get(String method, String param)
{
	String data;
	if (checkMethod(method))
		data = String("{\"" + method + "\":\"" + param + "\"}\r\n");
	_Serial->print(data);
	do
	{
		data = _Serial->readString();
		data.trim();
	} while (data.length() == 0);
	if (data.equals(String("404"))) data = String(-1);
	_Serial->print(String("200\r\n"));
	return data;
}

bool BLINKPIE::checkServerAvail()
{
	while (_Serial->readString().equals(String("200\r\n")) != 1)
		if (millis() > 60000)
			return false;
	return true;
}

bool BLINKPIE::checkMethod(String method)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (_METHOD[i].indexOf(method))
			return true;
	}
	return false;
}