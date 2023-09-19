#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
