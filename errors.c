#include "shell.h"

/**
 * _eputs - Prints a message to the error stream.
 * @message: The message to be printed.
 *
 * Description: This function prints the provided message to the standard error stream (stderr).
 *
 * Return: Nothing.
 */
void _eputs(char *message)
{
    int i = 0;

    if (!message)
        return;
    
    while (message[i] != '\0')
    {
        _eputchar(message[i]);
        i++;
    }
}

/**
 * _eputchar - Writes a character to the error stream.
 * @c: The character to print.
 *
 * Description: This function writes the provided character to the standard error stream (stderr).
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(2, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return (1);
}

/**
 * _putfd - Writes a character to a given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Description: This function writes the provided character to the specified file descriptor.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return (1);
}

/**
 * _putsfd - Prints a message to a specified file descriptor.
 * @message: The message to be printed.
 * @fd: The file descriptor to write to.
 *
 * Description: This function writes the provided message to the specified file descriptor.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *message, int fd)
{
    int i = 0;

    if (!message)
        return (0);

    while (*message)
    {
        i += _putfd(*message++, fd);
    }

    return (i);
}

