#include "cyclelinkedlist.h"
#include <stdio.h>

void visit(link p)
{
	printf("-%d-", p->val);
	return;
}

int main(int argc, char **argv)
{
	link p1 = make_node(5);
	link p2 = make_node(15);
	link p3 = make_node(25);
	link p4 = make_node(35);
	link p5 = make_node(45);

	insert(p1);
	insert(p2);
	insert(p3);
	insert(p4);
	insert(p5);

	traverse(visit);
	delete(p1);
	traverse(visit);
	return 0;
}
