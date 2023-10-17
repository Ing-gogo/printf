#include "main.h"

/**
 * is_printable - checks if a char is printable
 * @z: Character evaluation
 * Return: 1 if z is printable, 0 otherwise
 */

int is_printable(char z)
{
	if (z >= 32 && z < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of characters.
 * @a: Index at which to start appending.
 * @ascii_code:code of ASSCI.
 * Return: 3 all the time
 */

int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[a++] = '\\';
	buffer[a++] = 'x';
	buffer[a++] = map[ascii_code / 16];
	buffer[a] = map[ascii_code % 16];
	return (3);
}
/**
 * is_digit - checks whether a char is a digit
 * @z: Character evaluation
 * Return: 1 if z is a digit, 0 otherwise
 */
int is_digit(char z)
{
	if (z >= '0' && z <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - change a number to the specified size
 * @nbr: Number to be changed.
 * @size: Number indicating the type to be changed.
 * Return: Changed value of nbr
 */

long int convert_size_number(long int nbr, int size)
{
	if (size == S_LONG)
	{
		return (nbr);
	}
	else if (size == S_SHORT)
	{
		return ((short)nbr);
	}
	return ((int)nbr);
}

/**
 * convert_size_unsgnd - Change a number to a specified size
 * @nbr: Number to be changed
 * @size: Number showing the type to be changed
 * Return: Changed value of nbr
 */

long int convert_size_unsgnd(unsigned long int nbr, int size)
{
	if (size == S_LONG)
		return (nbr);
	else if (size == S_SHORT)
		return ((unsigned short)nbr);
	return ((unsigned int)nbr);
}
