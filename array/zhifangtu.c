#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int a[MAX] = {0};

void gen_random(int upper_bound)
{
     int i;
      for (i = 0; i < MAX; i++)
            a[i] = rand() % upper_bound;
}

void print_random()
{
     int i;
      for (i = 0; i < MAX; i++)
            printf("%d ", a[i]);
       printf("\n");
}

void howmany(int *b)
{
    for(int i = 0; i < MAX; i ++)
    {
        b[a[i]] ++;
    }
    for(int j = 0; j < 10; j ++)
    {
        printf("%d : %d\n", j, b[j]);
    }
    return;
}

void print_zft(int *b)
{
	for (int i = 0; i < 10; i ++)
	{
		printf("%d ", i);
	}
	
	printf("\n");
	for (int i = 0; i < 10; i ++)
	{
		printf("%d ", b[i]);
	}

	printf("\n");
	int empty = 0;
    while(empty < 10)	
	{
		for (int i = 0; i < 10; i ++)
		{
			if (b[i])
			{
				printf("* ");					
				b[i] --;
			}
			else
			{
				printf("  ");
				empty ++; 
			}
		}
		printf("\n");
	}
}	


int main(void)
{
    gen_random(10);
    //print_random();
	int b[10] = {0};
	howmany(b);
	print_zft(b);
    return 0;
}
