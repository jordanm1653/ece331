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

#define BUFF_SIZE 10

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
	char filename[40];
	unsigned char buff[BUFF_SIZE];
	char addr = 0x41;
	struct temp_t temp;

	sprintf(filename,"/dev/i2c-1");

	/*
	 * Open device file
	 */
	if ((fd = open(filename, O_RDONLY)) < 0){
		perror("open:");
		exit(EXIT_FAILURE);
	}

	/*
	 * ioctl to initialize device as slave
	 */
	if (ioctl(fd,I2C_SLAVE,addr) < 0){
		perror("ioctl:");
		close(fd);	/* close file on failure */
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 30; i++){	/* iterate for 30 seconds */
		/*
		 * read from i2c device
		 */
		if (read(fd,&buff,BUFF_SIZE) != BUFF_SIZE){
			printf("unable to read data\n");
			close(fd);
		} else {
			/*
			 * assign values from i2c data to items in temp
			 */
			temp.roomcal = ((uint16_t)buff[0] << 8) + buff[1];
			temp.hotcal = ((uint16_t)buff[2] << 8) + buff[3];
			temp.adcal = ((uint16_t)buff[4] << 8) + buff[5];
			temp.v = ((uint16_t)buff[6] << 8) + buff[7];
			temp.room = (uint8_t)buff[8];
			temp.hot = (uint8_t)buff[9];

			/*
			 * Raw temperature value
			 */
			printf("Raw Temp = %d\n", temp.v);

			sleep(1);	/* Delay 1 second */
		}
	}

	close(fd);
	return 0;

}
