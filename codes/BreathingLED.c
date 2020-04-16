#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define ledPin 1

void main(void)
{
	int i;
	printf('[INFO] Glowing LED is starting...\n');
	wiringPiSetup();
	softPwmCreate(ledPin,0,100);
	
	while(1){
		for(i=0;i<100;i++){
			softPwmWrite(ledPin,i);
			delay(20);
		}
		delay(300);
		for(i=100;i>=0;i--){
			softPwmWrite(ledPin,i);
			delay(20);
		}
		delay(300);
	}
}
