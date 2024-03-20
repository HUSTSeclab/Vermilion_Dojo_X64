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

void print_desc()
{
	print_image("Jolteon", "image.txt");
	printf("###\n");
	printf("### If you feel hard to beat this pokemon, please read and study the description.\n");
	printf("### Or just skip and try other pokemons.\n");
	printf("### Have fun :)\n");
	printf("###\n");
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

	printf("3 + 5 = ?\n");
	scanf("%s", buffer); // vulnerable scanf
	result = atoi(buffer);

	if (match) {
		read_flag();
	} else {
		printf("The provided input is incorrect\n");
	}

	return 0;

	puts("Bye bye~");

	return 0;
}