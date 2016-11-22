#include "hash.h"
#include "stdio.h"

static link table[10];

int error_not_found = 0;

static int hash(uchar key)
{
	return key % 11;
}

void insert(uchar key)
{
	link p = make_node(key);
	int pos = hash(key);
	link slot = table[pos];
	
	if (slot == NULL)
		table[pos] = p;
	else
	{
		while(slot->next != NULL)
			slot = slot->next;
		slot->next = p;
	}

	return;
}

uchar search(uchar key)
{
	int pos = hash(key);

	link slot = table[pos];

	while(slot != NULL)
	{
		if (slot->val == key)
		{
			error_not_found = 0;
			return key;
		}
		slot = slot->next;
	}
	error_not_found = 1;
	return 0;
}


