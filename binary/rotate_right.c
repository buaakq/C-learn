#include <stdio.h>
#include <stdlib.h>

void makeit(unsigned int *a, unsigned int b) {
    b = b % (sizeof(unsigned int) * 8);
    int len = (sizeof(unsigned int) * 8);
	if (b == 0)
		return;
	unsigned int temp = *a;
	*a = *a << (len - b);
	unsigned int right = temp >> b;
	*a = *a | right;
}

int main(int argc, char ** argv)
{
	if (argc != 3) {
		printf("Usage: ./a.out a b\n");
		exit(1);
	}

	unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[2]);

	printf("Will rotate 0x%08x to right %d bits\n", a, b);

	makeit(&a, b);
	printf("The result is 0x%08x\n", a);

	return 0;
}
