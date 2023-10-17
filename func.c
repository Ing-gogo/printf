#include "main.h"


/**
 * print_char - function that prints characters
 * @ig: arguments
 * @buffer: arrray
 * @flags: counts flags
 * @width: width
 * @size: shows size
 * @precision: precises
 * Return: number of printed characters
 */
int print_char(va_list ig, char buffer[], int flags, int width,
		int precision, int size)
{
	char z = va_arg(ig, int);

	return (handle_write_char(z, buffer, flags, width, precision,
					size));
}

/**
 * print_string - printing a string
 * @ig: arguments
 * @buffer: array printed
 * @width: width
 * @flags: counts flags
 * @precision: precises
 * @size: shows size
 * Return: number of printed characters
 */
int print_string(va_list ig, char buffer[], int flags,
		int precision, int width, int size)
{
	int len = 0, a;
	char *str = va_arg(ig, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (a = width - len; a > 0; a--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, "", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}


/**
 * print_percent - printing a percent sign
 * @ig: arguments
 * @buffer: array
 * @flags: counts flags
 * @width: width
 * @precision: precises
 * @size: shows size
 * Return: printed characters
 */
int print_percent(va_list ig, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(ig);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	return (write(1, "%%", 1));
}

/**
 * print_int - prints integers
 * @ig: arguments
 * @buffer: array
 * @flags: counts flags
 * @width: width
 * @size: shows size
 * @precision: precises
 * Return: number of printed characters
 */
int print_int(va_list ig, char  buffer[], int flags,
		int width, int size, int precision)
{
	int a = BUFF_SIZE - 2;
	int negative = 0;
	long int b = va_arg(ig, long int);
	unsigned long int nbr;

	b = convert_size_number(b, size);

	if (b == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nbr = (unsigned long int)b;

	if (b < 0)
	{
		nbr = (unsigned long int)((-1) * b);
		negative = 1;
	}
	while (nbr > 0)
	{
		buffer[a--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	a++;
	return (write_number(negative, a, buffer, flags, width,
			       precision, size));
}

/**
 * print_binary - printing unsigned number
 * @ig: arguments
 * @buffer: array printed
 * @flags: counts flags
 * @width: width
 * @precision: precises
 * @size: shows size
 * Return: printed chharacters
 */
int print_binary(va_list ig, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int b, c, a, sum;
	unsigned int d[32];
	int x;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(ig, unsigned int);
	c = 2147483648;
	d[0] = b / c;
	for (a = 1; a < 32; a++)
	{
		c /= 2;
		d[a] = (b / c) % 2;
	}
	for (a = 0; sum = 0, x = 0, a < 32; a++)
	{
		sum += d[a];
		if (sum || a == 31)
		{
			char i = '0' + d[a];

			write(1, &i, 1);
			x++;
		}
	}
	return (x);
}



