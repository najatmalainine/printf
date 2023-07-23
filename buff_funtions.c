#include "main.h"

/**
 * get_func - returns needed function
 * @i: identifier for function
 * Return: Pointer to needed function
 */
char* (*get_func(char i))(va_list)
{
	int k = 0;

	print keys[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', itob},
		{'R', rot13},
		{'r', rev_string},
		{'o', itoOctal},
		{'\0', NULL}
	};

	while (keys[k].id != '\0')
	{
		if (keys[k].id == i)
			return (keys[k].func);
		k++;
	}
	return (NULL);
}

/**
 * create_buffer - creates buffer to hold string until it's ready for print
 * Return: pointer to buffer created
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	return (buffer);
}

/**
 * write_buffer - prints buffer, then frees it and frees va_list
 * @buffer: buffer holding print-ables
 * @len: length of print-able string
 * @list: va_list
 */
void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len);
	write(1, buff, len);

	free(buff); va_end(list);
}


/**
 * _strcpy - Copies information from each element
 * @dest: destination file
 * @src: source file
 * Return: array
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = src[x];
	return (dest);
}

/**
 * _strlen - prints length string in integer
 * @s: string passed to function
 * Return: a
 */
int _strlen(char *s)
{
	int a = 0;

	while (*(s + a))
		a++;

	return (a);
}
