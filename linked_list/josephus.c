#include <stdio.h>
#include "cyclelinkedlist.h"
#include <assert.h>
#include <stdlib.h>

#define MAX_NUMS 100

void visit(link p)
{
	printf("-%d-", p->val);
	return;
}

//static link nodes[MAX_NUMS];

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s N M\n", argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	if (n > MAX_NUMS || n < 0 || m < 0)
	{
		fprintf(stderr, "error m or n size\n");
		exit(2);
	}

	for (int i = 0; i < n; i++)
	{
		link p = make_node(i+1);
		insert(p);
	}
	traverse(visit);

	//while(head != head->next)
	{
		// kill_one();
	}

	return 0;
}



