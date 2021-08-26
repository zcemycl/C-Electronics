#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

void setupLedPin(void)
{
	softPwmCreate(ledPinRed	 ,0,100);
	softPwmCreate(ledPinGreen,0,100);
	softPwmCreate(ledPinBlue ,0,100);
}
void setLedColor(int r,int g,int b)
{
	softPwmWrite(ledPinRed	,r);
	softPwmWrite(ledPinGreen,g);
	softPwmWrite(ledPinBlue ,b);
}
int main(void)
{
	int r,g,b;
	printf("[INFO] Color LED Program ...\n");
	wiringPiSetup();
	setupLedPin();
	while(1){
		r=random()%100;
		g=random()%100;
		b=random()%100;
		setLedColor(r,g,b);
		printf("\rr=%d, g=%d, b=%d",r,g,b);
		fflush(stdout);
		delay(500);
	}
	return 0;
}




