#include <wiringPi.h>
#include <stdio.h>

#define ledCounts 10
int pins[ledCounts] = {0,1,2,3,4,5,6,8,9,10};

void main(void)
{
	int i;
	printf("[INFO] Light LED Left Right");
	wiringPiSetup();
	
	for(i=0;i<ledCounts;i++){
		pinMode(pins[i],OUTPUT);
	}
	while(1){
		for(i=0;i<ledCounts;i++){
			digitalWrite(pins[i],LOW);
			delay(1000);
			digitalWrite(pins[i],HIGH);
			printf("\r[INFO] LED %d",i);
			fflush(stdout);
		}
		for(i=ledCounts-1;i>-1;i--){
			digitalWrite(pins[i],LOW);
			delay(1000);
			digitalWrite(pins[i],HIGH);
			printf("\r[INFO] LED %d",i);
			fflush(stdout);
		}
	}
}
