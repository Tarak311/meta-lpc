#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int main (void)
{

	int deviceHandle;
	int readBytes;
	char buffer[7];

	// initialize buffer
	buffer[0] = 0x55;

	// address of DS1307 RTC device
	int deviceI2CAddress = 0x5d;

	// open device on /dev/i2c-0
	if ((deviceHandle = open("/dev/i2c-0", O_RDWR)) < 0) {
		printf("Error: Couldn't open device! %d\n", deviceHandle);
		return 1;
	}

	// connect to DS1307 as i2c slave


	// begin transmission and request acknowledgement
	readBytes = write(deviceHandle, buffer, 1);
	if (readBytes != 1)
	{
		printf("Error: Received no ACK-Bit, couldn't established connection!");
	}
	else
	{
		// read response
		readBytes = read(deviceHandle, buffer, 7);
		if (readBytes != 7)
		{
			printf("Error: Received no data!");
		}


	// close connection and return
	close(deviceHandle);
	return 0;
}
