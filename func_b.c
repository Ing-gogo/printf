#include "main.h"

/**
 * print_pointer - Prints the value of a pointer
 * @ig: arguments list
 * @buffer: Buff array to print
 * @flags: Counts active flags
 * @width: width
 * @precision: specify the precision
 * @size: shows Size
 * Return: Number of characters.
 */

int print_pointer(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	char zz = 0, y = ' ';
	int index = BUFF_SIZE - 2, len = 2, yy = 1;
	unsigned long num_ad;
	char map[] = "0123456789abcdef";
	void *ad = va_arg(ig, void *);

	UNUSED(width);
	UNUSED(size);
	if (ad == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	num_ad = (unsigned long)ad;
	while (num_ad > 0)
	{
		buffer[index--] = map[num_ad % 16];
		num_ad /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		y = '0';
	if (flags & F_PLUS)
		zz = '+', len++;
	else if (flags & F_SPACE)
		zz = ' ', len++;
	index++;
	return (write_pointer(buffer, index, len,
				width, flags, y, zz, yy));
}

/**
 * print_non_printable - Prints non printable characters in ASCII
 * @ig: arguments lists
 * @buffer: array to handle print
 * @flags:  Counts flags
 * @width: take width
 * @precision: specifies precision
 * @size: Show specifier
 * Return: Number of characters printed
 */

int print_non_printable(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = 0, set = 0;
	char *str = va_arg(ig, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + set] = str[a];
		else
			set += append_hexa_code(str[a], buffer, a + set);
		a++;
	}
	buffer[a + set] = '\0';
	return (write(1, buffer, a + set));
}

/**
 * print_reverse - Prints string in reverse
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  Counts active flags
 * @width: take width
 * @precision: specifies precision
 * @size: Shows size
 * Return: number of characters printed
 */

int print_reverse(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int a, x = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(ig, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;
	for (a = a - 1; a >= 0; a--)
	{
		char i = str[a];

		write(1, &i, 1);
		x++;
	}
	return (x);
}

/**
 * print_rot13string - Print a string in rot13.
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  countes active flags
 * @width: takes width
 * @precision: specifies precision
 * @size: shows Size
 * Return: Numbers of characterss printed
 */

int print_rot13string(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	char p;
	char *str;
	unsigned int a, e;
	int x = 0;
	char start[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char end[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(ig, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (e = 0; start[e]; e++)
		{
			if (start[e] == str[a])
			{
				p = end[e];
				write(1, &p, 1);
				x++;
				break;
			}
		}
		if (!start[e])
		{
			p = str[a];
			write(1, &p, 1);
			x++;
		}
	}
	return (x);
}
