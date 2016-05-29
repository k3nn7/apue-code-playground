## Chapter 2

UNIX standardization

Dominant standards:

* ISO C [C99](https://en.wikipedia.org/wiki/C99), [C11](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
* [POSIX](https://en.wikipedia.org/wiki/POSIX)
* [Single UNIX Specification](https://en.wikipedia.org/wiki/Single_UNIX_Specification)

### `limits.c`

Reads and displays limits defined in

* headers - available at compile time
* sysconf - configurable system variables available at runtime
* pathconf - configurable system variables associated with pathname available at runtime

Usage:

`cc ls.c && ./a.out <dirname>`
