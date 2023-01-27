#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * addr2str - converts an address to an str
 * @num: The address to convert
 * Return: the address hex in a string
 */
char *addr2str(const char *num)
{
	int i;
	char *str;
	char hex[] = "0123456789abcdef";

	str = malloc(12 + 3);
	if (str == NULL)
	{
		return (str);
	}
	str[15] = '\0';
	for (i = 0; i < (6); i++)
	{
		str[i * 2]          = hex[num[i + 1] / 16];
		str[(i * 2) + 1]    = hex[num[i + 1] % 16];
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

/**
 * str2str - converts an str to an str
 * @str: The string to convert
 * Return: the address of the string string
 */
char *str2str(const char *str)
{
	char *strret;
	unsigned int len, i;
	char hex_upper[] = "0123456789ABCDEF";

	len = i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] < 32 || str[1] >= 127)
			len += 4;
		else
			len++;
		i++;
	}
	strret = malloc(len + 1);
	if (strret == ((void *) 0))
	{
		return (strret);
	}
	strret[len] = '\0';
	len = i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[1] >= 127)
		{
			strret[len] = '\\';
			strret[len + 1] = 'x';
			strret[len + 2] = hex_upper[str[i] >> 4];
			strret[len + 3] = hex_upper[str[i] % 16];
			len += 4;
		}
		else
		{
			strret[len] = str[i];
			len++;
		}
		i++;
	}
	return (strret);
}
/**
 * buffer_controller - ensures the write function is not called too often
 * @print_buffer: the buffer
 * @str: The string write to buffer
 * @flush: flag to flush or add 1 char
 * Return: length of string written
 */
int buffer_controller(char *print_buffer, const char *str, char flush)
{
	static unsigned int indx;
	int i;

	i = 0;
	if ((str == ((void *) 0) || str[0] == '\0') && (flush == 'f'))
	{
		flush_buffer(print_buffer, indx);
		indx = 0;
		return (0);
	}
	if (flush == 'c')
	{
		print_buffer[indx] = str[0];
		i++;
		indx++;
		return (1);
	}
	while (str[i] != '\0')
	{
		if (indx > (BUFFER_LEN))
		{
			flush_buffer(print_buffer, (BUFFER_LEN));
			indx = 0;
		}
		else
		{
			print_buffer[indx] = str[i];
			i++;
			indx++;
		}
	}
	return (i);
}
/**
 * flush_buffer - clears out the buffer
 * @print_buffer: the buffer to write from
 * @len: the length to write
 * Return: length of string written to standard output
 */
int flush_buffer(char *print_buffer, unsigned int len)
{
	return (write(1, print_buffer, len));
}
