#include <stdio.h>
#include <stdlib.h>

struct student {
	int ID; 
	char name[24];
	int age;
};

void print_stu(struct student *data)
{
	printf("My ID is %d\n", data->ID);
	printf("My name is %s\n", data->name);
	printf("I am %d years old\n", data->age);
}

int main(int argc, char **argv)
{
	struct student data[2];
	FILE *file;

	file = fopen("datafile", "r");
	if (file == NULL) {
		perror("opening file...");
		exit(2);
	}

	fread((void *)data, sizeof(struct student), 2, file);

	print_stu(&data[0]);
	puts("");
	print_stu(&data[1]);

	return 0;
}

