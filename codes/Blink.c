#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0 

void main(void)
{
	printf("[INFO] Program is starting ... \n");
	wiringPiSetup();
	pinMode(ledPin,OUTPUT);
	printf("[INFO] Using pin %d\n");

	while (1){
		digitalWrite(ledPin,HIGH);
		printf("\r[INFO] LED turned on >>>");
		delay(1000);
		fflush(stdout);
		digitalWrite(ledPin,LOW);
		printf("\r[INFO] LED turned off <<<");
		delay(1000);
		fflush(stdout);
	}
}
