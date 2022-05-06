#include <b15f/b15f.h>
#include <iomanip>

using namespace std;


int main() {
	B15F& drv = B15F::getInstance();
	while (true) {
		cout << "Poti AE6: " << drv.analogRead(6) << " Poti AE7: " << drv.analogRead(7) << endl; 
		drv.delay_ms(100);
	}
	
	
 }
