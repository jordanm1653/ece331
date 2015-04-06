/*
 * zombie.c
 *
 * Program to make a zombie process that dies after roughly 10 seconds
 *
 * Jordan Millington
 * 02/17/2015
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	/* Declare Variables */
	pid_t child_pid = -1;
	int ret = 0;

	/* Check command line arguments */
	if (argc > 1){
		printf("USAGE: %s\n", argv[0]);
		printf("\n");
		printf("This program does not take any arguments!\n\n");
		exit(EXIT_FAILURE);
	}

	/* Informational purposes */
	printf("The main program process ID is: %d\n", (int) getpid());

	/* Create a child process */
	child_pid = fork();
	if (child_pid < 0){
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}

	/* Parent Process */
	if (child_pid != 0){
		ret = kill(child_pid, SIGTERM);
		if (ret < 0){
			perror("Kill: ");
		}
		sleep(10);
	}
	/* Child Process */
	else{
		printf("This is the child proccess, with ID: %d\n",
		       (int) getpid());
	}

	return EXIT_SUCCESS;
}
