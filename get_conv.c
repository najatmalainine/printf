#include "main.h"


char *convert(unsigned long int num, int base, int low)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (low)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
