## Chapter 4

Files and Directories

### `lstat.c`

Uses `lstat` function to determine file type

Usage:

`cc lstat.c && ./a.out /dev/tty /dev/zero /dev/disk0 /var/run/syslog /dev/stdin`

Example output:
```
./a.out: regular
/dev/tty: character device
/dev/zero: character device
/dev/disk0: block device
/var/run/syslog: socket
/dev/stdin: symbolic link
```
