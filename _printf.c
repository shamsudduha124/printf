#include "main.h"
#include <limits.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that wil
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, log_t *);
	const char *p;
	va_list arguments;
	log_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (p = format; *p; p++)
	{
		switch (*p)
		{
		case '%':
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
			{
				p++;
			}
			pfunc = get_print(*p);
			count += (pfunc) ? pfunc(arguments, &flags) : _printf("%%%c", *p);
			break;
		default:
			count += _putchar(*p);
			break;
		}
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
