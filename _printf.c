#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - print fomated outpt
 * @format: fomat str containin charactas and specifier
 *
 * Descriptn: Ths functn prints fomated otput basd on the fomat
 * string prided. It calls the get_print() function to determine which
 * printing function to use for each conversion specifier.
 *
 * Return: The number of characters printed (excluding the null byte
 * used to end output to strings),  error.
 */
int _printf(const char *format, ...)
{
	int (*shamzfunc)(va_list, flags_t *);
	const char *shamz;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (shamz = format; *shamz; shamz++)
	{
		switch (*shamz)
		{
		case '%':
			shamz++;
			if (*shamz == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*shamz, &flags))
				shamz++;
			shamzfunc = get_print(*shamz);
			count += (shamzfunc)
				? shamzfunc(arguments, &flags)
				: _printf("%%%c", *shamz);
			break;

		default:
			count += _putchar(*shamz);
			break;
		}
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
