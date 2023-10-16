#include "main.h"

/**
 * get_width - calculates width
 * @format: string formatted
 * @a: arguments printed
 * @kb: arguments
 * Return: width
 */
int get_width(const char *format, int *a, va_list kb)
{
	int h;
	int width = 0;

	for (h = *a + 1; format[h]; h++)
	{
		if (is_digit(format[h]))
		{
			width *= 10;
			width += format[h] - '0';
		}
		else if (format[h] == '*')
		{
			h++;
			width = va_arg(kb, int);
			break;
		}
		else
			break;
	}
	*a = h - 1;
	return (width);
}

