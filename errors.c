#include "shell.h"

/**
 * _eputs - This prints an input string
 * @str: This is the string to print
 *
 * Return: Null
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - This writes the char c to stderr
 * @c: This is the char to be printed
 *
 * Return: This returns 1 if sucessful
 * but while at error, -1 is returned, and errno is set
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
 * _putfd - This writes the char c to given FD
 * @c: This is the chara to be printed
 * @fd: This is the File Descriptor that is to be written into
 *
 * Return: This returns 1 if sucessful
 * but while at error, -1 is returned, and errno is set
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
 * _putsfd - This actually prints the input string
 * @str: This string is to be printed
 * @fd: This is the File Descriptor to be written into
 *
 * Return: This returns the number of character put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
