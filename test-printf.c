/*
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
	double i = 9.60,
		   d = 10.25;
	char cc = 'C';

	if (printf("Speed is [%9.9d]\n", (int)ceil(floor(i * 100))) < 0) {
		printf("Error on printf 1!\n");
	}

	if (printf("Speed is [%9.9d]\n", (int)round(i * 100)) < 0) {
		printf("Error on printf 2!\n");
	}
	if (printf("Speed is [%9.9d]\n", (int)ceil(floor(d * 100))) < 0) {
		printf("Error on printf 1!\n");
	}

	if (printf("Speed is [%9.9d]\n", (int)round(d * 100)) < 0) {
		printf("Error on printf 2!\n");
	}

	if (printf("Contract code right: [%20c]\n", cc) < 0) {
		printf("Error on printf 3!\n");
	}

	if (printf("Contract code left: [%-20c]\n", cc) < 0) {
		printf("Error on printf 4!\n");
	}

	return 0;
}
