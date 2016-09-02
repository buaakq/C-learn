#include <stdio.h>
#include <stdlib.h>

unsigned int makeit(unsigned int a, unsigned int b) {
	unsigned int mask = 1;
	unsigned int ret = 0;
	for (int i = 0; i < sizeof(unsigned int) * 8; i ++) {
	    if (mask & b) {
			ret += a << i;
		}
		mask = mask << 1;
	}

	return ret;
}

int main(int argc, char ** argv)
{
	if (argc != 3) {
		printf("Usage: ./a.out a b");
		exit(1);
	}

	unsigned int a = atoi(argv[1]);
	unsigned int b = atoi(argv[2]);

	printf("Will calculate %d * %d\n", a, b);

	unsigned ret = makeit(a, b);
	printf("The result is %d\n", ret);

	return 0;
}
