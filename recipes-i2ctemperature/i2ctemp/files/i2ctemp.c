#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

int main (void)
{
	int deviceHandle;
	int readBytes;
  char buffer[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  buffer[0] = 0x55;
  int deviceI2CAddress = 0x5d;
	if ((deviceHandle = open("/dev/i2c-1", O_RDWR)) < 0)
  {
		printf("Error: Couldn't open device! %d\n", deviceHandle);
		return 1;
	}
	if (ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress) < 0)
    {
			printf("Error: Couldn't find device on address!\n");

		}

 //readBytes = write(deviceHandle, buffer, 1);
 readBytes = read(deviceHandle, buffer, 9);
 if (readBytes != 9)
	{
		printf("Error: Received no data!");
	}
 else
 {
	 printf(" ---------------------------\n");
	 	printf("| DS1482 scratchpad values:	|\n");
		printf(" ---------------------------\n");
		printf("|temperature is:     | %02x |\n",buffer[1] );
		printf(" ---------------------------\n");
	  printf("|temperature is:     | %02x |\n",buffer[0] );
		printf(" ---------------------------\n");
	  printf("|High temp reg			 | %02x |\n",buffer[2] );
		printf(" ---------------------------\n");
	  printf("|Low temp reg				 | %02x |\n",buffer[3] );
		printf(" ---------------------------\n");
	  printf("|Config register     | %02x |\n",buffer[4] );
		printf(" ---------------------------\n");
	  printf("|reserved register   | %02x |\n",buffer[5] );
		printf(" ---------------------------\n");
	  printf("|reserved register   | %02x |\n",buffer[6] );
		printf(" ---------------------------\n");
	  printf("|reserved register   | %02x |\n",buffer[7] );
		printf(" ---------------------------\n");
	  printf("|CRC:                | %02x |\n",buffer[8] );
		printf(" ---------------------------\n");
 }

 close(deviceHandle);
 return 0;
}
