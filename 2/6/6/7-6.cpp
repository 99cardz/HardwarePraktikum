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
int main(int argc, char** argv)
{
	B15F& drv = B15F::getInstance();
	
	double voltage = stod(argv[1]);
	int analogValue = toAnalogValue(voltage);
	cout << "voltage: " << voltage << " analogValue: " << analogValue << endl;
	
	drv.analogWrite0(analogValue);
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite1(i);
		int amp = (drv.analogRead(0) - drv.analogRead(1)) ;
		cout << toVoltage(drv.analogRead(2)) << ", " << toVoltage(amp) / 0.15 << endl;
	}
	drv.analogWrite1(0);
}
