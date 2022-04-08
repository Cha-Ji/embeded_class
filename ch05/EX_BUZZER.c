#include <wiringPi.h>
#include <stdio.h>

#define LED_PWM_PIN		1

void setPinMode();
void runLoop();

int main(void) {
	wiringPiSetup();

	setPinMode();

	runLoop();

	return 0;
}

void setPinMode() {
	pinMode(LED_PWM_PIN, PWM_OUTPUT);
}

void runLoop() {
	while(1) {
		for(int nBright = 0; nBright < 1024; nBright++) {
			pwmWrite(LED_PWM_PIN, nBright);
			delay(1);
		}

		for(int nBright = 1023; nBright >= 0; nBright--) {
			pwmWrite(LED_PWM_PIN, nBright);
			delay(1);
		}
	}
}
