#include <iostream>
#include <b15f/b15f.h>

using namespace std;

double toVoltage(int analogReading)
{
	return analogReading * 5.0 / 1023.0;
}
int toAnalogValue(double voltage)
{
	return (int) (voltage *  1023.0 / 5.0);
}

int main()
{
	B15F& drv = B15F::getInstance();
	drv.analogWrite1(0);
	drv.analogWrite0(0);
	
	int zahl = drv.digitalRead1(); 
	
	for(int i = 0; i < 1024; i+=10) {
		drv.analogWrite0(i);
		
		if (drv.digitalRead1() != zahl) {
			zahl = drv.digitalRead1();
			cout << "Hoch: " << toVoltage(i) << endl;
		}
	}
	
	for(int i = 1023; i >= 0; i-=10) {
		drv.analogWrite0(i);
		
		if (drv.digitalRead1() != zahl) {
			zahl = drv.digitalRead1();
			cout << "Runter: " << toVoltage(i) << endl;
		}
	}
	drv.analogWrite0(0);
	drv.analogWrite1(0);
}
