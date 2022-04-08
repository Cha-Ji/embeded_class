#include <wiringPi.h>
#include <softTone.h>

#define LED_PWM_PIN		1
#define BUZ_PIN			0

unsigned int melody[14] = {262, 294, 330, 349, 392, 440, 494,
						523, 587, 659, 698, 784, 830, 987};
int score[9] = {9, 8, 9, 8, 9, 6, 8, 7, 5};

void setPinMode();
void runLoop();
void setScore();

int main(void) {
	wiringPiSetup();
	
	setPinMode();

	softToneCreate(BUZ_PIN);

	runLoop();

	softToneStop(BUZ_PIN);

	return 0;
}

void setPinMode() {
	pinMode(BUZ_PIN, SOFT_TONE_OUTPUT);
}

void runLoop() {
	while(1) {
		for(int i = 0; i < 9; i++) {
			softToneWrite(BUZ_PIN, melody[score[i]]);
			delay(500);
		}
		delay(500);
	}
}
