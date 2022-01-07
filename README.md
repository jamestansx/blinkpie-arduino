# blinkpie-arduino
A simple library for Arduino UNO

# Example

```cpp
#include "blinkpie.h"

String uuid = "Paste Your UUID from The blinkpie_hdl.exe"
BLINKPIE blinkpie(9600, uuid);

void setup(){
	blinkpie.begin(&Serial);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	blinkpie.post("sending from Arduino");
}

void loop(){

	delay(100);
	String data =blinkpie.get();
	if(data.equals("1")) digitalWrite(8,HIGH);
	if(data.equals("2")) digitalWrite(8,HIGH);
	if(data.equals("n")) blinkpie.notify("Hello, World");
}
```
