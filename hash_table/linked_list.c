#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

link make_node(uchar val)
{
	link node = malloc(sizeof(struct node));
	node->val = val;
	node->next = NULL;
	return node;
}

void free_node(link node)
{
	free(node);
}

link search_node(link head, uchar key)
{
	while(head)
	{
		if (head->val == key)
			return head;
		head = head->next;
	}
	return NULL;
}

void insert_node2(link *head, link p)
{
	if (*head == NULL)
	{	
		*head = p;
		return ;
	}
	link last = *head;
	while(last->next)
	{
		last = last->next;
	}
	last->next = p;
	p->next = NULL;
	return;
}

void insert_node(link *head, link p)
{
	if (*head == NULL)
	{
		*head = p;
		return ;
	}

	link tar = *head;
	if (p->val < tar->val)
	{
		*head = p;
		p->next = tar;
		return ;
	}

	while(tar && tar->next)
	{
		if (p->val >= tar->val && p->val < tar->next->val)
			break;
		tar = tar->next;
	}
	// insert after tar
	p->next = tar->next;
	tar->next = p;
	return ;
}

void delete_node(link *head, link p)
{
	if (*head == NULL)
		return ;
	if (*head == p)
	{
		*head = p->next;
		free_node(p);
	}
	link pre = NULL;
	link cur = *head;
	while(cur != p && cur)
	{
		pre = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	pre->next = cur->next;
	free_node(p);
}

typedef void (*visit_type)(link);

void traverse(link head, visit_type visit)
{
	while(head)
	{
		visit(head);
		head = head->next;
	}
	puts("NULL");
}

void destroy(link *head)
{
	if (*head == NULL)
		return;
	link cur = *head;
	while(cur)
	{
		link next = cur->next;
		free_node(cur);
		cur = next;
	}
	*head = NULL;
}

void push(link *head, link p)
{
	insert_node(head, p);
}

link pop(link *head)
{
	if (*head == NULL)
		return NULL;
	if ((*head)->next == NULL)
	{
		link ret = *head;
		*head = NULL;
		return ret;
	}

	link pre = NULL;
	link cur = *head;

	while(cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	
	return cur;
}
	
void reverse(link *head)	
{
	if (*head == NULL || (*head)->next == NULL)
		return;
	link curr = *head;
	link prev = NULL;
	link next = NULL;
	while(curr)
	{
		next = curr->next;
		if (next == NULL)
			*head = curr;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return;
}



	
