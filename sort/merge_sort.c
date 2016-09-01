#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int *aux;

void merge(int *a, int lo, int mid, int hi)
{
	int i = lo;
	int j = mid+1;
	for (int k = lo; k <= hi; k ++)
		aux[k] = a[k];

	for (int k = lo; k <= hi; k ++) {
		if (i == mid+1)
			a[k] = aux[j ++];
		else if (j == hi+1)
			a[k] = aux[i ++];
		else if (aux[i] > aux[j])
			a[k] = aux[j ++];
		else
			a[k] = aux[i ++];
	}
	return ;
}

void print_array(int *a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return;
}

void merge_sort(int *a, int lo, int hi)
{
	if (lo >= hi)
		return;
	int mid = lo + (hi - lo) / 2;
	merge_sort(a, lo, mid);
	merge_sort(a, mid + 1, hi);
	merge(a, lo, mid, hi);
}

int main()
{
	aux = (int *)malloc(sizeof(int) * LEN);
	int a[LEN] = {10,9,8,7,6,5,4,3,2,1};
	merge_sort(a, 0, LEN - 1);
	print_array(a, LEN);

	return 0;
}
