## Basic Concepts

A simple example of signal in Linux.
1) shell running a front-end command
2) user presses "CTRL+C", trigger a HW interrupt
3) CPU switch to priviledged mode
4) console driver interprets "CTRL+C" as `SIGINT` signal, wirtes to PCB
5) before returning to user space, handle singal in PCB
6) detect `SIGINT` signal, so kill this process.

Use `kill -l` to check supported signal list.

See signal(7) for default action and comments for every signal.

How to trigger a signal:
1) user presses some keys on keyboard.
2) HW exceptions
3) kill(2) function
4) kill(1) command
5) specific HW conditions. e.g., a time-out alarm triggers `SIGALRM` signal.

User programs can use sigaction(2) to tell kernel how to handle a signal:
1) ignore
2) default action
3) specify a handler function

## Generate a Signal

In this section, we talk about how to generate a signal. We will use the
following signals:

- SIGQUIT: default action is terminate a process and generate core dump
- SIGSEGV: let a process trigger segmentation fault.

Defaultly, a user process can not generate core dump. To release this hold,
we need to run

```
$ ulimit -c <core_dump_size>
```
in current shell.

### console key bindings

Press `CTRL+\` to send a `SIGQUIT` signal to current process in shell.

### `kill` syscall

You can use `kill -<signal_id> <pid>` to send a specific signal to any process.
`kill` command uses `kill()` syscall to generate signals.

```
#include <signal.h>

int kill(pid_t pid, int signo);
int raise(int signo);

#include <stdlib.h>

void abort(void);
```

- `kill` can send any signal to a specified process.
- `raise` can send any signal to the process itself.
- `abort` sends a `SIGABRT` signal to itself.

### `alarm`

A program can call `alarm` to set up a timer. The default action of time-out
timer is to terminate the process.

```
#include <unistd.h>

unsigned int alarm(unsigned int seconds);
```

This function always returns how seconds left that is set by the previous alarm.

## Block Signals

### signal expression in kernel

Kernel maintains a table for all signals, where each signal has an entry.

```
signal id   block    pending    handler
   0          0         0       default
   1          1         1       ignore   
   2          1         0       --> void sighalder(int a)
   3 ....
```

- for sig(0), won't block, default action.
- for sig(1), will block, have blocked one. Process has the chance to change the
"ignore" action before releasing it.
- for sig(2), will block, deliver to user space `sighandler` function.

### `sigset_t` operations 

A set of signals is called "signal set", it could be: 
- a process's signal mask contains the info that which signal the process should
block.
- a process's pending signals.

```
#include <signal.h>

// clear set
int sigemptyset(sigset_t *set);

// set all bits of set
int sigfillset(sigset_t *set);

// add signo to set
int sigaddset(sigset_t *set, int signo);

// delete signo from set
int sigdelset(sigset_t *set, int signo);

// check whether signo exists in set, return 1 if true, otherwise return 0.
int sigismember(const sigset_t *set, int signo);
```

All functions above return -1 if fails.

```
int sigprocmask(int how, const sigset_t *set, sigset_t *oset);
```

`sigprocmask` can change process's signal mask.
- if `oset` isn't NULL, restore the original mask to it.
- if `how`=`SIG_BLOCK`, mask=mask|set
- if `how`=`SIG_UNBLOCK`, mask=mask&~set
- if `how`=`SIG_SETMASK`, mask=set

```
int sigpending(sigset_t *set);
```

`sigpending` reads process's pending signals to `set`.

## Catch Signal

### signal catch process

See picture:

![](https://akaedu.github.io/book/images/signal.catch.png)

### modify signal action

Use `sigaction` to modify handler action of a specific signal.

```
#include <signal.h>

// modify action to act
// if oact is not NULL, restore the original action in it.
int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);
```

`struct sigaction` is defined as

```
struct sigaction {
   void      (*sa_handler)(int);   /* addr of signal handler, */
                                       /* or SIG_IGN, or SIG_DFL */
   sigset_t sa_mask;               /* additional signals to block */
   int      sa_flags;              /* signal options, Figure 10.16 */

   /* alternate handler: for RT signals */
   void     (*sa_sigaction)(int, siginfo_t *, void *);
};
```

### `pause` function

`pause` will block a process until a signal is delivered.

- if the signal's action is to terminate the process, then do so.
- if the signal's action is to ignore, then continue its blocking status.
- if the signal has a handler, then execute the handler, `pause` returns -1.

### `sigsuspend` function

```
#include <signal.h>

int sigsuspend(const sigset_t *sigmask);
```

`sigsuspend` can
- change current signal mask to `sigmask`
- block current process

The point is: two steps above are **atomic**.

We can use this function to implement a `sleep` syscall. See mysleep.c.
