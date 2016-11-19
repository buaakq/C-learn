#include <stdio.h>
#include <stdlib.h>

struct student {
	int ID; 
	char name[24];
	int age;
};

int main(int argc, char **argv)
{
	struct student data[2] = {
		{1, "kang", 24}, 
		{2, "Xie", 25}
	};

	FILE *file;
	if ((file = fopen("datafile", "w")) == NULL)
	{
		perror("opening file:");
		exit(2);
	}
	
	fwrite((void *)data, sizeof(struct student), 2, file);

	return 0;
}
