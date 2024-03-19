#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.h"

void print_desc()
{
	printf("###\n");
	printf("### If you feel hard to beat this pokemon, please read and study the description.\n");
	printf("### Or just skip and try other pokemons.\n");
	printf("### Have fun :)\n");
	printf("###\n");
}

long read_hex_long()
{
	char buf[0x10];
	char *ptr;
	read(0, buf, 0x10);
	return strtol(buf, &ptr, 16);
}

void print_flag()
{
	char *p;
	FILE *fp;
	char flag[100];

	fp = fopen("/flag", "r");

	if (!fp) {
		perror("[-] fopen failed");
	}

	p = fgets(flag, sizeof(flag), fp);
	if (!p) {
		perror("[-] fgets failed");
		fclose(fp);
	}
	
	printf("%s", flag);

	fclose(fp);
}

int main()
{
	int64_t i;
	int32_t j;
	int16_t k;
	bool result = true;

	print_desc();

        puts("Give me your input");
	i = read_hex_long();

	if ((i > 0) || ((uint64_t)i) < 0xFFFFFFFE00000000) {
	    result = false;
	}

	j = i;


	if ((j > 0) || ((uint32_t)j) > 0x88880000) {
	    result = false;
	}

	k = i;

	if ((k > 0) || ((uint16_t)k) != 0x9527) {
		result = false;
	}

	if (result)
		print_flag();
	else
	 	printf("Please leverage the underlying integer overflow to bypass the condition\n");
	
	return 0;
}
