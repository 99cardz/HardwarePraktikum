#include <iostream>
#include <b15f/b15f.h>

using namespace std;

int main()
{
	B15F& drv = B15F::getInstance();
	
	for (int i = 0; i < 1023; i += 10) {
		drv.analogWrite0(i);
		cout << (drv.analogRead(0) * 5.0 / 1023.0) << endl;
	}
	drv.analogWrite0(0);
}
