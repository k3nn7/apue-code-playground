## Chapter 1

Overview of UNIX environment

### `ls.c`

Bare-bones implementation of `ls` command based on `opendir` and `readdir` functions.
Error handling with `errno` variable and `perror` function.

Usage:

`cc ls.c && ./a.out <dirname>`

### `copy.c`

Unbuffered I/O example. Copies `STDIN` to `STDOUT`.

`cc ls.c && ./a.out < input > output`
