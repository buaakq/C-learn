#include <stdio.h>
#include <stdlib.h>


int b_search_last(int *a, int n, int num) {
	if (n < 1)
		return -1;
	int lo = 0, hi = n - 1;
	int mid;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] <= num)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	if (hi < n && a[hi] == num)
		return hi;
	return -1;
}

int b_search_first(int *a, int n, int num) {
	if (n < 1)
		return -1;
	int lo = 0, hi = n - 1;
	int mid;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] >= num)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	if (lo < n && a[lo] == num)
		return lo;
	return -1;
}

int b_search(int *a, int n, int num) {
	if (n < 1)
		return -1;
	int lo = 0, hi = n - 1;
	int mid;
	while(lo <= hi) {
		mid = lo + (hi - lo) / 2;
		if (a[mid] == num)
			return mid;
		else if (a[mid] < num)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return -1;
}
	

int main(int argc, char **argv){
	if (argc != 2){
		printf("wrong args, will exit!\n");
		exit(2);
	}

	int num = atoi(argv[1]);
	int a[12] = {1,2,2,3,4,4,5,6,7,8,9,10};
	int index = b_search_last(a, 10, num);

	if (index != -1)
		printf("number %d found, index is %d\n", num, index);
	else
		printf("not found!\n");

	return 0;
}
