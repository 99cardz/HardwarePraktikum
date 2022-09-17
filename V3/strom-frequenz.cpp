#include <iostream>
#include <b15f/b15f.h>
#include <string>
using namespace std;

// aus serialctl.cpp von HWP1
int open_port(void)
{
  int fd; /* File descriptor for the port */
	struct termios options;

  fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
    cout<<"open_port: Unable to open \n";
  }
  else {
  	// setting terminal options
    fcntl(fd, F_SETFL, FNDELAY);
		tcgetattr(fd, &options);
		cfsetispeed(&options, B115200);
		cfsetospeed(&options, B115200);
		options.c_cflag |= (CLOCAL | CREAD);
		options.c_cflag &= ~PARENB;
		options.c_cflag &= ~CSTOPB;
		options.c_cflag &= ~CSIZE;
		options.c_cflag |= CS8;
		tcsetattr(fd, TCSANOW, &options);
  	return (fd);
  }
  return 0;
}

void writeAndMeasure(int f, B15F& drv, int fd) {
	string str = string(":w21=5.\r\n:w23=") + to_string(f) + string("00,0.\r\n");
	char write_buffer[32];
	strcpy(write_buffer, str.c_str());
	write(fd, write_buffer , 32);
	int sum1 = 0;
	for (int i = 0; i < 200; i++)
		sum1 += drv.analogRead(1);
	cout << f << "," << (int) sum1 / 200 << endl;
}

int main(){
	B15F& drv = B15F::getInstance();
	int fd = open_port();
	
	for (double frequenz = 1000; frequenz < 1000000.0; frequenz *= 1.15)
		writeAndMeasure((int) frequenz, drv, fd);
}
