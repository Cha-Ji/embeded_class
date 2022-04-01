#include <wiringPi.h>
#include <stdio.h>

#define BUZ_PIN	0
#define DELAY_TIME	1000

int main(void) {
	wiringPiSetup();

	pinMode(BUZ_PIN, OUTPUT);

	while(1) {
		digitalWrite(BUZ_PIN, HIGH);
		delay(DELAY_TIME);
		digitalWrite(BUZ_PIN, LOW);
		delay(DELAY_TIME);
		printf("BUZZER\n");
	}
	
	return 0;
}
