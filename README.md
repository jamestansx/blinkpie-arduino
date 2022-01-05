# blinkpie-arduino
A simple library for Arduino UNO

# Example

```cpp
#include "serialpy.h"

SERIALPY serialpy(9600);

void setup(){
	serialpy.begin(&Serial);
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	serialpy.post("sending from Arduino");
}

void loop(){

	delay(100);
	String data =serialpy.get();
	if(data.equals("1")) digitalWrite(8,HIGH);
	if(data.equals("2")) digitalWrite(8,HIGH);
}
```
