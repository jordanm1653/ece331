/*
 * mnarray.c
 *
 * Description:
 * Creates a 2-d array of doubles that is m rows by n columns specified
 * by command line arguments
 * 
 * Jordan Millington
 * ECE 331 - HW_1_3
 */

#include<stdio.h>
#include<stdlib.h>

void help(void)
{
	printf("Usage: \n");
}

int main(int argc, char *argv[])
{
	int dim[argc] = {0};
	int i = 0;
	int j = 0;
	if (argc > 3){
		help();
		return EXIT_FAILURE;
	}
	int args = argc - 1;
	for (i = 0; i < argc; i++){
		dim[i] = atoi(argv[i+1]);
		if (dim[i] < 1){
			printf("Not a valid integer!\n");
			help();
			return EXIT_FAILURE;
		}
	}
	double arr[dim[1]][dim[2]] = {{0}};
	for (i = 0;i < 2; i++){
		for (j = 1; j < 2; j++){
		       printf("%d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
