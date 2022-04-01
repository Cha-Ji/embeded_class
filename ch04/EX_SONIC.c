#include <stdio.h>
#include <wiringPi.h>

#define TRIG_PIN	4
#define ECHO_PIN	5
#define BUZ_PIN		0
#define DELAY_TIME	500

void setPinMode();
void setBeforeSetUp();
void runLoop();
int getStartTime();
int getEndTime();
void printDistance(float distance);
void setBackSignal(float distance);
void soundBuzzer(int delayTime);

int main(void) {
	wiringPiSetup();

	setPinMode();

	runLoop();

	return 0;
}

void runLoop() {
	int start_time, end_time;
	float distance;

	while(1) {
		setBeforeSetUp();
		
		start_time = getStartTime();
		end_time = getEndTime();
		distance = (331.5 + 0.6 *2.5) * ((float)(end_time - start_time)/1000000 / 2) * 100;

		setBackSignal(distance);
		printDistance(distance); 
	}
}

void setBackSignal(float distance) {
	if (distance < 2 || distance > 400) delay(100);
	else if (2 < distance && distance < 5) soundBuzzer(100);
	else if (5 <= distance && distance < 10) soundBuzzer(1000);
	else delay(100);
}

void soundBuzzer(int delayTime) {
	digitalWrite(BUZ_PIN, HIGH);
	delay(delayTime);
	digitalWrite(BUZ_PIN, LOW);
	delay(delayTime);
	
	printf("BUZZER\n");
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

void printDistance(float distance) {
	if (distance < 2 || distance > 400) printf("Out of range!\n");
	else printf("Distance : %3.0f cm \n", distance);
}
