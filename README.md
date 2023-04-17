# README
### Everything you need to know to start coding your own shell

Exercises to prepare and practice concepts before we begin the simple shell project

## Table of Contents:

### PID & PPID

#### 0. getppid
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does `echo $$` print the same value? Why?

#### 1. /proc/sys/kernel/pid_max
Write a shell script that prints the maximum value a process ID can be.

### Arguments

#### 0. av
Write a program that prints all the arguments, without using `ac`.

#### 1. Read line
Write a program that prints `"$ "`, wait for the user to enter a command, prints it on the next line.

man 3 `getline`

**important:** make sure you read the man, and the RETURN VALUE section, in order to know when to stop reading Keyword: “end-of-file”, or `EOF` (or `Ctrl+D`).

**advanced:** Write your own version of `getline`.
```
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt
julien@ubuntu:~/c/shell$ ./prompt 
$ cat prompt.c
cat prompt.c
julien@ubuntu:~/c/shell$
```
#### 2. command line to av
Write a function that splits a string and returns an array of each word of the string.

man `strtok`

**advanced:** Write the function without `strtok`

### Exercise: fork + wait + execve
#### Write a program that executes the command `ls -l /tmp` in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.
