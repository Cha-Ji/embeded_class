#include <wiringPi.h>
#include <stdio.h>

#define PIR_PIN 29
#define LED_PIN 1

int main(void) {
	wiringPiSetup();

	pinMode(PIR_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);

	while(1) {
		int detect = digitalRead(PIR_PIN);
		
		if(detect) printf("Detected ~!!: %d\n", detect);
		else printf("------: %d\n", detect);

		delay(100);

		digitalWrite(LED_PIN, detect);
	}

	return 0;
}
