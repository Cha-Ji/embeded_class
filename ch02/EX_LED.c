#include <wiringPi.h>
#include <stdio.h>

#define LED_PIN 29
#define DELAY_TIME 100

int main(void) {
	// library init
	wiringPiSetup();
	
	// LED init
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

	while(1) {
		digitalWrite(LED_PIN, HIGH);	// LED on
		printf("LED ON\n");
		delay(DELAY_TIME);

		digitalWrite(LED_PIN, LOW);	// LED on
		printf("LED OFF\n");
		delay(DELAY_TIME);
	}

	return 0;
}

	
