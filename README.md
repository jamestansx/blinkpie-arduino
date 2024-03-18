# blinkpie-arduino
A simple library for Arduino UNO

## Available Functions

Class:
- BLINKPIE(uint32_t baudrate, String UUID)

Functions:
- begin(HardwareSerial *serial)
- post(String method, String param, String value)
- get(String method, String param)

## Example

```cpp
#include "blinkpie.h"
#include <SoftwareSerial.h>

SoftwareSerial serialMon = SoftwareSerial(4,5);
String uuid = "Paste Your UUID from The blinkpie_hdl.exe"
BLINKPIE blinkpie(9600, uuid);

// blinkpie.post(Method, id, data)
// blinkpie.get(Method, id)

// Methods available: 
// - data
// - notification
// - profile

void setup(){
	blinkpie.begin(&Serial);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	serialMon.begin(9600);
	serialMon.println("Received");
	blinkpie.post("notification","notification title","sending from Arduino");
	serialMon.println("post");
}

void loop(){

	delay(500);
	String data = blinkpie.get("data", "led");
	serialMon.println(data);
	if(data.equals("1")) digitalWrite(8,HIGH);
	if(data.equals("2")) digitalWrite(8,HIGH);
}
```
