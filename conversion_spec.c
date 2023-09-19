#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_oct - Print octal conversion of a decimal number
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */
int print_oct(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int num, i;
	unsigned int n;
	char *oct;

	n = va_arg(args, unsigned int);
	oct = octConverter(n);
	if (oct == NULL)
		return (0);
	i = num = 0;
	while (oct[i] != '\0')
	{
		buffer[*buff_ind] = oct[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
		{
			print_buffer(buffer, buff_len, buff_ind);
		}
		i++, num++;
	}
	free(oct);
	return (num);
}

/**
 * print_hex - prints the hexadecimal conversion of a decimal number, lowercase
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */

int print_hex(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int num, i;
	unsigned int n;
	char *hex;

	n = va_arg(args, unsigned int);
	hex = hexConverter('x', n);
	if (hex == NULL)
		return (0);
	i = num = 0;
	while (hex[i] != '\0')
	{
		buffer[*buff_ind] = hex[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
		{
			print_buffer(buffer, buff_len, buff_ind);
		}
		i++, num++;
	}
	free(hex);
	return (num);
}

/**
 * print_heX - prints the hexadecimal conversion of a decimal number, uppercase
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */

int print_heX(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int num, i;
	unsigned int n;
	char *heX;

	n = va_arg(args, unsigned int);
	heX = hexConverter('X', n);
	if (heX == NULL)
		return (0);
	i = num = 0;
	while (heX[i] != '\0')
	{
		buffer[*buff_ind] = heX[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
		{
			print_buffer(buffer, buff_len, buff_ind);
		}
		i++, num++;
	}
	free(heX);
	return (num);
}

/**
 * print_bin - prints the binary conversion of a decimal number
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */

int print_bin(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int num, i;
	unsigned int n;
	char *bin;

	n = va_arg(args, unsigned int);
	bin = binConverter(n);
	if (bin == NULL)
		return (0);
	i = num = 0;
	while (bin[i] != '\0')
	{
		buffer[*buff_ind] = bin[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
		{
			print_buffer(buffer, buff_len, buff_ind);
		}
		i++, num++;
	}
	free(bin);
	return (num);
}

/**
 * print_S - prints printable chars, else their hex value in uppercase
 * @args: number to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */

int print_S(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	int num, i, k, j;
	char *str, *inHex;

	str = va_arg(args, char *);
	if (str == NULL || *str == '\0')
	{
		buffer[*buff_ind] = '\\';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		buffer[*buff_ind] = 'x';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		buffer[*buff_ind] = '0';
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		return (4);
	}
	i = num = 0;
	while (str[i] != '\0')
	{
		j = str[i];
		if ((j > 0 && j < 32) || j >= 127)
		{
			buffer[*buff_ind] = '\\';
			*buff_ind += 1;
			*buff_len += 1;
			if (*buff_len == 1024)
				print_buffer(buffer, buff_len, buff_ind);
			buffer[*buff_ind] = 'x';
			*buff_ind += 1;
			*buff_len += 1;
			if (*buff_len == 1024)
				print_buffer(buffer, buff_len, buff_ind);
			if (j > 0 && j <= 15)
			{
				buffer[*buff_ind] = '0';
				*buff_ind += 1;
				*buff_len += 1;
				if (*buff_len == 1024)
					print_buffer(buffer, buff_len, buff_ind);
				if (j > 0 && j <= 9)
					buffer[*buff_ind] = str[i] + '0';
				else if (j > 9 && j <= 15)
					buffer[*buff_ind] = str[i] + 55;
				*buff_ind += 1;
				*buff_len += 1;
				if (*buff_len == 1024)
					print_buffer(buffer, buff_len, buff_ind);
			}
			else if ((j > 16 && j < 32) || j >= 127)
			{
				inHex = hexConverter('X', j);
				if (inHex == NULL)
					return (0);
				k = 0;
				while (inHex[k] != '\0')
				{
					buffer[*buff_ind] = inHex[k];
					*buff_ind += 1;
					*buff_len += 1;
					if (*buff_len == 1024)
						print_buffer(buffer, buff_len,
							     buff_ind);
					k++;
				}
				free(inHex);
			}
			num += 4;
		}
		else
		{
			buffer[*buff_ind] = str[i];
			*buff_ind += 1;
			*buff_len += 1;
			if (*buff_len == 1024)
				print_buffer(buffer, buff_len, buff_ind);
			num++;
		}
		i++;
	}
	return (num);
}
