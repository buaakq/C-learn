## Job Control

`jobs` command can list all jobs in the current shell.
`fg %N` command put a job (N is the no. of the job) to front desk to run.

A quick example:
```
$ cat &
[1] 29806
$ jobs
[1]+  Stopped                 cat
$ fg %1
cat
```

`Ctrl+Z` send `SIGTSTP` signal to all front-desk processes so they terminate.
`bg` command can let a job run in background.

Two special signals which cannnot be ignored or catched by user-defined handler:
- `SIGKILL`, can always kill a process.
- `SIGSTOP`, can always stop a process.

BTW, background processes can write to console by default, but you can disable
it using:

```
$ stty tostop
```

## Daemon Process

Daemon processes don't have control terminal. Most of them are kernel threads
and don't have user-level code and data.

Use `ps axj` to check:
```
$ps axj
 PPID   PID  PGID   SID TTY      TPGID STAT   UID   TIME COMMAND
    0     1     1     1 ?           -1 Ss       0   0:10 /sbin/init
    0     2     0     0 ?           -1 S        0   0:00 [kthreadd]
    2     4     0     0 ?           -1 I<       0   0:00 [kworker/0:0H]
    2     6     0     0 ?           -1 I<       0   0:00 [mm_percpu_wq]
    2     7     0     0 ?           -1 S        0   0:00 [ksoftirqd/0]
    2     8     0     0 ?           -1 I        0   3:17 [rcu_sched]
    2     9     0     0 ?           -1 I        0   0:00 [rcu_bh]
    2    10     0     0 ?           -1 S        0   0:00 [migration/0]
    2    11     0     0 ?           -1 S        0   0:01 [watchdog/0]
```

TPGID=-1 tells us it's a daemon process.
