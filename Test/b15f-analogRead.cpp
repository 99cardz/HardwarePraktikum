#include <iostream>
#include <b15f/b15f.h>

// plot adc values to terminal

int main()
{
	
	B15F& drv = B15F::getInstance();

    while(1)
    {
		std::cout << "POTI 6: " << drv.analogRead(6) * 5.0 / 1023.0 << "V POTI 7: " << drv.analogRead(7) * 5.0 / 1023.0 << "V"<< std::endl;        
		drv.delay_ms(40);
    }
    
}
