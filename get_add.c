#include "main.h"

/**
 * printAdd - prints address of input in hexa format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printAdd(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p;

	register int count;

	p = va_arg(l, unsigned long int);
	count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
