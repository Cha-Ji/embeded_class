#include <wiringPi.h>
#include <stdio.h>

#define LED_PIN 29

int main(void) {
	// library init
	wiringPiSetup();
	
	// LED init
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

	digitalWrite(LED_PIN, LOW);	// LED off
	printf("LED OFF\n");

	return 0;
}
