#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  Counts active flags
 * @width: takes width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of charscters printed.
 */

int print_unsigned(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(ig, unsigned long int);

	nbr = convert_size_unsgnd(nbr, size);
	if (nbr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[a--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned num in octal not.
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */

int print_octal(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(ig, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);
	nbr = convert_size_unsgnd(nbr, size);
	if (nbr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[a--] = (nbr % 8) + '0';
		nbr /= 8;
	}
	if (flags & F_HASH && init_nbr != 0)
		buffer[a--] = '0';
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned nbr in hex. notation
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  Counts active flags
 * @width: take width
 * @precision: specifies precision
 * @size: Show size
 * Return: Number of characters printed
 */

int print_hexadecimal(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(ig, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned nbr in upper hex. not.
 * @ig: arguments list
 * @buffer: array to handle print
 * @flags:  Counts active flags
 * @width: take width
 * @precision: specifies precision
 * @size: show Size
 * Return: Number of characters printed
 */

int print_hexa_upper(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(ig, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hex. nbr in lower or upper
 * @ig: arguments list
 * @map: values to map numbers
 * @buffer: array to handle print
 * @flags:  Counts active flags
 * @flag_c: Counts active flags
 * @width: take width
 * @precision: specifies precision
 * @size: shows Size
 * Return: Number of characters printed
 */

int print_hexa(va_list ig, char map[], char buffer[],
		int flags, char flag_c, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(ig, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);
	nbr = convert_size_unsgnd(nbr, size);
	if (nbr == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (nbr > 0)
	{
		buffer[a--] = map[nbr % 16];
		nbr /= 16;
	}
	if (flags & F_HASH && init_nbr != 0)
	{
		buffer[a--] = flag_c;
		buffer[a--] = '0';
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
