#include <iostream>
#include <b15f/b15f.h>
#include <b15f/plottyfile.h>


using namespace std;

int main()
{
	
	B15F& drv = B15F::getInstance();
	drv.analogWrite0(0);
	
	//Plot-Beschriftung
    PlottyFile pf;
	pf.setUnitY("mA");
	pf.setUnitX("V");
	pf.setDescX("U");
	pf.setDescY("I");
	pf.setUnitPara("");
	pf.setDescPara("");
	pf.setRefX(5);
	pf.setRefY(5);
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite0(i);
		int messung = drv.analogRead(0); // Spannung
		pf.addDot(Dot(i-messung, messung, 1)); // mA
	}
	drv.analogWrite0();
    pf.writeToFile("plot.bin");
    pf.startPlotty("plot.bin");
}
