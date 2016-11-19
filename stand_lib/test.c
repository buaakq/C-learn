#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("./textfile", "r");
	printf("The postition of file is %ld \n", ftell(file));

	char buf[10];
	while (fgets(buf, 10, file) != NULL)
	{
		printf("Get string from file : %s\n", buf);
	}
		
	fprintf(stderr, "comes to the tail of file\n");
	puts("hello world");

	return 0;
}
