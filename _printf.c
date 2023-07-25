#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the getPrint() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
<<<<<<< HEAD
	flags_t flags = {0, 0, 0};
=======
	flags_t flags; 
	flags = {0, 0, 0};
>>>>>>> c94b4b7f5320286d86638765538c9c967a127961

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (getFlag(*p, &flags))
				p++;
			pfunc = getPrint(*p);
			count += (pfunc)
<<<<<<< HEAD
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
=======
			? pfunc(arguments, &flags)
			: _printf("%%%c", *p);
	} else
>>>>>>> c94b4b7f5320286d86638765538c9c967a127961
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
