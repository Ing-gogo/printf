#include "main.h"

/**
 * _printf - printf function
 * @format: string
 * @...: variable arguments
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	int cpr = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			cpr++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				cpr++;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				cpr++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char *);
				int slen = 0;

				while (str[slen] != '\0')
					slen++;
				write(1, str, slen);
				cpr = cpr + slen;
			}
		}
		format++;
	}
	va_end(list);
	return (cpr);
}




