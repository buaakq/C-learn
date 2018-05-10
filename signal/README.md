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
