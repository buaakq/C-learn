#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Error usage, usage: ./a.out from-file to-file\n");
		exit(2);
	}

	char *from_path = argv[1];
	char *to_path = argv[2];	

	FILE *from = fopen(from_path, "r");
	if (from == NULL){
		perror("Open from file: ");
		exit(3);
	}
	
	FILE *to = fopen(to_path, "w");
	if (to == NULL) {
		perror("Open to file:");
		exit(3);
	}

	int ch;
	while((ch = fgetc(from)) != EOF)
	{
		fputc(ch, to);
	}

	return 0;
}
