/*
 * i2c.c
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<linux/i2c-dev.h>
#include<inttypes.h>

struct temp_t {
	uint16_t roomcal;
	uint16_t hotcal;
	uint16_t adcal;
	uint16_t v;
	uint8_t room;
	uint8_t hot;
};

int main(int argc, char *argv[])
{
	int fd = 0;
	int i = 0;
	char filename[40]; //= NULL;
	unsigned char buff[10];// = NULL;
	char addr = 0x41;
	struct temp_t temp;
	//uint16_t = data;// = 0;

	sprintf(filename,"/dev/i2c-1");
	if ((fd = open(filename, O_RDONLY)) < 0){
		perror("open:");
		exit(1);
	}

	if (ioctl(fd,I2C_SLAVE,addr) < 0){
		perror("ioctl:");
		close(fd);
		exit(1);
	}

	for (i = 0; i < 30; i++){
		if (read(fd,&buff,10) != 10){
			printf("unable to read data\n");
			close(fd);
		} else {
			temp.roomcal = ((uint16_t)buff[0] << 8) + buff[1];
			temp.hotcal = ((uint16_t)buff[2] << 8) + buff[3];
			temp.adcal = ((uint16_t)buff[4] << 8) + buff[5];
			temp.v = ((uint16_t)buff[6] << 8) + buff[7];
			//printf("Roomcal = %d\n", temp.roomcal);
			//printf("Hotcal = %d\n", temp.hotcal);
			//printf("Adcal = %d\n", temp.adcal);
			printf("Temp = %d\n", temp.v);
			sleep(1);
			//data = (unsigned int)buff[0];
			//data = (data << 8) + (unsigned int)buff[1];
			//printf("Data: %02d\n",data);
		}
	}

	close(fd);
	return 0;

}
