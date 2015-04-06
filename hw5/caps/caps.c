/*
 * caps.c
 *
 * Program to have child print input string in all caps 
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
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>
#include<regex.h>

int main(int argc, char *argv[])
{
	/* Declare Variables */
	int pipefd[2] = {0};
	pid_t child_pid = -1;
	int ret = 0;
	char buf = NULL;
	char line[4096] = {NULL};
	regex_t re;
	regmatch_t rm[256];

	/* Check command line arguments */
	if (argc != 2){
		printf("USAGE: %s <string>\n", argv[0]);
		printf("\n");
		exit(EXIT_FAILURE);
	}

	/* Pipe */
	if (pipe(pipefd) == -1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	/* Create a child process */
	child_pid = fork();
	if (child_pid < 0){
		perror("Fork: ");
		exit(EXIT_FAILURE);
	}

	/* Parent Process */
	if (child_pid != 0){
		ret = regcomp(&re, "/\bquit\b | \bexit\b | \bbye\b/",
			      REG_ICASE);
		while(!feof(stdin)){
			fgets(line,4096,stdin);

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
