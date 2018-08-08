
#include <stdio.h> // standard input and output library
#include <stdlib.h> // this includes functions regarding memory allocation
#include <string.h> // contains string functions
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <time.h> //contains various functions for manipulating date and time
#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <sys/select.h>
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <sys/ioctl.h>
int deviceHandle;
int readBytes;
uint8_t scratchpad[9]={0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int deviceI2CAddress = 0x5d;
struct scratchpad {
	uint8_t temp0;
	uint8_t temp1;
	uint8_t temphigh;
	uint8_t templow;
	uint8_t configuration;
	uint8_t crc;
};
using namespace std;
int readi2c(int& devhndl,struct scratchpad&);
int printscratchpad(struct scratchpad& scrth);
int main()
{

    int server_socket = 0, clientfd = 0;
    struct sockaddr_in server_address;
    struct  scratchpad scratch;
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // creating socket
    memset(&server_address, '0', sizeof(server_address));
    memset(scratchpad, '0', sizeof(scratchpad));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(2017);         // this is the port number of running server
    bind(server_socket, (struct sockaddr*)&server_address , sizeof(server_address));
    listen(server_socket , 20);
    if ((deviceHandle = open("/dev/i2c-1", O_RDWR)) < 0)
    	{
    		printf("Error: Couldn't open device! %d\n", deviceHandle);
    		return 1;
    	}
    	if (ioctl(deviceHandle, I2C_SLAVE, deviceI2CAddress) < 0)
    	{
    		printf("Error: Couldn't find device on address!\n");

    	}
    while(1)
    {

        clientfd = accept(server_socket, (struct sockaddr*)NULL, NULL);
        cout<<"Some client requested data"<<endl;
        int i=readi2c(deviceHandle,scratch);
        if (i<0){cout<<"Data not recived"<<endl;}
       // clock = time(NULL);
        write(clientfd, scratchpad, sizeof(scratchpad));
        close(clientfd);
        sleep(1);
     }

     return 0;
}
int readi2c(int& devhndl,struct scratchpad& sp)
{
	readBytes = read(devhndl, scratchpad, 9);
		if (readBytes != 9)
		{
			printf("Error: Received no data!");
			return -1;
		}
		else
		{
			sp.temp0=scratchpad[1];
			sp.temp1=scratchpad[0];
			sp.temphigh=scratchpad[2];
			sp.templow=scratchpad[3];
			sp.configuration=scratchpad[4];
			sp.crc=scratchpad[5];
			printscratchpad(sp);
		}

		return 0;
}
int printscratchpad(struct scratchpad& sc)
{

	printf(" ---------------------------\n");
	printf("|  DS1482 scratchpad values: |\n");
	printf(" ---------------------------\n");
	printf("|temperature is:      | %02x |\n",sc.temp0 );
	printf(" ---------------------------\n");
	printf("|temperature is:      | %02x |\n",sc.temp1 );
	printf(" ---------------------------\n");
	printf("|High temp reg	      | %02x |\n",sc.temphigh );
	printf(" ---------------------------\n");
	printf("|Low temp reg	      | %02x |\n",sc.templow );
	printf(" ---------------------------\n");
	printf("|Config register      | %02x |\n",sc.configuration );
	printf(" ---------------------------\n");
	printf("|reserved register    | %02x |\n",scratchpad[5] );
	printf(" ---------------------------\n");
	printf("|reserved register    | %02x |\n",scratchpad[6] );
	printf(" ---------------------------\n");
	printf("|reserved register    | %02x |\n",scratchpad[7] );
	printf(" ---------------------------\n");
	printf("|CRC:                 | %02x |\n",sc.crc );
	printf(" ---------------------------\n");
	return 0;
}
