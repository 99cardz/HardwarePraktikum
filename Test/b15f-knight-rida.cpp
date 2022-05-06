#include <b15f/b15f.h>
#include <iomanip>

using namespace std;

int main() {
	B15F& drv = B15F::getInstance();
	int delay = 20;
	while (true) {
		if (drv.readDipSwitch() > 0) {
			int digitalInput = drv.digitalRead0();
			drv.digitalWrite0(~digitalInput);
			if (delay) drv.delay_ms(delay);
		} else {
			for (int i = 0; i < 7; i++) {
				drv.digitalWrite0(0b11100000 >> i);
				if (delay) drv.delay_ms(delay);
			}
			for (int i = 0; i < 7; i++) {
				drv.digitalWrite0(0b00000111 << i);
				if (delay) drv.delay_ms(delay);
			}
		}
	}
 }
