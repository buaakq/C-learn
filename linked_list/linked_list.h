#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
	unsigned char val;
	struct node *next;
};

typedef unsigned char uchar;
typedef struct node* link;

link make_node(uchar val);
void free_node(link node);
link search_node(link head, uchar key);
void insert_node(link *head, link p);
void delete_node(link *head, link p);

typedef void (*visit_type)(link);

void traverse(link head, visit_type visit);
void destroy(link *head);

void push(link *head, link p);
link pop(link *head);


#endif
