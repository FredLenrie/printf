#include "main.h"

/**
 * print_c - Copy a character into the buffer
 * & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buff_len: The number of characters in buffer
 * @buff_ind: Current index of buffer
 * Return: Returns number of characters copied to buffer
 */

int print_c(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	if (*buff_len < 1024)
	{
		buffer[*buff_ind] = va_arg(args, int);
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
	}
	else
	{
		print_buffer(buffer, buff_len, buff_ind);
		buffer[*buff_ind] = va_arg(args, int);
		*buff_ind += 1;
		*buff_len += 1;
	}
	return (1);
}

/**
 * print_s - Copy a string into the buffer & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buff_len: The number of characters in buffer
 * @buff_ind: Current index of buffer
 * Return: Returns number of characters copied to buffer
 */

int print_s(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	char *str;
	int i, print_char;

	i = print_char = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		buffer[*buff_ind] = str[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		i++;
		print_char++;
	}
	return (print_char);
}

/**
 * print_int - Call the function to copy a number to the buffer
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buff_len: The number of characters in buffer
 * @buff_ind: Current index of buffer
 * Return: Returns number of characters copied to buffer
 */

int print_int(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int print_char;
	int n;

	n = va_arg(args, int);
	print_char = print_num(n, buffer, buff_len, buff_ind);
	return (print_char);
}


/**
 * print_u - prints the unsigned int
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: number of characters written to buffer
 */

int print_u(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	unsigned int c;
	int print_char;

	c = va_arg(args, unsigned int);
	print_char = print_Unum(c, buffer, buff_len, buff_ind);
	return (print_char);
}
