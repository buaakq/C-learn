# Shell

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

Usually shell forks* a new process and call `exec` to execute a target command,
except for builtin commands, which trigger a function call of the shell process.

Commond builtin commands include `cd`, `alias`, `umask`, `exit`, etc.

If run `(command)`, current shell will fork a new process to execute this
command instead of running it in current shell.

Shell also supports running a shell script - a collection of shell commands.

There are differnt ways to run a shell script:

- 1) `/bin/bash ./script.sh`
- 2) `./script.sh`
- 3) `source ./script.sh`
- 4) `. ./script.sh`

1) = 2): running the script in a child process.
3) = 4): running the script in a current shell process.

## Basic Shell Grammar

### Variables

Two kinds of vairables in shell:
* local: `VAR=value`
* env: `VAR=value`

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
- \$ = $
- \\ = \
- \` = `
- \\ = \
- \" = "
```
