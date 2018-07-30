
#include "/home/tarak/rpi/meta-lpc/recipes-i2ctemperature/i2ctemp/files/inc/wiringPiI2C.h"
#include <stdio.h>

int main()
{
   int fd, result;

   fd = wiringPiI2CSetup(0x5d);


   for(int i = 0; i < 5; i++)
   {
      int a=0x54;
      result = wiringPiI2CWriteReg8(fd, a,0x55);
        printf("value is:%s\n",result );

   }
}
