#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int a[MAX];

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

void howmany()
{
    int b[10] = {0};
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

int main(void)
{
    gen_random(10);
    //print_random();
    howmany();
    return 0;
}
