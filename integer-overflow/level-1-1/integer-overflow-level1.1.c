#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "util.h"

unsigned short read_short()
{
	char buf[0x6];
	read(0, buf, 0x6);
	return atoi(buf);
}

void read_flag()
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

void vuln_func(unsigned short index)
{
	char buf[0x100];
	read(0, buf, index);
}

int main()
{
	unsigned char s;
	unsigned short i;
	
	print_desc();

        puts("Give me your input");
	i = read_short();
	puts("Give me your payload");

	s = i; // integer overflow - width

	if (s >= 80) {
		printf("You need to provide a value less than 80\n");
		return -1;
	}

	if ((i >= 80) && (s != i)) {
		vuln_func(i);
	} else {
	 	printf("Please leverage the underlying integer overflow to bypass the condition\n");
	}

	print_exit();

	return 0;
}
