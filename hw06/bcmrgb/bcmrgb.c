/* 
 * bcmrgb
 *
 * Communicate with xmega RPi Expansion Board using the bcm2835 library
 * to access the RPi GPIO pins
 *
 * Jordan Millington
 * 02/25/2015
 *
 * ECE 331 - Homework 6.1
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<bcm2835.h>
#include<unistd.h>
#include<errno.h>
#include<limits.h>

/* 
 * RPI Expansion PINOUT
 *
 * Clock ->	GPIO 25 (pin 22)
 * Red	 ->	GPIO 22 (pin 15)
 * Green ->	GOIO 23 (pin 16)
 * Blue  ->	GPIO 24 (pin 18)
 */
/* Define GPIO pins for bcm2835.h */
#define CPIN	RPI_GPIO_P1_22
#define RPIN	RPI_GPIO_P1_15
#define GPIN	RPI_GPIO_P1_16
#define BPIN	RPI_GPIO_P1_18

int main(int argc, char *argv[])
{
	/* Variables */
	const unsigned char BITLEN = 11;
	unsigned int i = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	int dc_red = 0;
	int dc_green = 0;
	int dc_blue = 0;

	/* Get input and verify */
	if (argc != 4 ){
		printf("Usage: %s [Red 0-2048] [Green 0-2048]"
		       "[Blue 0-2048]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	r = atoi(argv[1]);
	g = atoi(argv[2]);
	b = atoi(argv[3]);

	if ((r > 2048) || (g > 2048) || (b > 2048)){
		printf("Usage: %s [Red 0-2048] [Green 0-2048]"
		       "[Blue 0-2048]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	dc_red = 0x7FF - r;
	dc_green = 0x7FF - g;
	dc_blue = 0x7FF - b;

	/* Initialization */
	if(!bcm2835_init()){
		perror("bcm2835: ");
		exit(EXIT_FAILURE);
	}

	/* Set GPIO pins to be outputs */
	bcm2835_gpio_fsel(CPIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(RPIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(GPIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(BPIN, BCM2835_GPIO_FSEL_OUTP);

	/* Set clock low */
	bcm2835_gpio_write(CPIN, LOW);

	/* Read RGB duty cycle values */


	/* Shift out duty cycles for R G and B */
	for(i = 0; i < BITLEN; i++){
		//RED
		if(dc_red & 0x700){
			bcm2835_gpio_write(RPIN, HIGH);
		}else{
			bcm2835_gpio_write(RPIN, LOW);
		}
		//GREEN
		if(dc_green & 0x700){
			bcm2835_gpio_write(GPIN, HIGH);
		}else{
			bcm2835_gpio_write(GPIN, LOW);
		}
		//BLUE
		if(dc_blue & 0x700){
			bcm2835_gpio_write(BPIN, HIGH);
		}else{
			bcm2835_gpio_write(BPIN, LOW);
		}

		//Make sure clock is low
		bcm2835_gpio_write(CPIN, LOW);
		usleep(10);
		bcm2835_gpio_write(CPIN, HIGH);
		usleep(10);
		bcm2835_gpio_write(CPIN, LOW);

		/* Shift bits */
		dc_red <<= 1;
		dc_green <<= 1;
		dc_blue <<= 1;
	}

	bcm2835_close();

	return EXIT_SUCCESS;
}
