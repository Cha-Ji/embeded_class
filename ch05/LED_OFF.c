#include <wiringPi.h>

#define LED_PWM_PIN		1

int main(void) {
	wiringPiSetup();
	
	pinMode(LED_PWM_PIN, PWM_OUTPUT);
	
	pwmWrite(LED_PWM_PIN, 0);

	return 0;
}
