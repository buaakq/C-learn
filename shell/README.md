# Shell

[Shell Script Quick References](https://www.shellscript.sh/quickref.html)
[Shell Script Tips](https://www.shellscript.sh/tips/)

## History

Different kinds of shell:
- sh
- csh
- ksh: compatible with sh
- tcsh: enhancement of csh
- bash: compatible with sh, developed by GNU.

The most common one is `/bin/bash`. The default bash is configured in
`/etc/passwd`:

```
qiaokang:x:1000:1000:qiaokang,,,:/home/qiaokang:/bin/bash
```

## How Shell Works

Usually shell forks a new process and call `exec` to execute a target command,
except for builtin commands, which trigger a function call of the shell process.

Commond builtin commands include `cd`, `alias`, `umask`, `exit`, etc.

If run `(command)`, current shell will fork a new process to execute this
command instead of running it in current shell.

Shell also supports running a shell script - a collection of shell commands.

There are differnt ways to run a shell script:

```
/bin/bash ./script.sh
./script.sh
source ./script.sh
. ./script.sh
```

1 = 2: running the script in a child process. 3 = 4: running the script in a
current shell process.

## Basic Shell Grammar

### Variables

Two kinds of vairables in shell:
* local: `VAR=value`
* env: `export VAR=value`

To delete a local or env var, use `unset VAR`

### Wildcard

- `*` can match 0, 1 or more chars.
- `?` can match an arbitary char.
- `[abc]` can match a, b, or c.

### Command Replacement

A pair of back quotes can be used to contain the output of a command.

```
DATE=`date`
echo $DATE
```

Shell will first execute `date` command and pass its output to `DATE` var.

### Arithmetic

Use `$(())` to convert string to number.

### Escape

Use `\` to eliminate special meanings.
See the following examples:

To create a directory named `$hello`: `mkdir \$hello`
To create a file named `learn linux`: `touch learn\ linux`

Another usage of `\` is to jump to next line:
```
$ ls \
> -l
<output of ls>
```

### Quotes

Single quotes: keep literal form of special chars like `$` and `\`.
Doule quotes: can do the following;
- can fetch var value using `$`
- can replace output of command using back quotes
```
\$ = $
\\ = \
\` = `
\\ = \
\" = "
```

## Bash Startup Scripts

### interactive login shell

When login:

1) run `/etc/profile`
2) search and run `~/.bash_profile`, `~/.bash_login` and `~/.profile`

When logout: run `~/.bash_logout`

### interacitve non-login shell

When using `ssh`, run terminal program or type `bash` in a shell, you get an
interactive non-login shell.

This kind of shell will run `~/.bashrc`.

Usually we recommend putting your local var, env, and alias in this file.

### non-interactive shell

A non-interactive shell is created to execute a shell script. It inherits all
env but not local var and alias.

This kind of shell executs no scripts.

## Shell Script Grammar

### conditional test

Use `test` or `[` command to test a condition.

Test commands include:

```
[ -d DIR ]: true if DIR is a directory
[ -f FILE ]: true if FILE exists.
[ -z STRING ]: true if len(STRING) is 0
[ -n STRING ]: true if len(STRING) > 0
[ STRING1 = STRING2 ]: true if STRING1 equals STRING2 
[ STRING1 != STRING2 ]: true if STRING1 doesn't equal STRING2 
[ ARG1 OP ARG2 ]: ARG1 and ARG2 should be numbers.
OP can be:
  -eq: =
  -ne: !=
  -lt: <
  -le: <=
  -gt: >
  -gt: >=
```

Shell also supports logical expressions:
```
[ ! EXPR ]: reverse EXPR
[ EXPR1 -a EXPR2 ]: and
[ EXPR1 -o EXPR2 ]: or
```

### conditioncal branching

Shell supports `if`, `else`, `elif`, `fi`, which are similar with C. See a
short example below:
```
## Bash Startup Scripts

### interactive login shell

When login:

1) run `/etc/profile`
2) search and run `~/.bash_profile`, `~/.bash_login` and `~/.profile`

When logout: run `~/.bash_logout`

### interacitve non-login shell

When using `ssh`, run terminal program or type `bash` in a shell, you get an
interactive non-login shell.

This kind of shell will run `~/.bashrc`.

Usually we recommend putting your local var, env, and alias in this file.

### non-interactive shell

A non-interactive shell is created to execute a shell script. It inherits all
env but not local var and alias.

This kind of shell executs no scripts.

## Shell Script Grammar

### conditional test

Use `test` or `[` command to test a condition.

Test commands include:

```
[ -d DIR ]: true if DIR is a directory
[ -f FILE ]: true if FILE exists.
[ -z STRING ]: true if len(STRING) is 0
[ -n STRING ]: true if len(STRING) > 0
[ STRING1 = STRING2 ]: true if STRING1 equals STRING2 
[ STRING1 != STRING2 ]: true if STRING1 doesn't equal STRING2 
[ ARG1 OP ARG2 ]: ARG1 and ARG2 should be numbers.
OP can be:
  -eq: =
  -ne: !=
  -lt: <
  -le: <=
  -gt: >
  -gt: >=
```

Shell also supports logical expressions:
```
[ ! EXPR ]: reverse EXPR
[ EXPR1 -a EXPR2 ]: and
[ EXPR1 -o EXPR2 ]: or
```

### conditioncal branching

Shell supports `if`, `else`, `elif`, `fi`, which are similar with C. See a
short example below:
```
if [ "$INPUT" = "yes" ]; then
   echo "good morning"
elif [ "$INPUT" = "no" ]; then
   echo "good evening"
else
   echo "bye bye"
fi
```

In shell, `&&` and `||` can be used to connect commands.
`&&` means `if ... then ...`, `||` measn `if not ... then ...`.

Shell also support `case`, which is similar with `switch/case` in C. See a 
simple program below:

```
case $COLOR in 
red|Red)
   echo "red";;
[gG]*)
   echo "green;;
*)
   echo "not found";;
```

All commands must end with `;;`.

### loop

For loop looks like `foreach`:
```
for COLOR in red, green, blue; do
   echo "I like $COLOR"
done
```

While loop is similar with while in C:
```
COUNTER=1
while [ "$COUNTER" -le "10" ]; do
   echo "number = $COUNTER"
   COUNTER=$(($COUNTER+1))
done
```

### special var

```
$0, $1, $2..., $n: command-line args, argv[n] in C
$#: argc - 1
$@: argument list(except $0), i.e.,  "$1" "$2" ...
$?: exit status of last command
$$: PID of current shell
```

An interesting special var is `$IFS`, complete name is "Internal Field
Separator", which specifies the default separator when you input from console.

### function

See a sample function below:

```
print_max()
{
   if [ $# -eq 0 ]; then
      return 1
   MAX=$1
   for NUM in $@; do
      if [ $NUM -gt $MAX ]; then
         MAX=$NUM
      fi
   done
   echo "$MAX"
   return 0
}
```

## How to debug shell script

1) `-n`: read the script but not execute
2) `-v`: run the script, print all commands to stderr
3) `-x`: run and print all commands and output to stdout

use `+` to disable debug argument.
