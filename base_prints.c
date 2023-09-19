#include "main.h"
/**
 * print_hex - prints a number in hexadecimal base,
 * in lowercase
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 * Return: the number of char printed
 */

int print_hexagon(va_list l, log_t *f)
{
	unsigned int number = va_arg(l, unsigned int);
	char *str = convert(number, 16, 1);
	int count = 0;

	if (f->ash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_hex_big - Print a number in hexadecimal base (uppercase).
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Description: the function calls convert() which in turns converts the input
 * uppercase letters (A-F). It utilizes the convert() function to convert
 * Return: The number of characters printed.
 */
int print_hexagon_big(va_list l, log_t *f)
{
	unsigned int number = va_arg(l, unsigned int);
	char *str = convert(number, 16, 0);
	int count = 0;

	if (f->ash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}

/**
 * print_binary - prints a number in base 2
 * Description: the function calls convert() which in turns converts the input
 * number into the correct base and returns it as a string
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: the number of char printed
 */
int print_binary(va_list l, log_t *f)
{
	unsigned int number = va_arg(l, unsigned int);
	char *str = convert(number, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_octal - prints a numberber in base 8
 * Description: the function calls convert() which in turns converts the input
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: the numberber of char printed
 */
int print_octal(va_list l, log_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (f->ash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}
