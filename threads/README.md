# Threads

All threads in a process share the following resources:
- file descriptor table
- signal actions
- current working dir
- uid and gid

But they have private resources as well:
- thread id
- context: registers
- stack
- errorno
- signal masks
- scheduling priority

## Thread Management

Create a thread:

```
#include <pthread.h>

int pthread_create(pthread_t *restrict thread,
                   const pthread_attr_t *restrict attr,
	                void *(*start_routine)(void*),
                   void *restrict arg);
```

- `pthread_t` is the type of thread id, use `pthread_self` to get the tid of
the thread itself.
- `attr` is thread attribute, pass NULL to set to default.
- `start_routine` is the function where new thread starts running.
- `arg` is the argument passed to `start_routine` function.

A thread can exit actively by calling `pthread_exit`:
```
#include <pthread.h>

void pthread_exit(void *value_ptr);
```

Other threads can call `pthread_join` to get `value_ptr` after it exits.
```
#include <pthread.h>

int pthread_join(pthread_t thread, void **value_ptr);
```

There are different scenarios:
- if thread exits with `return`, `value_ptr` will be set to its return value.
- if thread is canceled by other threads using `pthread_cancel`, `value_ptr`
will set to `PTHREAD_CANCELED`.
- if thread exits actively by calling `pthread_exit`, `value_ptr` will be set
to the arg passed to `pthread_exit`.

If you don't want to recycle a thread's resources, use `pthread_detach` to
detach the thread. It will be destroyed once it exits.

```
#include <pthread.h>

int pthread_detach(pthread_t tid);
```

## Thread Sychronization

In this section we will learn different kinds of synchronization methods:
- mutex
- condition variable
- semaphore

## Dining Philosophers Problem
