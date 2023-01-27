#include "main.h"

/**
 * specifier2str - PRINTF
 * @formart: the string formart
 * @args: va list to use
 * Return: the length of string written
 */
char *specifier2str(const char *formart, va_list *args)
{
	char *str;
	unsigned int i;

	str = "hold something";
	i = str[1] - str[1];
	str = ((void *) 0);
	if ((formart[i] == 'd') || (formart[i] == 'i'))
		str = int2str(va_arg(*args, int));
	else if (formart[i] == 's')
		str = str2str(va_arg(*args, char *));
	else if (formart[i] == 'u')
		str = uint2str(va_arg(*args, unsigned int));
	else if (formart[i] == 'o')
		str = uoct2str(va_arg(*args, unsigned int));
	else if (formart[i] == 'x')
		str = uhex2str(va_arg(*args, unsigned int));
	else if (formart[i] == 'X')
		str = UHEX2str(va_arg(*args, unsigned int));
	return (str);
}
/**
 * _printf - PRINTF
 * @formart: the string formart
 * Return: the length of string written
 */
int _printf(const char *formart, ...)
{
	va_list args;
	unsigned int i, count;
	char seq, print_buffer[(BUFFER_LEN)], *str;

	count = i = seq = 0;
	va_start(args, formart);
	for (i = 0; formart && formart[i] != '\0'; i++)
	{
		if (seq)
		{
			str = specifier2str(&formart[i], &args);
			if (str == ((void *) 0))
			{
				seq = formart[i] == 'c' ? va_arg(args, int) : '%';
				count += buffer_controller(print_buffer, &seq, 'c');
				seq = 0;
				i = (formart[i] == '%') || (formart[i] == 'c') ? i : i - 1;
			}
			if ((seq) && (str != ((void *) 0)))
			{
				count += buffer_controller(print_buffer, str, 0);
				seq = 0;
				free(str);
			}
		}
		else
		{
			if (formart[i] == '%')
				seq = 1;
			else
			{
				buffer_controller(print_buffer, &formart[i], 'c');
				count++;
			}
		}
	}
	buffer_controller(print_buffer, "", 'f');
	va_end(args);
	return (count);
}
