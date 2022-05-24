#include <iostream>
#include <b15f/b15f.h>
#include <b15f/plottyfile.h>


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
	drv.analogWrite0(0);
	
	//Plot-Beschriftung
    PlottyFile pf;
	pf.setUnitY("mA");
	pf.setUnitX("V");
	pf.setDescX("U_{Gate}");
	pf.setDescY("I_{Drain}");
	pf.setUnitPara("");
	pf.setDescPara("");
	pf.setRefX(5);
	pf.setRefY(1);
	
	//for (double voltage : {0.0,1.0,2.0,2.5,3.0,4.0,5.0}) {
	for (double voltage = 2.0; voltage < 4.1; voltage += 0.5) {
		
		int analogValue = toAnalogValue(voltage);
		cout << "voltage: "<<voltage << " analogV: "<< analogValue << endl;
		
		drv.analogWrite1(analogValue);
		
		
		for (int i = 0; i < 1023; i += 50) {
			drv.analogWrite0(i);
			int amp = (drv.analogRead(0) - drv.analogRead(1)) ;
			cout << "supplying to drain: " << i << " reading at drain:  " << amp << endl;
			pf.addDot(Dot(drv.analogRead(1), amp, (int) voltage * 10)); // mA
		}
		
		
	}
	drv.analogWrite0(0);
    pf.writeToFile("plot.bin");
    pf.startPlotty("plot.bin");
}
