#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "rpi-hc-sr04.h"

float dist = 0;

int main () {
	
	printf ("Raspberry Pi HC-SR04 Distance Tool\n");

	if (wiringPiSetup () == -1) {
		exit(EXIT_FAILURE);
	}
	
	dist = distance(4,5);
	printf("Distance: %.2f cm\n", dist);
	
	return 0;
}