#include "main.h"

/**
 * print_int - prints an integer
 * Return: number of char printed
 */
int print_int(va_list l, log_t *f)
{
	int n = va_arg(l, int);
	int res = count_digit(n);

	if (f->spc == 1 && f->pl == 0 && n >= 0)
		res += _putchar(' ');
	if (f->pl == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	print_number(n);
	return (res);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list l, log_t *f)
{
	unsigned int w = va_arg(l, unsigned int);
	char *str = convert(w, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int n13;

	if (n < 0)
	{
		_putchar('-');
		n13 = -n;
	}
	else
		n13 = n;

	if (n13 / 10)
		print_number(n13 / 10);
	_putchar((n13 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int e = 0;
	unsigned int w;

	if (i < 0)
		w = i * -1;
	else
		w = i;
	while (w != 0)
	{
		w /= 10;
		e++;
	}
	return (e);
}
