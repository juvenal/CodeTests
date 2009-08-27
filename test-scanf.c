#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int debug = 0;
	extern int optind;
	extern char *optarg;
	char *options, *value, filename[1024], c;
	FILE fp;

	while ((c = getopt(argc, argv, "df:")) >= 0) {
		switch (c) {
			case 'd':
				debug = 1;
				break;
			case 'f':
				strcpy(filename, optarg);
				break;
			default
				printf("Unknown option %c found!\n", c);
				exit(1);
		}
	}
	if ((fp = fopen(filename, "r")) == NULL) {
		perror("Error reading the input file!\n");
		exit(1);
	}

	if ((fclose(fp)) == EOF) {
		perror("Error closing the input file!\n");
		exit(1);
	}
}
