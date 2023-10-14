#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* SIZES */
#define S_LONG2
#define S_SHORT1
/**
 * struct format - struct operation
 * @format: string formatted
 * @func: function used
 */
struct format
{
	char format;

	int(*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t - operation of struct
 * @format: string formatted
 * @format_t: function
 */
typedef struct format format_t;


int _printf(const char *format, ...);
int _putchar(char c);
int handle_print(const char *format, int *a, va_list kb, char buffer[],
		int flags, int width, int precision, int size);

/** FUNCTIONS **/

/* functions printing characters and strings */
int print_char(va_list ig, char buffer[], int flags, int width,
		int precision, int size);
int print_string(va_list ig, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list ig, char buffer[], int flags, int width,
		int precision, int size);

/** functions printing numbers **/
int print_int(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list ig, char buffer[], int flags, int width,
		int precision, int size);
int print_unsigned(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list ig, char buffer[],
		int flags, int width, int precison, int size);
int print_hexa(va_list ig, char map[],
		char buffer[], int flags, int width, int precison, int size);

/** function to print address to memory **/
int print_pointer(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
/** ffunctions printing non printable characters **/
int print_non_printable(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
/** functions printing strings in reverse **/
int print_reverse(va_list ig, char buffer[],
		int flags, int width, int precision, int size);
/** functions handling specifiers **/
int get_flags(const char *format, int *a);
int get_width(const char *format, int *a, va_list kb);
int get_precison(const char *format, int *a, va_list kb);
int get_size(const char *format, int *a);

/** function printing string in rot 13 */
int print_rot13string(va_list ig, char buffer[],
		int flags, int width, int precison, int size);
/** width handler **/
int handle_write_char(char z, char buffer[],
		int flags, int width, init precision, int size);
int write_number(int positive, int index, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags,
		int width, int precision, int len, char y, char zz);
int write_pointer(char buffer[], int index, int len, int width,
		int flags, char y, char zz, int yy);
int write_unsgnd(int negative, int index, char buffer[],
		int flags, int width, int precision, int size);


/** FLAGS **/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/** UTILITIES **/
int append_hexa_code(char, char[], int);
int is_priintable(char);
int is_digit(char);
long int conver_size_number(long int nbr, int size);
long int convert_size_unsgnd(unsigned long int nbr, int size);

#endif
