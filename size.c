#include "main.h"

/**
 * get_size - calculates size of arguments
 * @format: string formatted
 * @a: arguments printed
 * Return: size
 */
int get_size(const char *format, int *a)
{
	int f = *a + 1;
	int size = 0;

	if (format[f] == 'l')
		size = S_LONG;
	else if (format[f] == 'h')
		size = S_SHORT;
	if (size == 0)
		*a = f - 1;
	else
		*a = f;
	return (size);
}
