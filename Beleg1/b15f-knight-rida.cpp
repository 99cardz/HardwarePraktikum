#include <b15f/b15f.h>
#include <iomanip>

using namespace std;

void knight(B15F& drv) {
	while (drv.readDipSwitch() % 2 == 0) {
		int speed = (int) drv.readDipSwitch();
		for (int i = 0; i < 7; i++) {
			drv.digitalWrite0(0b11100000 >> i);
			if (speed) drv.delay_ms(speed);
		}
		for (int i = 0; i < 7; i++) {
			drv.digitalWrite0(0b00000111 << i);
			if (speed) drv.delay_ms(speed);
		}
	}
}

int main() {
	B15F& drv = B15F::getInstance();
	int dip = int(drv.readDipSwitch());
	int command = dip % 2;
	cout << (command ? "invert" : "knight") << endl;
	switch (command) {
		case 0: knight(drv); break;
		case 1: drv.digitalWrite0(~dip); break;
	}
 }
