#include <stdio.h>
#include <stdlib.h>

void binary_swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Wrong usage, will exit\n");
		exit(2);
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	printf("will swap %d and %d\n", a, b);
	binary_swap(&a, &b);
	printf("swap finish, now a = %d, b = %d\n", a, b);

	return 0;
}
