#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
#define buttonPin 1
int ledState=LOW;
int buttonState=HIGH;
int lastbuttonState=HIGH;
long lastChangeTime;
long captureTime=50;
int reading;

int main(void){
	printf("[INFO] LED Lamp Program is starting...\n");
	wiringPiSetup();
	pinMode(ledPin,OUTPUT);
	pinMode(buttonPin,INPUT);
	pullUpDnControl(buttonPin,PUD_UP);

	while(1){
		reading = digitalRead(buttonPin);
		if(reading!=lastbuttonState){
			lastchangeTime = millis();
		}
		if(!ledState){
			printf("\r[INFO] LED off...");
		}
		if(millis() - lastChangeTime > captureTime){
			if(reading!=buttonState){
				buttonState = reading;
				if(buttonState==LOW){
					ledState = !ledState;
					if(ledState){
						printf("\r[INFO] LED on...");
						fflush(stdout);
					}
					else{
						printf("\r[INFO] LED off...");
						fflush(stdout);
					}
				}
			}
		}
		digitalWrite(ledPin,ledState);
		lastbuttonState = reading;
	}
	return 0;
}
