#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	long long counter = 0;
	while(1)
	{
		int *p = malloc(1000);
		if (p == NULL)
		{
			printf("FAIL!\n");
			break;
		}
		counter += 4;
	}

	printf("Total memory is %lld byte\n", counter);

	return 0;

}
