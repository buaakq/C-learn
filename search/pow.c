#include <stdio.h>
#include <stdlib.h>

long long mypow (long long base, int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return base;

	long long bak = base;
	int k = 1;
	int t = 0;
	while(k < n) {
		k *= 2;
		t ++;
	}
	
	int more = k - n;
	while (t --)
		base = base * base;
	while (more --)
		base = base / bak;

	return base;
}

int main(){
	int base = 10;
	char c[100];
	while(scanf("%s", c) != EOF) {
		int n = atoi(c);
		long long ret = mypow(base, n);
		printf("%d ^ %d = %lld\n", base, n, ret);
	}

	return 0;
}
		
