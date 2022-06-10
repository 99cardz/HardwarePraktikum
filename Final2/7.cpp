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
	
	drv.analogWrite1(analogValue); // gate source constant
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite0(i); // drain
		double stromDrain = toVoltage(drv.analogRead(0) - drv.analogRead(1)) / 0.15;
		double spannungSourceDrain = toVoltage(drv.analogRead(1));
		cout << spannungSourceDrain << "," << stromDrain  << endl;
	}
	drv.analogWrite1(0);
	drv.analogWrite0(0);
}
