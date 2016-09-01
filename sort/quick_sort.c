#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void swap(int *a, int lo, int hi);

int partition(int *a, int lo, int hi)
{
	int i = lo;
	int j = hi+1;
	int val = a[lo];
	while(i < j){
		while(a[++i] < val){
			if (i == hi)
				break;
		}
		while(a[--j] > val){
			if (j == lo)
				break;
		}
		if (i < j)
			swap(a, i, j);
		else
			break;
	}
	swap(a, lo, j);
	return j;
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
}

void quick_sort(int *a, int lo, int hi)
{
	if (lo >= hi)
		return;
	int j = partition(a, lo, hi);
	quick_sort(a, lo, j - 1);
	quick_sort(a, j + 1, hi);
	return;
}

int main()
{
	int a[LEN] = {10,9,8,7,6,5,4,3,2,1};
	quick_sort(a, 0, LEN - 1);
	print_array(a, LEN);

	return 0;
}
