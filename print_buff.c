#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list_args: List of arguments to be printed.
 * @pos: pos.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *pos, va_list list_args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hex},
		{'X', print_heX}, {'p', print_pointer}, {'S', print_nonP},
		{'r', print_rev}, {'R', print_R}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*pos] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list_args, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*pos] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*pos - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*pos);
			while (fmt[*pos] != ' ' && fmt[*pos] != '%')
				--(*pos);
			if (fmt[*pos] == ' ')
				--(*pos);
			return (1);
		}
		unknow_len += write(1, &fmt[*pos], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
