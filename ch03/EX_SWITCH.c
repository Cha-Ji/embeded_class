#include <wiringPi.h>
#include <stdio.h>

#define PUSH_PIN 25

int main(void) {
	// init Library
	wiringPiSetup();
	
	// set pinMode
	pinMode(PUSH_PIN, INPUT);

	// print input value
	while(1) {
		printf("Push Value = %d\n", digitalRead(PUSH_PIN));
	}

	return 0;
}
