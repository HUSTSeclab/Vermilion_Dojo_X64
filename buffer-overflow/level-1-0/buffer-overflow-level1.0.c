#include <stdio.h>
#include <stdlib.h>
#include "util.h"


void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

// void print_desc()
// {
// 	print_image("小磁怪", "image.txt");
// 	printf("###\n");
// 	// printf("### Pokémons, please read and study the description.\n");
// 	// 在正式挑战宝可梦之前，请仔细阅读并学习描述中的战斗技巧
// 	// 如果感到吃力，请先尝试战胜其他低等级的宝可梦
// 	// printf("### Or just skip and try other lower level Pokémons.\n");
// 	// printf("### Have fun :)\n");
// 	printf("### 在正式挑战%s之前，请仔细阅读并学习描述中的战斗技巧\n", "小磁怪");
// 	printf("### 如果感到吃力，请先尝试战胜其他低等级的宝可梦\n");
// 	printf("### 祝你好运 :)\n");
// 	printf("###\n");
// }

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
        long magic = 0;
	char buffer[0x10];
        
        init();
        
        print_desc();

        puts("Give me your input");
	
	scanf("%s", buffer); // vulnerable scanf
        
        if (magic == 0xdeadbeef) {
                read_flag();
        }

	print_exit();

	return 0;
}