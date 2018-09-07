#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int main (int argc, char *argv[])
{
	if(argc==1){printf(" No arguments passed\n");}

	int deviceHandle;
	int readBytes;
char buffer[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	if(argv[1]=="relayoff")
	{
		buffer[0] = 0x44;
	}
	else if (argv[1]=="relayon")
	{
		buffer[0] = 0x55;
	}

	// initialize buffer


	// address of DS1307 RTC device
int deviceI2CAddress = 0x5d;

	// open device on /dev/i2c-0
	if ((deviceHandle = open("/dev/i2c-1", O_RDWR)) < 0) {
		printf("Error: Couldn't open device! %d\n", deviceHandle);
		return 1;
	}

	if (ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress) < 0) {
			printf("Error: Couldn't find device on address!\n");

		}

	// begin transmission and request acknowledgement
	readBytes = write(deviceHandle, buffer, 1);


	// close connection and return
	close(deviceHandle);
	return 0;
}
