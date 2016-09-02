#include <stdio.h>

#define STACK_SIZE 1000

int a[STACK_SIZE] = {0};
int esp = 0;

void push(int i)
{
	a[++esp] = i;
}

void pop()
{
	esp --;
}

int top()
{
	return a[esp];
}

void test_stack()
{
	push(1);
	push(2);
	push(3);
	printf("Now, the top is %d\n", top());
	pop();
	printf("Now, the top is %d\n", top());
	pop();
	printf("Now, the top is %d\n", top());
}

void print_buf(int index)
{
	if (index == 3)
		return;
	print_buf(index+1);
	printf("%d\n", index);
}

int main()
{
	int buf[3] = {1,2,3};
	print_buf(0);

	return 0;
}
	

