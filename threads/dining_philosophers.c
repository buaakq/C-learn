#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t chop_mutex[5] = {PTHREAD_MUTEX_INITIALIZER};

void pick_up_chop(int left, int right)
{
   /* DEADLOCK !!!
    * one possible solution is always pick up the lower-number chopstick first.
    * see https://en.wikipedia.org/wiki/Dining_philosophers_problem:
    * Resource hierarchy solution, i.e.,
    * pthread_mutex_lock(&chop_mutex[MIN(left, right)]);
    * pthread_mutex_lock(&chop_mutex[MAX(left, right)]);
    */
   pthread_mutex_lock(&chop_mutex[left]);
   pthread_mutex_lock(&chop_mutex[right]);
}

void put_down_chop(int left, int right)
{
   pthread_mutex_unlock(&chop_mutex[left]);
   pthread_mutex_unlock(&chop_mutex[right]);
}

void *dining_fn(void *id)
{
   int phi_id = *((int *)id);
   int sec, left, right;
   printf("Philosopher %d thread started.\n", phi_id);

   while (1) {
      sec = rand() % 10;
      usleep(sec);

      left = phi_id;
      right = (phi_id + 1) % 5;

      printf("Philosopher %d is hungry ...\n", phi_id);
      pick_up_chop(left, right);
      // eating
      sec = rand() % 10;
      usleep(sec);
      put_down_chop(left, right);
      printf("Philosopher %d is full ...\n", phi_id);
   }

   return NULL;
}

int main()
{
   pthread_t tid[5] = {0};
   int id[5] = {0, 1, 2, 3, 4};
   int i, ret;

   printf("main thread starting...\n");

   for (i = 0; i < 5; i ++) {
      ret = pthread_create(&tid[i], NULL, &dining_fn, &id[i]);
      // printf("Philosopher %d thread created ...\n", id[i]);
   }

   while (1);
   return 0;
}

