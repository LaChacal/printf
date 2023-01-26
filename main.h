#ifndef MAIN_H_HEADER
#define MAIN_H_HEADER boing
#define BUFFER_LEN 1024
#include <stdarg.h>

struct modifer{
	char left_just;
	char filler;
	char sign;
	unsigned int width;
	unsigned int endindx;
};
typedef struct sel
{
	char seq;
	char *(*f)(va_list *);
} op_t;

int _putchar(char c);
unsigned int _strlen(const char *s);
char *reversestr(const char *str);
char *int2str(int num);
char *uint2str(const unsigned int);
char *uoct2str(const unsigned int);
char *uhex2str(const unsigned int);
char *UHEX2str(const unsigned int);
char *addr2str(const char *);
char *str2str(const char *);
int buffer_controller(char *, const char *str, int mx, char);
int flush_buffer(char *,unsigned int);

int _printf(const char *formart, ...);

#endif
