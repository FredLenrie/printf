#include "main.h"

/**
* buffer_cpy - Copies the given character over to the buffer
* @formatter: Character to copy over
* @buffer: Buffer being copied to
* @buff_lenptr: Pointer to the length of the buffer, the number of
* characters in the buffer
* @buff_indptr: Pointer to the position in the buffer
* Return: Number of characters copied to buffer
*/

int buffer_cpy(char formatter, char buffer[],
		     int *buff_lenptr, int *buff_indptr)
{
	int print_char;

	print_char = 0;
	buffer[*buff_indptr] = formatter;
	*buff_indptr += 1;
	*buff_lenptr += 1;
	if (*buff_lenptr == 1024)
	{
		print_buffer(buffer, buff_lenptr, buff_indptr);
	}
	print_char++;
	return (print_char);
}

/**
* check_conversion - Checks formatter character to see if
* it's a conversion specifier
* @formatter: The format character being checked
* @conversions: Struct holding conversion specifiers & function pointers to
* @appropriate functions for corresponding conversion specifier
* @buffer: Buffer needed to copy to when calling function
* @buff_lenptr: Pointer to the length of the buffer
* @buff_indptr: Pointer to the position within the buffer
* @print_this: va_list holding all given arguments to _printf function
* Return: Return the number of characters copied to buffer if a
* function is called, 0 if no function is called
*/

int check_conversion(char formatter, char_funcs_t conversions[], char buffer[],
		     int *buff_lenptr, int *buff_indptr, va_list print_this)
{
	int j, print_char;

	print_char = 0;
	for (j = 0; j < 13; j++)
	{
		if (formatter == *conversions[j].c)
		{
			print_char += conversions[j].f(print_this, buffer, buff_lenptr,
						  buff_indptr);
			return (print_char);
		}
	}
	return (0);
}

/**
* formatPrinter - finds the formatters function and prints its arguement
* @format: The format character being checked
* @conversions: Struct holding conversion specifiers & function pointers to
* appropriate functions for corresponding conversion specifier
* @buffer: Buffer needed to copy to when calling function
* @buff_lenptr: Pointer to the length of the buffer
* @buff_indptr: Pointer to the position within the buffer
* @print_this: va_list holding all given arguments to _printf function
* Return: Return the number of characters copied to buffer if a
* function is called, 0 if no function is called
*/

int formatPrinter(const char *format, va_list print_this, char buffer[],
		  int *buff_lenptr, int *buff_indptr, char_funcs_t conversions[])
{
	int i, print_char, print;

	print_char = 0;
	for (i = 0; format[i] != '\0' && format != NULL; i++)
	{
		if (format[i] == '%')
		{
			i++;
			print = check_conversion(format[i], conversions,
						 buffer, buff_lenptr, buff_indptr,
						 print_this);
			if (print == 0)
				print_char += buffer_cpy(format[i], buffer,
							buff_lenptr, buff_indptr);
			print_char += print;
		}
		else
		{
			print_char += buffer_cpy(format[i], buffer, buff_lenptr,
						buff_indptr);
		}
	}
	return (print_char);
}

/**
 * _printf - A function that produces formatted output
 * @format: Format specifier.
 * Return: Printed characters excluding the null byte
 */

int _printf(const char *format, ...)
{
	va_list args_list;
	char buffer[1024];
	int print_char, buff_len, buff_ind, *buff_lenptr, *buff_indptr;
	char_funcs_t conversions[] = {{"c", print_c},
				      {"s", print_s},
				      {"i", print_int},
				      {"d", print_int},
				      {"u", print_u},
				      {"o", print_oct},
				      {"x", print_hex},
				      {"X", print_heX},
				      {"b", print_bin},
				      {"S", print_S},
				      {"r", print_rev},
				      {"R", print_rot13},
				      {"p", print_p},
	};

	init_buffer(buffer);
	print_char = buff_ind = 0;
	buff_len = 1;
	buff_lenptr = &buff_len;
	buff_indptr = &buff_ind;

	va_start(args_list, format);
	if (format == NULL || args_list == NULL)
		return (print_char);
	print_char = formatPrinter(format, args_list, buffer,
			      buff_lenptr, buff_indptr, conversions);
	print_buffer(buffer, buff_lenptr, buff_indptr);
	va_end(args_list);
	return (print_char);
}
