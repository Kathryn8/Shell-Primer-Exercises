#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

/**
 * main - print PID MAX
 *
 * Return: Always 0.
 */
int main(void)
{
    ssize_t rb;
    char buffer[1024];
    int fd;

    fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
    rb = read(fd, buffer, 1024);
    printf("%s\n", buffer);
    close(fd);
    return (0);
}
