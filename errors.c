#include "shell.h"

/**
<<<<<<< HEAD
 * _eputs - Prints input string
 * @str: String t/o be printed
=======
 * _eputs - Prints a message to the error stream.
 * @message: The message to be printed.
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
 *
 * Description: This function prints the provided message to the standard error stream (stderr).
 *
 * Return: Nothing.
 */
<<<<<<< HEAD
void _eputs(char *str)
=======
void _eputs(char *message)
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
{
    int i = 0;

<<<<<<< HEAD
	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes character c to stderr
 * @c: Character to print
=======
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
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
 *
 * Return: Success 1.
 * On error, -1 is returned, errno is set appropriately.
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
<<<<<<< HEAD
 * _putfd - Writes character c to given fd
 * @c: Character to print
 * @fd: Filedescriptor to write to
=======
 * _putfd - Writes a character to a given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Description: This function writes the provided character to the specified file descriptor.
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
 *
 * Return: Success 1.
 * On error, -1 is returned, errno is set appropriately.
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
<<<<<<< HEAD
 * _putsfd - Prints input string
 * @str: String to be printed
 * @fd: Filedescriptor to write to
 *
 * Return: Number of characters put
 */
int _putsfd(char *str, int fd)
=======
 * _putsfd - Prints a message to a specified file descriptor.
 * @message: The message to be printed.
 * @fd: The file descriptor to write to.
 *
 * Description: This function writes the provided message to the specified file descriptor.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *message, int fd)
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
{
    int i = 0;

    if (!message)
        return (0);

    while (*message)
    {
        i += _putfd(*message++, fd);
    }

<<<<<<< HEAD
	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
=======
    return (i);
>>>>>>> 808132e1968d01c91ea47744ac157f6f7e912958
}
