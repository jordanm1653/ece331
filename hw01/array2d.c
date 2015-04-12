/*
 * array2d.c
 *
 * Jordan Millington
 * Homework 1:3
 * ece331
 * 
 * Last Modified:
 * 01/22/2015 
 */
#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>

void print_usage()
{
	printf("Usage: array2d -m [M_NUM] -n [N_NUM]\n");
	printf("\tM_NUM:\tnumber of rows (integer > 0)\n");
	printf("\tN_NUM:\tnumber of columns (integer > 0)\n");
}
int main(int argc, char *argv[])
{
	int c = 0;
	char *rows;
	char *columns;
	char *pEndr;
	char *pEndc;
	/* Expected Options */
	static struct option long_options[] = {
		{"rows",	required_argument,	0,	'm'	},
		{"columns",	required_argument,	0,	'n'	},
		{0,	0,	0,	0}
	};
	int option_index = 0;

	if (argc < 3)
		print_usage();

	while ((c = getopt_long(argc, argv, ":m:n:", long_options,
				&option_index)) != -1)
	{
		switch (c){
		case 'm':
			//rows =atoi(optarg);
			rows = optarg;
			break;
		case 'n':
			//columns = atoi(optarg);
			columns = optarg;
			break;
		default:
			print_usage();
			exit (EXIT_FAILURE);
		}
	}

	/* Validity Checking */
	int res_rows = strtol(rows, &pEndr, 10);
	int res_columns = strtol(columns, &pEndc, 10);
	if ((*pEndr) || (*pEndc) || (res_rows < 1) || (res_columns < 1)){
		printf("!! Invalid arguments !!\n");
		print_usage();
		return EXIT_FAILURE;
	}
	int i = 0;
	int j = 0;
	double **arr2d;
	arr2d = (double**) malloc(res_rows * sizeof(double*));
	for (i = 0; i < res_rows; i++){
		arr2d[i] = (double*) malloc(res_columns *sizeof(double));
	}
	for (i = 0; i < res_rows; i++){
		for (j = 0; j < res_columns; j++){
			printf("%f ",arr2d[i][j]);
		}
		printf("\n");
	}

	/* Free allocated memory */
	for (i = 0; i < res_rows; i++){
		free(arr2d[i]);
	}
	free(arr2d);
	return 0;
}
