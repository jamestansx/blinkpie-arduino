#include "Arduino.h"
#include "serialpy.h"

#define MIN_DELAY 500

SERIALPY::SERIALPY(uint32_t baudrate){
	_baudrate = baudrate;
	_Serial = NULL;
}

void SERIALPY::begin(HardwareSerial *serial){
	_Serial = serial;
	_Serial->begin(_baudrate);
}

void SERIALPY::post(String data){
	_Serial->print(String("POST " + data + "\r\n"));
	while(_Serial->readString().equals(String("200\r\n")) != 1);
}

String SERIALPY::get(){
	_Serial->print(String("GET\r\n"));
	String data;
	do{
		data = _Serial->readString();
		data.trim();
	}while(data.length() == 0);
	_Serial->print(String("200\r\n"));
	return data;
}
