## Chapter 4

Files and Directories

### `lstat.c`

Uses `lstat` function to determine file type and size

Usage:

`cc lstat.c && ./a.out /dev/tty /dev/zero /var/run/docker.sock /dev/stdin`


Example output:
```
File /dev/tty:
- Type: character device
- Size: 0
- Last access time: 1466972664 s 480739478 ns
- Last modification time: 1466971574 s 480739478 ns
File /dev/zero:
- Type: character device
- Size: 0
- Last access time: 1466971574 s 472739478 ns
- Last modification time: 1466971574 s 472739478 ns
File /var/run/docker.sock:
- Type: socket
- Size: 0
- Last access time: 1466971586 s 220739494 ns
- Last modification time: 1466971586 s 220739494 ns
File /dev/stdin:
- Type: symbolic link
- Size: 15
- Last access time: 1466971496 s 508000039 ns
- Last modification time: 1466971496 s 508000039 ns
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

### `link.c`

Creates symbolic link using `link` function.

Usage:
`cc link.c && ./a.out ./source ./destination`

### `unlink.c`

Example of `unlink` function. Demonstrates that unlinking file isn't equivalent to removing file data from disk.

Usage:
`cc unlink.c && ./a.out`

### `futimens.c`

Uses `futimens` function to modify file access and modification times. Given file will be truncated but access and modification time will be left unchanged.

Usage:
`cc futimens.c && ./a.out <path>`
