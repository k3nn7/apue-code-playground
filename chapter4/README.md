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

### `access.c`

Uses `faccessat` function to display real user and effective user prermissions for file provided as an argument.

Usage:

`cc access.c && ./a.out ./bin/bash`

Example output:
```
File /bin/bash:
+ Readable for real user id
- Writable for real user id
+ Executable for real user id
+ Readable for effective user id
- Writable for effective user id
+ Executable for effective user id
```
