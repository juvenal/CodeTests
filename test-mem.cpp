#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int main(int argc, char *argv[]) {
	char *s1, *s2;

	s1 = new char(128);
	s2 = new char(128);

	strcpy(s1, "It's a brave new ");
	strcpy(s2, "world!");

	std::cout << s1 << s2 << std::endl;
	std::cout << s2 << std::endl;

	return 0;
}
