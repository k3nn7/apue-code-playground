## Chapter 1

Overview of UNIX environment

### `ls.c`

Bare-bones implementation of `ls` command based on `opendir` and `readdir` functions.
Error handling with `errno` variable and `perror` function.

Usage:

`cc ls.c && ./a.out <dirname>`

### `copy.c`

Unbuffered I/O example. Copies `STDIN` to `STDOUT`.

Usage:

`cc copy.c && ./a.out < input > output`

### `stdio_copy.c`

Copies `STDIN` to `STDOUT`. Implementation based on `stdio.h` library.

Usage:

`cc stdio_copy.c && ./a.out < input > output`

### `user.c`

Obtains current user ID and group ID with `getuid` and `getgid` functions.

Usage:

`cc user.c && ./a.out`

### `mypid.c`

Obtains their process ID with `mypid` function.

Usage:

`cc mypid.c && ./a.out`

### `signals.c`

Example of signals catching with `signal` function.

Usage:

`cc signals.c && ./a.out`

