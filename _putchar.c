#include <unistd.h>
#include <stdlib.h>
/**
 * _putchar - writes a single character to standard output
 * @c: The character passed in to print
 * Return: Return output success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - Returns the length of a string.
 * @s : String pointer
 *
 * Return: Returns the length of the array
 */
unsigned int _strlen(char *s)
{
	unsigned int siz = 0;

	while (s[siz] != '\0')
	{
		siz++;
	}
	return (siz);
}



/**
 * reversestr - reverse a string
 * @str: string to reverse
 * Return: Returns the passed string reversed
 */
char *reversestr(char *str)
{
	unsigned int siz, i;
	char temp;

	siz = _strlen(str);

	for (i = 0; i <= ((siz - 1) / 2); i++)
	{
		temp = str[i];
		str[i] = str[siz - i - 1];
		str[siz - i - 1] = temp;
	}

	return (str);
}

