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
	bool var = false;
	drv.analogWrite0(1023);
	while (true) {
		drv.analogWrite1((int)var*1023);
		var = not var;
		drv.delay_ms(5000);
		cout << var << endl;
	}	
}
