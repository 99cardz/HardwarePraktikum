#include <iostream>
#include <b15f/b15f.h>
using namespace std;

double toVoltage(int analogReading) {
	return analogReading * 5.0 / 1023.0;
}
int toAnalogValue(double voltage) {
	return (int) (voltage *  1023.0 / 5.0);
}
int main() {
	B15F& drv = B15F::getInstance();
	drv.analogWrite1(0);
	drv.analogWrite0(0);
	int reading = drv.digitalRead1(); 
	
	for(double v = 0.0; v < 5.0; v += 0.1) {
		drv.analogWrite0(toAnalogValue(v));
		if (drv.digitalRead1() != reading) {
			reading = drv.digitalRead1();
			cout << "Hoch: " << v << "V" << endl;
		}
	}
	for(double v = 5.0; v > 0.0; v -= 0.1) {
		drv.analogWrite0(toAnalogValue(v));
		if (drv.digitalRead1() != reading) {
			reading = drv.digitalRead1();
			cout << "Runter: " << v << "V" << endl;
		}
	}
	drv.analogWrite0(0);
	drv.analogWrite1(0);
}
