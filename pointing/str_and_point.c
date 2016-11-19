#include <stdio.h>

int main()
{
	char str2[] = "abcdefgh123abcd\n";
	printf(str2);
	printf("\n");

	char *p = "abcd";
	*p = 'A';

	return 0;
}
