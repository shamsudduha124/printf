#include "main.h"

/**
 * print_string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_string(va_list l, log_t *f)
{
	char *stress = va_arg(l, char *);

	(void)f;

	stress = stress ? stress : "(null)";
    return (_puts(stress));
}

int print_char(va_list l, log_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
