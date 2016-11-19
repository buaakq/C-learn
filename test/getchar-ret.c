#include <stdio.h>

int main(int argc, char **argv)
{
	int ch;
	while((ch = getchar()) != EOF) {
		putchar(ch);
	}
	printf("program will exit!\n");

	return 0;
}
