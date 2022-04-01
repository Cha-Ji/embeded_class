#include <stdio.h>
#include <wiringPi.h>

#define TRIG_PIN	4
#define ECHO_PIN	5
#define DELAY_TIME	500

void setPinMode();

void setBeforeSetUp();

void runLoop();
int getStartTime();
int getEndTime();

void printDistance(int start_time, int end_time);

int main(void) {
	wiringPiSetup();

	setPinMode();

	runLoop();

	return 0;
}

void setPinMode() {
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	printf("set pin mode\n");
}

void setBeforeSetUp() {
	digitalWrite(TRIG_PIN, LOW);
	delay(DELAY_TIME);

	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);
//	printf("before set up\n");
}

void runLoop() {
	int start_time, end_time;

	while(1) {
		setBeforeSetUp();
		
		start_time = getStartTime();
		end_time = getEndTime();
		printDistance(start_time, end_time); 
	}
}

int getStartTime() {
	int start_time;

	while(digitalRead(ECHO_PIN) == LOW)
		start_time = micros();

	return start_time;
}

int getEndTime() {
	int end_time;

	while(digitalRead(ECHO_PIN) == HIGH)
		end_time = micros();

	return end_time;
}

void printDistance(int start_time, int end_time) {
	float distance = (331.5 + 0.6 *2.5) * ((float)(end_time - start_time)/1000000 / 2) * 100;

	if (distance < 2 || distance > 400) printf("Out of range!\n");
	else printf("Distance : %3.0f cm \n", distance);
}
