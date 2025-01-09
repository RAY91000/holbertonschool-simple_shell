![Holberton school image (1)](https://holberton.anahuacmayab.mx/wp-content/uploads/2022/06/Holberton-Logo-v1.png)
# Simple Shell Project
A shell is a type of computer program called a command-line interpreter that lets Linux and Unix users control their operating systems with command-line interfaces. Shells allow users to communicate efficiently and directly with their operating systems.
This project has for goal to replicate its basic usage and features such as command implementation and directory navigation.

# Flowchart
![Flowchart image (1)](https://lucid.app/publicSegments/view/4a97a26a-c372-4c13-921d-6e66d5494b85/image.png)

# Project Requirements
General
 
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

### List of allowed functions and system calls+

- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

## How It Works

You will need to compile all the files for the program to work. You can compile using:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

Then you can test the program either in interactive mode:
```
hikarikedo@HikariKedosPC:~/holbertonschool-simple_shell$ ./hsh
#cisfun$ /bin/ls
AUTHORS    command_exists.c   handle_execve.c     hsh     man_1_simple_shell  shell.h          test_c
README.md  execute_command.c  handle_exit_echo.c  main.c  shell.c             split_command.c
#cisfun$
```
 Or in non-interactive mode:
```
hikarikedo@HikariKedosPC:~/holbertonschool-simple_shell$ echo "/bin/ls" | ./hsh
AUTHORS    command_exists.c   handle_execve.c     hsh     man_1_simple_shell  shell.h          test_c
README.md  execute_command.c  handle_exit_echo.c  main.c  shell.c             split_command.c
hikarikedo@HikariKedosPC:~/holbertonschool-simple_shell$
```

## Project Files

| Files | Purpose |
| :---------------: | :---------------: |
| main.c | The entry point of the shell program |
| shell.c | Contains utility functions for prompt display and input reading |
| split_command.c | Splits a command line string into an array of arguments |
| execute_command.c | Handles command execution |
| command_exists.c | Checks if a command exists in the system’s PATH |
| handle_execve.c | Executes commands using the execve system call |
| handle_exit_echo.c | Implements built-in commands exit and echo |
| shell.h | Header file containing shared definitions and function prototypes |

## Coding Style
Here, at Holberton School, we have a specific coding style that makes our codes look clean and easy to read:

Its called the [Betty-style](https://github.com/hs-hq/Betty/blob/main/betty-style.pl). With this we respect numerous spacing and syntaxes which is very useful to improve one's code clarity.

## Man Page
Here is our [manual page](https://github.com/RAY91000/holbertonschool-simple_shell/blob/main/man_1_simple_shell). Feel free to check it out!

## Authors
The [Authors](https://github.com/RAY91000/holbertonschool-simple_shell/blob/main/AUTHORS) of this project were: 

-[Kerian](https://github.com/Hikarikedo)

-[Ray](https://github.com/RAY91000)
