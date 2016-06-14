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

### `umask.c`

Example that shows how different values passed to `umask` function affects permissions of files created by process

Usage:

`cc umask.c`

It creates 3 files with different umask set before:

* `1foo` - with default umask (inherited from parent process)
* `2foo` - with umask 0
* `3foo` - with umask `S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH`
