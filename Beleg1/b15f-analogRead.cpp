#include <iostream>
#include <b15f/b15f.h>

// plot adc values to terminal

int main()
{
	
	B15F& drv = B15F::getInstance();

    while(1)
    {
		std::cout << drv.analogRead(7) << std::endl;        
		drv.delay_ms(25);
    }
    
}
