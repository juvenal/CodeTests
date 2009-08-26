#include <stdio.h>

#define INTEGERS(x, y) ((int)(x), (int)(y))

int main(int argc, char **argv) {
	printf("%d %d\n", INTEGERS(1.2, 3.4));
	return 0;
}
