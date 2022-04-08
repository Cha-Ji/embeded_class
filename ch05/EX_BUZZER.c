#include <wiringPi.h>
#include <softTone.h>

#define LED_PWM_PIN		1
#define BUZ_PIN			0

unsigned int melody[8] = {262, 294, 330, 349, 392, 440, 494, 523};

void setPinMode();
void runLoop();

int main(void) {
	wiringPiSetup();

	softToneCreate(BUZ_PIN);

	runLoop();

	softToneStop(BUZ_PIN);

	return 0;
}

void runLoop() {
	while(1) {
		for(int i = 0; i < 8; i++) {
			softToneWrite(BUZ_PIN, melody[i]);
			delay(1000);
		}
	}
}
