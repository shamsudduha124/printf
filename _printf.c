#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
<<<<<<< HEAD
 * _printf - Produces output according to a format
 * @format: The format of the string.
 * Return: The number of characters printed
=======
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that wil
 * specifiers contained into fmt
 * Return: length of the formatted output string
>>>>>>> 670c1afc96bd2245cebf9ce831b68c84ac5b6e44
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, n = 0;

	while (format[i] != 0)
	{
		if (format[i] == '%')
			n++;
		i++;
	}
	write(1, format, n);
	printf("We have %d formatters\n", n);
	return (n);
}
