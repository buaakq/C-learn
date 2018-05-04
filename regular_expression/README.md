## Introduction

Three key components of regular expressions:

- Character Class: specify a set of chars
- Quantifier: specify how many time a char can repeat
- Anchor: specify char's location

A quick example:

```
$ cat testfile
192.168.1.1
1234.234.04.5678
123.4234.045.678
abcde

# use egrep to find possible IP addresses in testfile

$ egrep '^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$' testfile
192.168.1.1
```

Note:
1) `egrep` = `grep -E`, use Extended spec.
2) use single quotes to include regular exp so it won't be explained by shell.

Actually, POSIX.2 gives much more complex definition of regex, as explained
below:

## Basic Grammar

See regex(7) for complete explanation of regex grammar.

Basically, a regex is one or more nonempty **branches** separated by `|`. It
matches anything that match one of the branches.

For instance, regex `hello|Hello` has two branches: `hello` and `Hello`.

A branch is one or more pieces, concatenated. It matches a match for the first,
followed by a match for the second, and so on.

For instance, `k+@` is a brnach , which has two pieces: `k+` and `@`.

A piece is an atom possibly followed by a quantifier, see below.

For instance, `k+` is a piece, in which `k` is an atom and `+` is a quantifier.

### Character Class (atom)

The smallest unit in regex is **atom**, which could be:
- an ordinary char, like a, b, c, 1, 2, -, etc.
- `\` followed by a special char (`^.[$()|*+?{\`)
- a regex enclosed in `()`
- `()`, which matches a null string
- `^`, which matches the beginning of the line
- `$`, which matches the end of the line
- `.` ,which matches any single char

In addition, an atom could be a **bracket expression** as well:
- `[]` matches any single char inside the quotes
- `[a-b]` matches any single char between a and b.
- `[^xy]` matches any single char but not x and y. 
- `[[:xxx:]]`: pre-defined special char class

### Quantifier

- `?` matches a sequence of 0 or 1 time of the atom
- `*` matches 0 or more times
- `+` matches 1 or more times

Another important quantifier called **bound**, enclosed by `[]`.

- `{N}` matches N times.
- `{N,}` matches at least N times.
- `{,M}` matches at most M times.
- `{N, M}` matches at least N times, at most M times.

## Case study: `sed`

sed is a stream editor. It's basic usage:
```
sed [option] [command] file1 file2 ...
```

Frequently-used sed options
- `-r`, used extended regex grammar
- `-n`, suppress automatic printing of pattern space
- `-i`, edit file in place

Frequently-used sed commands:
```
/pattern/p     # print all lines that match pattern
/pattern/d     # delete all lines that match pattern
/pattern/s/pattern1/pattern2 
# replace the first string that match p1 with p2 within lines that match p
/pattern/s/pattern1/pattern2 
# replace all strings that match p1 with p2 within lines that match p
```

Practice: use `sed` command to remove all html tags in a html file.
answer:
```
sed 's/<[^>]*>//g' file.html
```

Note: `sed 's/<.*>//g' file.html` is not correct, because all quantifiers in
regex will try to match as long strings as they can.

## Case Study: Use Regex in C

See regex(3) for the complete tutorial.
