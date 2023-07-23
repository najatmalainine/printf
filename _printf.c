#include "main.h"

int val_precentage(const char *format, int *i);

/**
 * _printf - prints a formatted string to stdout, similar to printf.
 * @format: the format of the string to be printed.
 *
 * This function prints a formatted string to the stdout stream. It
 * accepts a format string as its first argument and any additional arguments
 * will be used to replace format specifiers in the format string. The function
 *
 * Return: the number of characters printed to the stdout stream.
 */
int _printf(const char *format, ...)
{
	va_list args, args_flags, args_width;
	flags_t flags = {0};
	width_t width = {0};
	int (*print_fn)(va_list);
	int i = 0, prd = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	(va_copy(args_flags, args), va_copy(args_width, args));
	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!val_precentage(format, &i))
				return (-1);
			/* get conversion_index by getting [flags, width..] first */
			print_fn = get_conversion(format, &i, args, &flags, &width);

			par_flags(&flags, args_flags, print_fn, &prd);
			par_width(&width, args_width, print_fn, &prd);
			par_length(&flags, args, print_fn, &prd);

			/* check length outside this func*/
			if (flags.h || flags.l)
				continue;
			/* for valid conversion call print_func, otherwise print as is*/
			prd += print_fn
						   ? print_fn(args)
						   : _putchar('%') + _putchar(format[i]);
		}
		else
			prd += _putchar(format[i]);
	}
	va_end(args);
	(va_end(args_flags), va_end(args_width));
	return (prd);
}

/**
 * val_precentage - valid percentages
 * @format: The string to be evaluated
 * @i: Pointer to the index of the character being evaluated
 * Return: 1 if valid specifer, 0 otherwise
 */
int val_precentage(const char *format, int *i)
{
	int k;

	if (format[++(*i)] == '\0')
		return (0);
	k = *i;

	/* check if no caractere after '%', return false */
	for (; format[k] == ' '; k++)
	{
		if (format[*i + 1] == '\0')
			return (0);
		else if (format[*i + 1] == ' ')
			(*i)++;
		else
			break;
	}
	/* ignore extra val_precentage between '%' and 'specefier' */
	return (1);
}
