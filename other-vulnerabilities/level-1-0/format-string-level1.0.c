#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

#define FMT_LEN 0x20

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	print_image("Paras", "image.txt");
	printf("###\n");
	printf("### If you feel hard to beat this pokemon, please read and study the description.\n");
	printf("### Or just skip and try other pokemons.\n");
	printf("### Have fun :)\n");
	printf("###\n");
}

void input_message() 
{
	char buf[FMT_LEN];

	puts("Give me your name:");
	read(0, buf, FMT_LEN);
	printf("Hello, %s\n", buf);

	puts("Say something to me:");
	read(0, buf, FMT_LEN);
	puts("Copy that");
	printf(buf);

	puts("Bye bye~");
}

void magic()
{
	char flag[0x38];
	FILE *file;

	*(long long *)flag = (long long)&flag + 0x8;
	file = fopen("/flag", "r");
	if (file == NULL) {
		printf("[-] cannot open\n");
		exit(-1);
	}

	while (fgets((char *)((char *)(&flag) + 0x8), sizeof(flag), file) != NULL) {
		puts(flag);
	}

	fclose(file);

	input_message();
}

int main()
{
        init();
	print_desc();
	magic();

	return 0;
}
