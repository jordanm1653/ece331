/*
 * slptmr.c
 *
 * Print the seconds system time elapsed during a call to sleep(1)
 *
 * Jordan Millington
 * 02/10/2015
 *
 * Compiling:
 *	must link -lbcm2835
 *	gcc -lbcm2835 -Wall -g slptmr.c -o slptmr
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<bcm2835.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	/* Declare Variables */
	double syshz = 1000000;
	double systimestart = 0;
	double systimeend = 0;
	double elapsed_time = 0;

	/* Initialize bcm2835 library and check for errors */
	if(!bcm2835_init()){
		perror("bcm2835");
		exit(EXIT_FAILURE);
	}

	/* get system time
	 * sleep for 1 second
	 * get system time after sleep
	 * calculate difference of system time in seconds
	 */
	systimestart = (double) bcm2835_st_read();
	sleep(1);
	systimeend = (double) bcm2835_st_read();
	elapsed_time = (systimeend - systimestart)/syshz;

	printf("Sleep(1) elapsed time: %f seconds\n",elapsed_time);

	/* Close the library deallocating any allocated memory */
	bcm2835_close();
	return EXIT_SUCCESS;
}
