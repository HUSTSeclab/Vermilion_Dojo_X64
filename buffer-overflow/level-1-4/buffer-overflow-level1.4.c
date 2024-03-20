#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "util.h"

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void read_flag()
{
	char flag[100];
	FILE *file;

	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("[-] cannot open\n");
		exit(-1);
	}

	while (fgets(flag, sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);
}

int main()
{
	bool match = false;
	char buffer[8];
	int result;

	print_desc();

	printf("3 + 5 = ?\n");
	scanf("%s", buffer); // vulnerable scanf
	result = atoi(buffer);

	if (match) {
		read_flag();
	} else {
		printf("The provided input is incorrect\n");
	}

	return 0;

	print_exit();

	return 0;
}