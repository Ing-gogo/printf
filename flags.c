#include "main.h"

/**
 * get_flags - counts flags
 * @format: string formatted
 * @a: parameter used
 * Return: flags
 */
int get_flags(const char *format, int *a)
{
	/* - + 0 # '' */
	/* 1 2 4 8 16 */

	int e, f;
	int flags = 0;
	const char g[] = {'-', '+', '0', '#', '', '\0'};
	const int h[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
		F_SPACE, 0};

	for (f = *a + 1; format[f] != '\0'; f++)
	{
		for (e = 0; g[e] != '\0'; e++)
			if (format[f] == g[e])
			{
				flags |= h[e];
				break;
			}
		if (g[e] == 0)
			break;
	}
	*a = f - 1;
	return (flags);
}
