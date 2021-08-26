#include <iostream>
#include <stdio.h>
#include <wiringPi.h>

using namespace std;

#define ledPin 0

int main(){
	cout << "Program is starting ... " << endl;
	wiringPiSetup();

	pinMode(ledPin,OUTPUT);
	printf("Using pin %d\n",ledPin);

	while(1){
		digitalWrite(ledPin,HIGH);
		cout << "led turned on >>>" << endl;
		delay(1000);
		digitalWrite(ledPin,LOW);
		cout << "led turned off <<<" << endl;
		delay(1000);
	}

	return 0;


}
