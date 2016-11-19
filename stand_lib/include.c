#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void all_h_file(FILE *src)
{
	char buf[50];
	int error = get_item(src, buf);


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage ./a.out c_file\n");
		exit(1);
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("opening src file...");
		exit(2);
	}

	all_h_file(file);

	return 0;
}
