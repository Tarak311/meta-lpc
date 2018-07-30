#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int main (void)
{
	int deviceHandle;
	int readBytes;
char buffer[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	// initialize buffer
	buffer[0] = 0x55;
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
	//readBytes = write(deviceHandle, buffer, 1);
	//if (readBytes != 1)
	//{
	//	printf(readBytes);
//	}
	readBytes = read(deviceHandle, buffer, 7);
	if (readBytes != 7)
		{
			printf("Error: Received no data!");
		}
		else {	printf(" Received  data!");}
		printf("value is %02x\n",buffer[2] );
		printf("value is %02x\n",buffer[3] );
		printf("value is %02x\n",buffer[1] );
		printf("value is %02x\n",buffer[0] );
	// close connection and return
	close(deviceHandle);
	return 0;
}
