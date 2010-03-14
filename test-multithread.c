#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void doOneThing(int *);
void doAnotherThing(int *);
void doWrapUp(int, int);


int main(int argc, char *argv[]) {
	pthread_t thread1, thread2;
	int r1 = 0, r2 = 0;

	pthread_create(&thread1, NULL, (void *)doOneThing, (void *)&r1);
	pthread_create(&thread2, NULL, (void *)doAnotherThing, (void *)&r2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	doWrapUp(r1, r2);

	return 0;
}


void doOneThing(int *numTimes) {
	int i, j, x;

	for (i = 0; i < 4; i++) {
		printf("Doing one thing.\n");
		for (j = 0; j < 10000; j++) {
			x += i;
		}
		(*numTimes)++;
	}
}

void doAnotherThing(int *numTimes) {
	int i, j, x;

	for (i = 0; i < 4; i++) {
		printf("Doing another thing.\n");
		for (j = 0; j < 10000; j++) {
			x += i;
		}
		(*numTimes)++;
	}
}

void doWrapUp(int oneTime, int anotherTime) {
	int total;

	total = oneTime + anotherTime;
	printf("Wrap up:\n   One thing:     %d\n   Another thing: %d\n   Total:         %d\n", oneTime, anotherTime, total);
}

