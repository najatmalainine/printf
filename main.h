#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} print_H;

/* Numbers */
int printInt(va_list l, flags_t *f);
void printNum(int n);
int printUns(va_list l, flags_t *f);
int countDig(int i);

/* Bases */
int printHex(va_list l, flags_t *f);
int printHex_b(va_list l, flags_t *f);
int printBinary(va_list l, flags_t *f);
int printOctal(va_list l, flags_t *f);

/* Convert */
char *convert(unsigned long int num, int base, int lowercase);

/* the printf function */
int _printf(const char *format, ...);

/* getPrint */
int (*getPrint(char s))(va_list, flags_t *);

/* getFlag */
int getFlag(char s, flags_t *f);

/* print_alpha */
int printStr(va_list l, flags_t *f);
int printChar(va_list l, flags_t *f);

/* write functions */
int _putchar(char c);
int _puts(char *str);

/* print Rot13, Reverse and Big string */
int printRot13(va_list l, flags_t *f);
int printRev(va_list l, flags_t *f);
int printBigS(va_list l, flags_t *f);

/* print address */
int printAdd(va_list l, flags_t *f);

/* print percent */
int printPer(va_list l, flags_t *f);
#endif
