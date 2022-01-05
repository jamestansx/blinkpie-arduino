#include "Arduino.h"
#include "blinkpie.h"


BLINKPIE::BLINKPIE(uint32_t baudrate){
	_baudrate = baudrate;
	_Serial = NULL;
}

void BLINKPIE::begin(HardwareSerial *serial){
	_Serial = serial;
	_Serial->begin(_baudrate);
}

void BLINKPIE::post(String data){
	_Serial->print(String("POST " + data + "\r\n"));
	while(_Serial->readString().equals(String("200\r\n")) != 1);
}

String BLINKPIE::get(){
	_Serial->print(String("GET\r\n"));
	String data;
	do{
		data = _Serial->readString();
		data.trim();
	}while(data.length() == 0);
	_Serial->print(String("200\r\n"));
	return data;
}
