#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list_args: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list_args)
{
	int ind_i = *i + 1;
	int precision = -1;

	if (format[ind_i] != '.')
		return (precision);

	precision = 0;

	for (ind_i += 1; format[ind_i] != '\0'; ind_i++)
	{
		if (is_digit(format[ind_i]))
		{
			precision *= 10;
			precision += format[ind_i] - '0';
		}
		else if (format[ind_i] == '*')
		{
			ind_i++;
			precision = va_arg(list_args, int);
			break;
		}
		else
			break;
	}

	*i = ind_i - 1;

	return (precision);
}
