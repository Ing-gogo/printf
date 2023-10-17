#include "main.h"

/**
 * get_precision - counts the precision for printing
 * @format: string formatted
 * @a: List of arguments to be printed.
 * @kb: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *a, va_list kb)
{
	int f = *a + 1;
	int precision = -1;

	if (format[f] != '.')
		return (precision);
	precision = 0;
	for (a += 1; format[f] != '\0'; f++)
	{
		if (is_digit(format[f]))
		{
			precision *= 10;
			precision += format[f] - '0';
		}
		else if (format[f] == '*')
		{
			f++;
			precision = va_arg(kb, int);
			break;
		}
		else
			break;
	}
	*a = f - 1;
	return (precision);
}
