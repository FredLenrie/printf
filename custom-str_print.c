#include "main.h"

/**
 * print_rev - prints the reversed string
 * @args: string to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */
int print_rev(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	char *str;
	int i, num;

	i = num = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
		i++;
	i--;
	for (; i >= 0; i--, num++)
	{
		buffer[*buff_ind] = str[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
	}
	return (num);
}

/**
 * print_rot13 - prints the rot13'ed string
 * @args: string to be printed
 * @buffer: space used for printing
 * @buff_len: buffer length
 * @buff_ind: current buffer index
 * Return: numbers of chars written to buffer
 */
int print_rot13(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	char *str, temp;
	int i, num;

	i = num = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
	{
		temp = str[i];
		if ((temp >= 'A' && temp <= 'M') ||
		    (temp >= 'a' && temp <= 'm'))
			temp += 13;
		else if ((temp >= 'N' && temp <= 'Z')
			 || (temp >= 'n' && temp <= 'z'))
			temp -= 13;

		buffer[*buff_ind] = temp;
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		i++, num++;
	}
	return (num);
}
/**
* print_p - prints the address of a variable
* @args: number to be printed
* @buffer: space used for printing
* @buff_len: buffer length
* @buff_ind: current buffer index
* Return: numbers of chars written to buffer
**/
int print_p(va_list args, char buffer[], int *buff_len, int *buff_ind)
{
	char *str;
	int i, num;
	size_t add;

	add = (size_t)va_arg(args, void *);
	str = size_tHex('x', add);
	if (str == NULL)
		return (0);
	i = num = 0;
	buffer[*buff_ind] = '0';
	num++;
	*buff_ind += 1;
	*buff_len += 1;
	if (*buff_len == 1024)
		print_buffer(buffer, buff_len, buff_ind);
	buffer[*buff_ind] = 'x';
	num++;
	*buff_ind += 1;
	*buff_len += 1;
	if (*buff_len == 1024)
	print_buffer(buffer, buff_len, buff_ind);
	while (str[i] != '\0')
	{
		buffer[*buff_ind] = str[i];
		*buff_ind += 1;
		*buff_len += 1;
		if (*buff_len == 1024)
			print_buffer(buffer, buff_len, buff_ind);
		i++, num++;
	}
	free(str);
	return (num);
}
