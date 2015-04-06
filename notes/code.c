/*
 * Name Date
 * What this is
 */

#include<stdio.h>
unistd.h
fcntl.
sys/types
std.int.h
math.h
sys/stat.h
errno.h

int main(int argc, char *argv[])
{
	float *f, *r;
	int err = 0;//every varinle is init with a known val
	int fd = 0;
	FILE *fh=NULL;
	char line[4096];
	char *line; //<-BAD (alone needs malloc)casuses segfault
	line=(char *)malloc(sizeof(char)*4096);h

	fh=open("myfile",O_RDONLY);
	if (fd<0){
		perror("open");
		return 1;
	}
	while(!feof(fh)){
		sscanf(line,"%u %u %u %u",&td->hotcal,&td->roomcal,&td->hottemp,
		       &td->roomtemp,&td->temp);
		fgets(line,4096,fh);
		printf("%s",file);
	}
	close(fd);

	//access structure through pointers
	struct tempdata{
		uint16_t hotcal;
		uint16_t roomcal;
		uint16_t hottemp;
		uint16_t roomtemp;
		uint16_t temp;
		};
	struct tempdata *td=NULL;
	td=malloc(sizeof(stuct tempdata));
	if (td==NULL){
		perror("malloc(td)");
		free(td);
		exit(EXIT_FAILURE);
	}


}
