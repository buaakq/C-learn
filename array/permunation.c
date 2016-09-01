#include <stdio.h>
#include <stdlib.h>

#define LEN 8

void print_array(int *a, int len)
{
	for (int i = 0; i < len; i ++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int *a, int lo, int hi)
{
	int temp = a[lo];
	a[lo] = a[hi];
	a[hi] = temp;
}

void helper(int *a, int lo, int hi)
{
	if (lo == hi)
		print_array(a, LEN);
	for(int i = lo; i <= hi; i ++)
	{
		swap(a, lo, i);
		helper(a, lo+1, hi);
		swap(a, lo, i);
	}
}

void permutation(int *a)
{
	helper(a, 0, LEN-1);
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8};
	permutation(a);
	return 0;
}

