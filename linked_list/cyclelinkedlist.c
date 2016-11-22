#include <stdlib.h>
#include "cyclelinkedlist.h"
#include <stdio.h>


struct node head_node = {0, &head_node, &head_node};

static link head = &head_node;

link make_node(unsigned char val)
{
	link node = malloc(sizeof(*node));
	node->val = val;
	node->next = node->prev = NULL;
	return node;
}

void free_node(link p)
{
	free(p);
	return;
}

void insert(link p)
{
	p->next = head->next;
	p->prev = head;
	head->next->prev = p;
	head->next = p;
}

void delete(link p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->prev = p->next = NULL;
}

void traverse(visit_type visit) 
{
	link p;
	printf("head-");
	for(p = head->next; p != head; p = p->next) 
		visit(p);
	printf("-head\n");
}

void enqueue(link p)
{
	insert(p);
}

link dequeue(void)
{
	if (head->next == head)
		return NULL;
	else
	{
		link p = head->prev;
		delete(p);
		return p;
	}
	return NULL;
}





