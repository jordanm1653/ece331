/*
 * Jordan Millington 02/04/2015
 *
 * swa.c
 *
 * read unsigned integer from stdin values 0-255 then compute a sliding
 * window average on data stream with a window of 8. Print average values
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>

int main(int argc, char *argv[])
{
	int window[8] = {0};
	int i = 0;
	double avg = 0;
	unsigned int num = 0;
	int nwin = 8;
	double sum = 0;
	int count = 0;
	FILE *fd = NULL;

	fd = fopen("nums.txt","r");
	if(fd<0){
		perror("open");
		exit (EXIT_FAILURE);
	}
	while (!feof(fd)){
		fscanf(fd,"%u",&num);
		if (count < nwin){
			window[count] = num;
		}
		else{
			for (i = 0; i < nwin; i++){
				sum = sum + window[i];
			}
			avg = sum/(double)nwin;
			printf("%f\n",avg);
			sum = 0;
			window[count%nwin] = num;
		}
		count++;
	}
	fclose(fd);
	return 0;
}
