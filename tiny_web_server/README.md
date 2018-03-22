This is a small web server called TINY. The source code is from CSAPP book.

Use the following command to run TINY

```
gcc csapp.c tiny.c
gcc ./cgi-bin/sum.c -o ./cgi-bin/sum
./a.out
```

example of running sum:
```
http://127.0.0.1:15555/cgi-bin/sum?15000&15
```

example of getting a static pge:
```
http://127.0.0.1:15555/home.html
```
