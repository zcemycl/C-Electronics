#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1

void main(void)
{
	printf("Program is starting ... \n");
	wiringPiSetup();
	pinMode(ledPin,OUTPUT);
	pinMode(buttonPin,INPUT);

	pullUpDnControl(buttonPin,PUD_UP);
	while(1){
		if(digitalRead(buttonPin) == LOW){
			digitalWrite(ledPin,HIGH);
			printf("\rButton is pressed, LED turned on >>>");
			fflush(stdout);
		}
		else {
			digitalWrite(ledPin,LOW);
			printf("\rButton is released, LED turned off <<<");
			fflush(stdout);
		}
	}
}
