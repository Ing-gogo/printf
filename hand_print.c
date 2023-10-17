#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string
 * @kb: List of arguments to be printed.
 * @index:starting number.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *format, int *index, va_list kb, char buffer[],
		int flags, int width, int precision, int size)
{
	int a, ulen = 0, chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; format_types[a].format != '\0'; a++)
		if (format[*index] == format_types[a].format)
			return (format_types[a].func(kb, buffer, flags, width, precision, size));
	if (format_types[a].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		ulen += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			ulen += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		ulen += write(1, &format[*index], 1);
		return (ulen);
	}
	return (chars);
}
