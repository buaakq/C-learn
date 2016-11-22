#include "hash.h"
#include "linked_list.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	insert(1);
	insert(3);
	insert(7);
	insert(100);
	insert(5);
	insert(12);
	insert(11);
	insert(0);

	printf("%d\n", search(2));
	printf("%d\n", search(1));
	printf("%d\n", search(5));
	printf("%d\n", search(12));
	printf("%d\n", search(0));
	printf("%d\n", search(11));

	return 0;
}
