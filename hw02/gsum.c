/*
 * gsum.c -- print total number of bytes used by files returned from a
 * single glob passed on the command line
 *
 * Jordan Millington
 * Homework 2:3
 * ece331
 *
 * Last Modified:
 * 01/29/2015
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<glob.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Usage Function */
void print_usage(char **argv)
{
	printf("Usage: %s \"<glob>\"\n", argv[0]);
}
int main(int argc, char *argv[])
{
	/* declare glob struct */
	glob_t globbuf;
	/* declare stat struct */
	struct stat sb;
	long long fsum = 0;
	int i = 0;

	if (argc != 2){
		print_usage(argv);
		exit(EXIT_FAILURE);
	}

	if((glob(argv[1], 0, NULL, &globbuf)) != 0){
		perror("glob");
		exit(EXIT_FAILURE);
	}

	/* Pass glob files to stat() and check for errors */
	for (i = 0; i < globbuf.gl_pathc; i++){
		if ((stat(globbuf.gl_pathv[i], &sb)) == -1){
			perror("stat");
			exit(EXIT_FAILURE);
		/* Only accept regular filetypes */
		}else if ((sb.st_mode & S_IFMT) != S_IFREG){
			printf("Error: \"%s\" is not an acceptable filetype\n",
			       globbuf.gl_pathv[i]);
			print_usage(argv);
			exit (EXIT_FAILURE);
		}else{
			fsum += ((long long) sb.st_size);
		}
	}
	printf("%lld\n", fsum);

	/* Free memory from glob_t */
	globfree(&globbuf);

	return (EXIT_SUCCESS);
}
