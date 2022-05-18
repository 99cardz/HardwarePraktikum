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
	pf.setDescY("U");
	pf.setRefX(1023 / 10);
	pf.setRefY(5);
	pf.setParaFirstCurve(0);
	pf.setParaStepWidth(0);
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite0(i);
		drv.delay_ms(100);
		int messung = drv.analogRead(0);
		cout << messung*5.0/1023.0 << " - " << i*5.0/1023.0 << endl;
		pf.addDot(Dot(i, messung, 1));
	}
    pf.writeToFile("plot.bin");
    pf.startPlotty("plot.bin");
}
