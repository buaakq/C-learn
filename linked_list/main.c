#include "linked_list.h"
#include "double_list.h"
#include <stdio.h>

void print_node(link node)
{
	printf("%d->", node->val);
}

int main(int argc, char **argv)
{
	link head = make_node(10);
	link p = make_node(5);

	insert_node(&head, p);
	traverse(head, print_node);

	destroy(&head);
	traverse(head, print_node);

	p = make_node(5);
	link ret = search_node(head, 5);
	traverse(head, print_node);

	link p1 = make_node(1);
	link p2 = make_node(5);
	link p3 = make_node(10);
	link p4 = make_node(0);
	link p5 = make_node(3);
	link p6 = make_node(20);
	link p7 = make_node(14);
	link p8 = make_node(12);

	insert_node(&head, p1);
	insert_node(&head, p2);
	insert_node(&head, p3);
	insert_node(&head, p4);
	insert_node(&head, p5);
	insert_node(&head, p6);
	
	insert_node2(&head, p7);

	traverse(head, print_node);
	
	push(&head, p8);
	traverse(head, print_node);
	pop(&head);
	pop(&head);
	traverse(head, print_node);
	reverse(&head);
	traverse(head, print_node);

	return 0;
}
