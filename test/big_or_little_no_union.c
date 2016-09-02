#include<stdio.h>

int main(int argc, char ** argv) {
	int a = 0x12345678;
	char *p = (char *)&a;

	printf("Low byte of int a is %x\n", *p);

	if (*p == 0x78)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
	return 0;
}
	
