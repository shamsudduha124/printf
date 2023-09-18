#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct flags - Structure containing flags to enable specific formatting options
 * @pl: for '+'
 * @spc: for dash
 * @ash: for '#'
 */
typedef struct flags
{
	int pl;
	int spc;
	int ash;
} log_t;
/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, log_t *f);
} ph;
/* print_nums */
int print_int(va_list l, log_t *f);
void print_number(int n);
int print_unsigned(va_list l, log_t *f);
int count_digit(int i);
/* base_prints */
int print_hexagon(va_list l, log_t *f);
int print_hexagon_big(va_list l, log_t *f);
int print_binary(va_list l, log_t *f);
int print_octal(va_list l, log_t *f);
/* converter */
char *convert(unsigned long int num, int base, int lowercase);
/* _printf */
int _printf(const char *format, ...);
/* get_print */
int (*get_print(char s))(va_list, log_t *);
/* get_flag */
int get_flag(char s, log_t *f);
/* print_alpha */
int print_string(va_list l, log_t *f);
int print_char(va_list l, log_t *f);
/* write_funcs */
int _putchar(char c);
int _puts(char *str);
/* print_custom */
int print_rot13(va_list l, log_t *f);
int print_rev(va_list l, log_t *f);
int print_bigS(va_list l, log_t *f);
/* print_address */
int print_address(va_list l, log_t *f);
/* print_percent */
int print_percent(va_list l, log_t *f);
#endif
