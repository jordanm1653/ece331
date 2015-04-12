/*
 * fsum.c
 *
 * Jordan Millington
 * Homework 2:2
 * ece331
 */

/* Pre-processor Includes */
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

/* Usage Function */
void print_usage()
{
	printf("\nUsage: fsum <file 1> <file 2> <file ...>\n");
	printf("\t<file (#)>:\tFilename\n\n");
	printf("Only regular files accepted!\n\n");
}
int main(int argc, char *argv[])
{
	struct stat sb;
	int i = 0;
	long long sum_fsize = 0;
	/* Validity Checking */
	if (argc < 2){
		printf("\nMust pass atleast 1 file!\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++){
		if ((stat(argv[i], &sb)) == -1){
			perror("stat");
			exit(EXIT_FAILURE);
		}else if ((sb.st_mode & S_IFMT) != S_IFREG){
			printf("Error: \"%s\" is not an acceptable filetype\n",
			       argv[i]);
			print_usage();
			exit (EXIT_FAILURE);
		}else{
			sum_fsize = sum_fsize + ((long long) sb.st_size);
		}
	}

	printf("%lld\n", sum_fsize);


	return 0;
}
