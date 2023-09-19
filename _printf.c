#include "main.h"

void print_buffer(char buffer[], int *buffpos);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, print_char = 0;
	int flags, width, precision, size, buffpos = 0;
	va_list list_args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list_args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffpos++] = format[i];
			if (buffpos == BUFF_SIZE)
				print_buffer(buffer, &buffpos);
			/* write(1, &format[i], 1);*/
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buffpos);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list_args);
			precision = get_precision(format, &i, list_args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list_args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			print_char += printed;
		}
	}

	print_buffer(buffer, &buffpos);

	va_end(list_args);

	return (print_char);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffpos: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buffpos)
{
	if (*buffpos > 0)
		write(1, &buffer[0], *buffpos);

	*buffpos = 0;
}

