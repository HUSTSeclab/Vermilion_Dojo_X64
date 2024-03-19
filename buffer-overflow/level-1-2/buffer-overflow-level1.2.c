// gcc -fno-stack-protector -no-pie ./ret2text.c -o ret2text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

char *gift_string = "/flag";

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void print_desc()
{
	printf("###\n");
	printf("### If you feel hard to beat this pokemon, please read and study the description.\n");
	printf("### Or just skip and try other pokemons.\n");
	printf("### Have fun :)\n");
	printf("###\n");
}

void read_flag(char *filename)
{
	char flag[100];
	FILE *file;

	printf("filename %s\n", filename);

	file = fopen(filename, "r");
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
        char filename[10] = "Makefile";
	char buffer[0x10];
        
        init();
        
        print_desc();

        puts("Give me your input");
	
	scanf("%s", buffer); // vulnerable scanf
        
        read_flag(filename);

	puts("Bye bye~");

	return 0;
}