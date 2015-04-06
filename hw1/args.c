/*
 * args.c
 *
 * Description: A program to demonstrate passing command line arguments
 * by printing all passed arguments
 *
 * Jordan Millington
 * Homework 1:2
 * ece331
 *
 * Last Modified:
 * 01/21/2015
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if (argc < 2){
		printf("\tUsage: ./args [FILE]\n");
	}else{
		printf("Number of arguments passed to the main function:"
			"%d\n",argc);
		for(i=0;i<argc;i++){
		printf("Argument number %d is %s\n",i,argv[i]);
		}
	}
	return 0;
}
