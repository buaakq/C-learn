#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("hi\n");

	while(1)
	{
		printf("time now!\n");
		sleep(1);
	}

	return 0;
}
