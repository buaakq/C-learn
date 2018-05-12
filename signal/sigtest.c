#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

void printsigset(const sigset_t *set)
{
   int i, ret;
   for (i = 1; i < 32; i ++) {
      ret = sigismember(set, i);
      assert(ret != -1);
      printf(ret == 0 ? "0" : "1");
   }
   printf("\n");
}

int main()
{
   sigset_t mask, pending;
   sigemptyset(&mask);
   sigaddset(&mask, SIGINT);
   sigprocmask(SIG_BLOCK, &mask, NULL);

   while (1) {
      sigpending(&pending);
      printsigset(&pending);
      sleep(1);
   }

   return 0;
}
