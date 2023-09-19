#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @pos: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int pos, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - pos - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(pos, buffer, flags, width, precision,
		len, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @pos: posex at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @len: Number len
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int pos, char buffer[],
	int flags, int width, int prec,
	int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0')
		buffer[pos] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buffer[--pos] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--pos] = extra_c;
			return (write(1, &buffer[pos], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--pos] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[pos], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[pos], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--pos] = extra_c;
	return (write(1, &buffer[pos], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number posicating if the num is negative
 * @pos: posex at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int pos,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - pos - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && pos == BUFF_SIZE - 2 && buffer[pos] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < len)
		padd = ' ';

	while (precision > len)
	{
		buffer[--pos] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[pos], len) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[pos], len));
		}
	}

	return (write(1, &buffer[pos], len));
}

/**
 * write_ptr - Write a memory address
 * @buffer: Arrays of chars
 * @pos: posex at which the number starts in the buffer
 * @len: len of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: posex at which padding should start
 *
 * Return: Number of written chars.
 */
int write_ptr(char buffer[], int pos, int len,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--pos] = 'x';
			buffer[--pos] = '0';
			if (extra_c)
				buffer[--pos] = extra_c;
			return (write(1, &buffer[pos], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--pos] = 'x';
			buffer[--pos] = '0';
			if (extra_c)
				buffer[--pos] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[pos], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[pos], len - (1 - padd_start) - 2));
		}
	}
	buffer[--pos] = 'x';
	buffer[--pos] = '0';
	if (extra_c)
		buffer[--pos] = extra_c;
	return (write(1, &buffer[pos], BUFF_SIZE - pos - 1));
}
