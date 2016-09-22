#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rpi-hc-sr04.h"

float distance(int TRIG, int ECHO) {
	
	int ping = 0;
	int pong = 0;
	long timeout = 500000;
	float distance = 0; 
	
	// set pins
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	// trig low
	digitalWrite(TRIG, LOW);
	delay(100);
	
	// trigger sensor
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG, LOW);
	
	// handle response or timeout
	while (digitalRead(ECHO) == LOW && micros() < timeout) {		
	}
	
	// handle timeout
	if (micros() > timeout) {
		printf("out of range - distance to short\n");
		return 0;
	}
	
	ping = micros();
	
	// handle response or timeout
	while (digitalRead(ECHO) == HIGH && micros() < timeout) {
	}
	
	// handle timeout
	if (micros() > timeout) {
		printf("out of range - distance to far away\n");
		return 0;
	}
	
	pong = micros();
	
	// calc distance
	distance = (float)(pong - ping)*0.017150;	
	
	return distance;	
}