#include <wiringPi.h>
#include <stdio.h>

#define LED_PWM_PIN		1
#define PWM_HIGH		1024
#define PWM_LOW			0

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
		for(int nBright = PWM_LOW; nBright < PWM_HIGH; nBright++) {
			pwmWrite(LED_PWM_PIN, nBright);
			delay(1);
		}

		for(int nBright = PWM_HIGH - 1; nBright >= PWM_LOW; nBright--) {
			pwmWrite(LED_PWM_PIN, nBright);
			delay(1);
		}
	}
}
