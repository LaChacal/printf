#include "main.h"

int _printf(const char *formart, ...)
{
	va_list args;
	unsigned int i, count;
	char seq, print_buffer[(BUFFER_LEN) + 1], *str;

	count = i = seq = 0;
	va_start(args, formart);
	for (i = 0; formart && formart[i] != '\0'; i++)
	{
		if (seq)
		{
			switch (formart[i])
			{
			case 'd':
			case 'i':
				str = int2str(va_arg(args, int));
				break;
			case 's':
				str = str2str(va_arg(args, char *));
				break;
			case 'c':
				seq = 0;
				i--;
				break;
			default:
				seq = 0;
				buffer_controller(print_buffer, "%", 1, 0);
				count++;
				i--;
				break;
			}
			if (seq)
			{
				if (str != ((void *) 0))
				{
					count += buffer_controller(print_buffer, str, _strlen(str), 0);
					seq = 0;
				}
			}
		}
		else
		{
			if (formart[i] == '%')
			{
				seq = 1;
			}
			else
			{
				buffer_controller(print_buffer, &formart[i], 1, 0);
				count++;
			}
		}
	}
	buffer_controller(print_buffer, "", 1, 1);
	va_end(args);
	return (count);
}
