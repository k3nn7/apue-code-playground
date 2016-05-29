## Chapter 3

File I/O

### `hole.c`

Example usage of `open` and `lseek` functions to create file with "hole".

Usage

`cc hole.c && ./a.out file.hole`

To analyse created file contents type:

`od -c file.hole`
