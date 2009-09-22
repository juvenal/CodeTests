#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void printInfo() {

}

void printUsage() {

}

int main(int argc, char *argv[]) {
	int debug = 0, size;
	extern int optind, opterr, optopt;
	extern char *optarg;
	char *options, *value, filename[1024], c;
	char name[100], data[20];
	int val1, val2, val3;
	FILE *fp;

	/* Validating number of parameters */
	if (argc < 2) {
		printInfo();
		printf("No parameters sent. Please inform the required parameters!\n");
		printUsage();
		exit(1);
	}

	/* Reading parameters from console */
	while ((c = getopt(argc, argv, "df:")) >= 0) {
		switch (c) {
			case 'd':
				debug = 1;
				break;
			case 'f':
				strcpy(filename, optarg);
				break;
			default:
				printf("Unknown option %c found!\n", c);
				exit(1);
		}
	}

	/* Open the given filename */
	if ((fp = fopen(filename, "r")) == NULL) {
		perror("Error reading the input file!\n");
		exit(1);
	}

	/* read the formatted content */
	while ((size = fscanf(fp, "%s|%u|%u|%u|%s\n", name, &val1, &val2, &val3, data)) != EOF) {
		/* Process and print the aquired data */
		if ((size = printf("Name: %s\nDate: %s\nTotal: %u\n\n", name, data, val1 + val2 + val3)) < 0) {
			perror("Error printing the result output!\n");
			exit(1);
		}
	}

	/* Close the opened file */
	if ((fclose(fp)) == EOF) {
		perror("Error closing the input file!\n");
		exit(1);
	}
	exit(0);
}
