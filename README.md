# README
### Everything you need to know to start coding your own shell

Exercises to prepare and practice concepts before we begin the simple shell project

## Table of Contents:

### PID & PPID
* 0. getppid
* 1. /proc/sys/kernel/pid_max

### Arguments
    #### 0. av
    #### 1. Read line
    #### 2. command line to av

### Exercise: fork + wait + execve

### Exercise: super simple shell

### File information
    #### Exercise: find a file in the PATH

### Environment
    #### 0. printenv with environ
    #### 1. env vs environ
    #### 2. getenv()
    #### 3. PATH
    #### 4. PATH
    #### 5. setenv
    #### 6. unsetenv

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

### Exercise: super simple shell
Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument.
```
julien@ubuntu:~/c/shell$ l
total 140
drwxrwxr-x  2 julien julien 4096 Dec  4 20:55 .
drwxrwxr-x 17 julien julien 4096 Dec  4 13:04 ..
-rw-rw-r--  1 julien julien  249 Dec  4 13:15 env-environ.c
-rw-rw-r--  1 julien julien  231 Dec  4 13:09 env-main.c
-rwxrwxr-x  1 julien julien 8768 Dec  4 19:52 exec
-rw-rw-r--  1 julien julien  302 Dec  4 19:38 exec.c
-rwxrwxr-x  1 julien julien 8760 Dec  4 20:11 fork
-rw-rw-r--  1 julien julien  438 Dec  4 19:57 fork.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:45 mypid
-rw-rw-r--  1 julien julien  179 Dec  4 19:49 pid.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:48 ppid
-rw-rw-r--  1 julien julien  180 Dec  4 13:48 ppid.c
-rwxrwxr-x  1 julien julien 8680 Dec  4 13:44 printenv
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 prompt
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 promptc
-rw-rw-r--  1 julien julien  191 Dec  4 14:17 prompt.c
-rw-rw-r--  1 julien julien  753 Dec  4 20:49 shell.c
-rwxrwxr-x  1 julien julien 8864 Dec  4 20:38 wait
-rw-rw-r--  1 julien julien  441 Dec  4 20:15 wait.c
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic shell.c -o shell
julien@ubuntu:~/c/shell$ ./shell 
#cisfun$ /bin/ls
env-environ.c  exec    fork    mypid  ppid    printenv  promptc   shell    wait
env-main.c     exec.c  fork.c  pid.c  ppid.c  prompt    prompt.c  shell.c  wait.c
#cisfun$ ./ppid
5451
#cisfun$ ./ppid
5451
#cisfun$ ^C
julien@ubuntu:~/c/shell$
```

### File information

#### Exercise: find a file in the PATH
Write a program that looks for files in the current `PATH`.

Usage: `_which filename ...`

### Environment

#### 0. printenv with environ
Write a program that prints the environment using the global variable `environ`.

#### 1. env vs environ
Write a program that prints the address of env (the third parameter of the `main` function) and `environ` (the global variable). Are they they same? Does this make sense?

#### 2. getenv()
Write a function that gets an environment variable. (without using `getenv`)

Prototype: `char *_getenv(const char *name);	    
man 3 `getenv`

#### 3. PATH
Write a function that prints each directory contained in the the environment variable `PATH`, one directory per line.

#### 4. PATH
Write a function that builds a linked list of the `PATH` directories.

#### 5. setenv
Write a function that changes or adds an environment variable (without using `setenv`).

Prototype: `int _setenv(const char *name, const char *value, int overwrite);`
man 3 `setenv`

#### 6. unsetenv
Write a function that deletes the variable name from the environment (without using `unsetenv`).

Prototype: `int _unsetenv(const char *name);`
man 3 `unsetenv`
