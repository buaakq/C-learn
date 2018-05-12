#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef unsigned int uint;

void sig_alarm_handler(int signo)
{
   /* do nothing */
}

uint mysleep(uint nsecs)
{
   struct sigaction new_act, old_act;
   sigset_t new_mask, old_mask, suspend_mask;
   uint ret;

   /* set action of SIGALRM and save original action */
   new_act.sa_handler = sig_alarm_handler;
   sigemptyset(&new_act.sa_mask);
   new_act.sa_flags = 0;
   sigaction(SIGALRM, &new_act, &old_act);

   /* block SIGALRM and save old mask */
   sigemptyset(&new_mask);
   sigaddset(&new_mask, SIGALRM);
   sigprocmask(SIG_BLOCK, &new_mask, &old_mask);

   /* start timer */
   alarm(nsecs);

   /* release SIGALRM and block the process */
   suspend_mask = old_mask;
   sigdelset(&suspend_mask, SIGALRM);
   sigsuspend(&suspend_mask);

   /* time is up, cancel the timer */
   ret = alarm(0);

   /* restore old action and mask */
   sigaction(SIGALRM, &old_act, NULL);
   sigprocmask(SIG_SETMASK, &old_mask, NULL);

   return ret;
}

int main()
{
   while (1) {
      mysleep(1);
      printf("1 second passed\n");
   }

   return 0;
}
