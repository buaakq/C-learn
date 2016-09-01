#include <stdio.h>

#define LEN 5

void swap(int *a, int lo, int hi);
void print_array(int *a, int n);

void insert_sort(int *a , int n)
{
	if (n <= 1)
		return;
	for (int i = 1; i < n; i++)
	{
		//print_array(a, n);
		for(int j = i; j > 0; j --)
		{
			if (a[j-1] > a[j])
				swap(a, j-1, j);
		}
	}
	//print_array(a, n);
	return;
}

void swap(int *a, int lo, int hi)
{
	int swap = a[lo];
	a[lo] = a[hi];
	a[hi] = swap;
}

void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return;
}

int main()
{
	int a[LEN] = {5,4,3,2,1};
	insert_sort(a, LEN);
	print_array(a, LEN);

	return 0;
}
