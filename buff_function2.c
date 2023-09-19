#include "holberton.h"

/**
 * print_num - Copy the given int one digit at a time to the buffer to print
 * @n: The integer to print
 * @buffer: Buffer beign copied to to print
 * @buff_len: Length of characters in buffer
 * @buff_ind: Position in the buffer
 * Return: Number of characters printed
 */

int print_num(int n, char buffer[], int *buff_len, int *buff_ind)
{
	int chars;
	int sign_print;

	chars = sign_print = 0;
	if (n == 0)
	{
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		return (1);
	}
	else if (n > 0)
		n *= -1;
	else
	{
		buffer[*buff_ind] = '-';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		sign_print = 1;
	}
	if ((n / 10) != 0)
	{
		chars = print_num(((n / 10) * -1), buffer, buff_len, buff_ind);
	}
	buffer[*buff_ind] = (n % 10) * -1 + '0';
	*buff_ind += 1;
	*buff_len += 1;
	if (*buff_len == 1024)
		print_buffer(buffer, buff_len, buff_ind);
	if (sign_print > 0)
		chars += sign_print;
	chars++;
	return (chars);
}

/**
 * print_Unum - Copy the given unsigned integer to the buffer to print
 * @n: Integer to copy
 * @buffer: Buffer to copy to
 * @buff_len: Current length of buffer
 * @buff_ind: Current position the buffer
 * Return: Number of characters printed
 */

int print_Unum(unsigned int n, char buffer[], int *buff_len, int *buff_ind)
{
	int num;

	num = 0;
	if (n == 0)
	{
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		return (1);
	}
	if ((n / 10) != 0)
		num = print_Unum((n / 10), buffer, buff_len, buff_ind);
	buffer[*buff_ind] = (n % 10) + '0';
	*buff_ind += 1;
	*buff_len += 1;
	if (*buff_len == 1024)
		print_buffer(buffer, buff_len, buff_ind);
	num++;
	return (num);
}
