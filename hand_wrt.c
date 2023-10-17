#include "main.h"

/**
 * handle_write_char - Printing string
 * @z: character types.
 * @buffer: array to handle print
 * @flags:  Counts active flags.
 * @width: take width.
 * @precision: specifies precision
 * @size: shows Size
 * Return: Number of characters printed.
 */

int handle_write_char(char z, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = 0;
	char y = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		y = '0';
	buffer[a++] = z;
	buffer[a] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = y;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Printing string
 * @negative: arguments list
 * @index: char types.
 * @buffer: array to handle print
 * @flags: Counts active flags
 * @width: take width.
 * @precision: specifies precision
 * @size: shows Size
 * Return: Number of characters printed.
 */

int write_number(int negative, int index, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char y = ' ', extra_c = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		y = '0';
	if (negative)
		extra_c = '-';
	else if (flags & F_PLUS)
		extra_c = '+';
	else if (flags & F_SPACE)
		extra_c = ' ';
	return (write_num(index, buffer, flags, width, precision,
				len, y, extra_c));
}
/**
 * write_num - Write number using a bufffer
 * @index: starting number
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Prec. specifier
 * @len: length
 * @y: Padding character
 * @zz: Extra character
 * Return: Number of printed characters.
 */

int write_num(int index, char buffer[],
		int flags, int width, int precision, int len, char y, char zz)
{
	int a, yy = 1;

	if (precision == 0 && index == BUFF_SIZE - 2
			&& buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = y = ' ';
	if (precision > 0 && precision < len)
		y = ' ';
	while (precision > len)
		buffer[--index] = '0', len++;
	if (zz != 0)
		len++;
	if (width > len)
	{
		for (a = 1; a < width - len + 1; a++)
			buffer[a] = y;
		buffer[a] = '\0';
		if (flags & F_MINUS && y == ' ')
		{
			if (zz)
				buffer[--index] = zz;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && y == ' ')
		{
			if (zz)
				buffer[--index] = zz;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && y == '0')
		{
			if (zz)
				buffer[--yy] = zz;
			return (write(1, &buffer[yy], a - yy) +
					write(1, &buffer[index], len - (1 - yy)));
		}
	}
	if (zz)
		buffer[--index] = zz;
	return (write(1, &buffer[index], len));
}
/**
 * write_unsgnd - Writes an unsigned nbr
 * @negative: Number that indicate if the num is negative
 * @index: starting number
 * @buffer: Array of characters
 * @flags: Flags
 * @width: Width
 * @precision: specifies precision
 * @size: shows Size
 * Return: Number of written characters.
 */

int write_unsgnd(int negative, int index,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1, a = 0;
	char y = ' ';

	UNUSED(negative);
	UNUSED(size);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (precision > 0 && precision < len)
		y = ' ';
	while (precision > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		y = '0';
	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = y;
		buffer[a] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], a));
		}
		else
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[index], len));
		}
	}
	return (write(1, &buffer[index], len));
}

/**
 * write_pointer - Write the address of a memory
 * @buffer: Arrays of characters
 * @index: starting number
 * @len: Length
 * @width: Width
 * @flags: Flags
 * @y: Character that represent a padding
 * @zz: Character that represent extra char
 * @yy: Indexing the starting point of padding
 * Return: Number of written characters.
 */

int write_pointer(char buffer[], int index, int len,
		int width, int flags, char y, char zz, int yy)
{
	int a;

	if (width > len)
	{
		for (a = 3; a < width - len + 3; a++)
			buffer[a] = y;
		buffer[a] = '\0';
		if (flags & F_MINUS && y == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (zz)
				buffer[--index] = zz;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (zz)
				buffer[--index] = zz;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && y == '0')
		{
			if (zz)
				buffer[--yy] = zz;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[yy], a - yy) +
					write(1, &buffer[index], len - (1 - yy) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (zz)
		buffer[--index] = zz;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
