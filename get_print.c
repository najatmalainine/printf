#include "main.h"

/**
 * getPrint - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * Return: a pointer to the matching printing function
 */
int (*getPrint(char s))(va_list, flags_t *)
{
	print_H f_arr[] = {
		{'i', printInt},
		{'s', printStr},
		{'c', printChar},
		{'d', printInt},
		{'u', printUns},
		{'x', printHex},
		{'X', printHex_b},
		{'b', printBinary},
		{'o', printOctal},
		{'R', printRot13},
		{'r', printRev},
		{'S', printBigS},
		{'p', printAdd},
		{'%', printPer}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (f_arr[i].c == s)
			return (f_arr[i].f);
	return (NULL);
}
