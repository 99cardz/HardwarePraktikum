#include <iostream>
#include <b15f/b15f.h>

using namespace std;

int main(int count, char** args)
{
	double num = count > 1 ? stod(args[1]) : 3.1415;
	// 5V -> 1023
	// 0V -> 0
	double wert = num * 1023.0 / 5.0;
	B15F& drv = B15F::getInstance();

    drv.analogWrite0(wert);
    cout << "input: " << num << " wert: " << wert << endl;
    
}
