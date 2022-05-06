#include <iostream>
#include <b15f/b15f.h>

using namespace std;

int main(int count, char** args)
{
	B15F& drv = B15F::getInstance();
	
	while (true) {
		for (int p : {2,3,5,7,11,13,17,19}) {
			drv.analogWrite0(p * 1023.0 / 50.0);
			drv.delay_ms(2500);
		}
			
	}
	
    
}
