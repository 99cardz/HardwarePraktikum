#include <stdio.h>   /* Standard input/output definitions */
#include <iostream> 
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <string>
using namespace std;
#define WR_BUFFER_LEN 32
#define RD_BUFFER_LEN 32

/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */

int
open_port(void)
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

/*
*
*main function
*/
int main(int count, char** params){
	/*
	uint8_t write_buffer[WR_BUFFER_LEN];
	string buff = ":w2";
	bool isChannel1 = params[1] == "1";
	if (params[2] == "square") {
		buff += string(isChannel1 ? "1" : "2") += string("=1.\r\n");
	} else if (params[2] == "sin") {
		buff += string(isChannel1 ? "1" : "2") += string("=0.\r\n");
	} else if ((isdigit(atoi(params[2])))) {
		buff += string(isChannel1 ? "3" : "4") += string("=") += to_string(atoi(params[2])) += string("00,0.\r\n");
	}
	write_buffer = buff.c_str();*/
	int fd,n;
	//:w21=1 set waveform to square
	uint8_t write_buffer[WR_BUFFER_LEN] = ":w24=700000,0.\r\n";
	uint8_t read_buffer[RD_BUFFER_LEN];
	fd=open_port();
	n = write(fd, write_buffer, WR_BUFFER_LEN);
	if (n < 0){ 
		cout<<"write() failed!\n";
	}else{
		cout<<"write done\n";
	}
	read(fd,read_buffer,RD_BUFFER_LEN);// get answer from function generator
	cout << read_buffer<< endl;
	close(fd);
}
