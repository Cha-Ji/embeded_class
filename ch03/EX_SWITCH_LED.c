#include <wiringPi.h>
#include <stdio.h>

#define PUSH_PIN 25
#define LED_PIN 29

int main(void) {

	// init library
	wiringPiSetup();

	// set pinMode
	pinMode(PUSH_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);

	// input loop
	int push_signal;

	while(1) {
		// push switch
		push_signal = digitalRead(PUSH_PIN);
		printf("Push Value = %d\n", push_signal);

		digitalWrite(LED_PIN, push_signal);
	}
}
