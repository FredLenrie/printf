#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list_args: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list_args)
{
	int ind_i;
	int width = 0;

	for (ind_i = *i + 1; format[ind_i] != '\0'; ind_i++)
	{
		if (is_digit(format[ind_i]))
		{
			width *= 10;
			width += format[ind_i] - '0';
		}
		else if (format[ind_i] == '*')
		{
			ind_i++;
			width = va_arg(list_args, int);
			break;
		}
		else
			break;
	}

	*i = ind_i - 1;

	return (width);
}
