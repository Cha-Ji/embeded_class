#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>

#define LCD_RS 11 // register select pin
#define LCD_E  10 // Enable pin
#define LCD_D4 6  // Data pin 4
#define LCD_D5 5  // Data pin 5
#define LCD_D6 4  // Data pin 6
#define LCD_D7 1  // Data pin 7

int main(void) {
	int lcd;
	wiringPiSetup();

	if (lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)) {
		printf("lcd init failed! \n");
		return -1;
	}

	lcdPosition(lcd, 0, 0); //Position cursor on the first line in the first column.
	lcdPuts(lcd, "HELLO WORLD");
	
	getchar();
	lcdClear(lcd);


	return 0;
}
