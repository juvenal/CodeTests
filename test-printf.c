#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	double i = 9999999.99;
	char cc = 'C';

	if (printf("Speed is [%09.9d]\n", (int)ceil(floor(i * 100))) < 0) {
		printf("Error on printf 1!\n");
	}

	if (printf("Contract code right: [%20.20c]\n", cc) < 0) {
		printf("Error on printf 2!\n");
	}

	if (printf("Contract code left: [%-20.20c]\n", cc) < 0) {
		printf("Error on printf 2!\n");
	}

	return 0;
}
