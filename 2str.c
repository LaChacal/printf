#include <stdlib.h>
#include "main.h"
/**
 * int2str - converts an integer to an str
 * @num: The integer to convert
 * Return: the int in a string
 */
char *int2str(int num)
{
	unsigned int len;
	int temp, i;
	char *str, neg;

	temp = num;
	for (len = 1; temp / 10; len++)
	{
		temp = temp / 10;
	}
	if (num < 0)
	{
		neg = 1;
		num *= -1;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (str);
	}
	str[len] = '\0';
	temp = num;
	for (i = len - 1; i >= 0 ; i--)
	{
		str[i] = (char) ((temp % 10) + '0');
		temp /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

/**
 * uint2str - converts an unsigned integer to an str
 * @num: The unsigned integer to convert
 * Return: the unsigned int in a string
 */
char *uint2str(const unsigned int num)
{
	unsigned int len;
	int temp, i;
	char *str;

	temp = num;
	for (len = 1; temp / 10; len++)
	{
		temp = temp / 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (str);
	}
	str[len] = '\0';
	temp = num;
	for (i = len - 1; i >= 0 ; i--)
	{
		str[i] = (char) ((temp % 10) + '0');
		temp /= 10;
	}
	return (str);
}
/**
 * uoct2str - converts an unsigned oct to an str
 * @num: The unsigned oct to convert
 * Return: the unsigned oct in a string
 */
char *uoct2str(const unsigned int num)
{
	unsigned int len;
	int temp, i;
	char *str;

	temp = num;
	for (len = 1; temp / 8; len++)
	{
		temp = temp / 8;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (str);
	}
	str[len] = '\0';
	temp = num;
	for (i = len - 1; i >= 0 ; i--)
	{
		str[i] = (char) ((temp % 8) + '0');
		temp /= 8;
	}
	return (str);
}
/**
 * uhex2str - converts an unsigned hex to an str
 * @num: The unsigned hex to convert
 * Return: the unsigned hex in a string
 */
char *uhex2str(const unsigned int num)
{
	unsigned int len;
	int temp, i;
	char *str;
	char hex[] = "0123456789abcdef";

	temp = num;
	for (len = 1; temp / 16; len++)
	{
		temp = temp / 16;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (str);
	}
	str[len] = '\0';
	temp = num;
	for (i = len - 1; i >= 0 ; i--)
	{
		str[i] = hex[(temp % 16)];
		temp /= 16;
	}
	return (str);
}
/**
 * UHEX2str - converts an unsigned hex to an str
 * @num: The unsigned hex to convert
 * Return: the unsigned hex in a string CAPITALIZED
 */
char *UHEX2str(const unsigned int num)
{
	unsigned int len;
	int temp, i;
	char *str;
	char hex[] = "0123456789ABCDEF";

	temp = num;
	for (len = 1; temp / 16; len++)
	{
		temp = temp / 16;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (str);
	}
	str[len] = '\0';
	temp = num;
	for (i = len - 1; i >= 0 ; i--)
	{
		str[i] = hex[(temp % 16)];
		temp /= 16;
	}
	return (str);
}
/**
 * addr2str - converts an address to an str
 * @num: The address to convert
 * Return: the address hex in a string
 */
char *addr2str(const char *num)
{
	unsigned int len;
	int temp, i;
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
