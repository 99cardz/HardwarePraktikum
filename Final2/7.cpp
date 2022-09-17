#include <iostream>
#include <b15f/b15f.h>

using namespace std;

double toVoltage(int analogReading) { return analogReading * 5.0 / 1023.0; }
int toAnalogValue(double voltage) { return (int) (voltage *  1023.0 / 5.0); }

int main(int argc, char** argv)
{
	B15F& drv = B15F::getInstance();
	
	double voltage = stod(argv[1]);
	int analogValue = toAnalogValue(voltage);
	cout << "voltage: " << voltage << " analogValue: " << analogValue << endl;
	drv.analogWrite1(analogValue);
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite0(i);
		double strom3 = toVoltage(drv.analogRead(0) - drv.analogRead(1)) / 0.15; // mA
		double spannung3 = toVoltage(drv.analogRead(1));
		double spannung1 = toVoltage(drv.analogRead(2));
		double strom1 = toVoltage(drv.analogRead(3) - drv.analogRead(2)) // mA
		cout << strom3 << "," << spannung3 << "," << strom1 << "," << spannung1 << endl;
	}
	drv.analogWrite1(0);
	drv.analogWrite0(0);
}
