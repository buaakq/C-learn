#include <stdio.h>

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

int small_k(int *a, int n, int k)
{
	if (k < 1 || k > n)
		return -1;
	int lo = 0;
	int hi = n - 1;
	int j;
	while(1){
		j = partition(a, lo, hi);
		if (j == k-1)
			break;
		else if (k-1 < j)
			hi = j - 1; 
		else
			lo = j + 1;
	}
	return a[j];
}

int main(int argc, char ** argv){
	if (argc != 2){
		printf("wrong args! will exit\n");
		exit(2);
	}

	int k = atoi(argv[1]);
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int num = small_k(a, 10, k);
	printf("the %dth small number is %d.\n", k, num);
	
	return 0;
}
