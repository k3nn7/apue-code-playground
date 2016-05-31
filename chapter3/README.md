## Chapter 3

File I/O

### `hole.c`

Example usage of `open` and `lseek` functions to create file with "hole".

Usage

`cc hole.c && ./a.out file.hole`

To analyse created file contents type:

`od -c file.hole`

### `pwrite.c`

Example usage of `pwrite` which allows to perform `lseek` and `write` in single, atomic operation.

Usage

`cc pwrite.c && ./a.out out`

### `dup.c`

Example of file descriptor duplication with `dup`.
It also shows that offset is not associated with file descriptor but with file table entry;

Usage

`cc dup.c && ./a.out out`

### `fcntl.c`

Uses `fcntl` command to get file descriptor file status flags.

Usage

`cc fcntl.c && ./a.out 2 2>>out`

`cc fcntl.c && ./a.out 0`

`cc fcntl.c && ./a.out 2 2>out`
