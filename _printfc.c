#include "main.h"

void print_buffer(char buffer[], int buff_c);

/**
 * _print - function of print
 * @format: formatted string
 * Return: characters printed
 */
int _print(const char *format, ...)
{
	int a, print = 0, chars = 0;
	int flags, width, precison, size, buff_c = 0;
	va_list ig;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ig, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_c++] = format[a];
			if (buff_c == BUFF_SIZE)
				print_buffer(buffer, &buff_c);
			/*write(1, &format[a], 1); */
			chars++;
		}
		else
		{
			print_buffer(buffer, &buff_c);
			flags = get_flags(format, &a);
			width = get_width(format, &a, ig);
			precision = get_precision(format, &a, ig);
			size = get_size(format, &a);
			++a;
			print = handle_print(format, &a, ig, buffer,
					flags, width, precision, size);
			if (print == -1)
				return (-1);
			chars = chars + print;
		}
	}
	print_buffer(buffer, &buff_c);
	va_end(ig);

	return (chars);
}

/**
 * print_buffer - function printing elements of an existing buffer
 * @buffer: an array
 * @buff_c: shows length
 */
void print_buffer(char buffer[], int *buff_c)
{
	if (*buff_c > 0)
		write(1, &buffer[0], *buff_c);
	*buff_c = 0;
}
