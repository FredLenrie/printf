#include "main.h"

/**
 * print_buffer - Print out the buffer of all
 * characters to print
 * @buffer: The buffer with the string needed to print
 * @buff_len: Pointer to the length of buffer
 * @buff_ind: Pointer to the postion inside buffer
 */

void print_buffer(char buffer[], int *buff_len, int *buff_ind)
{
	write(1, buffer, *buff_len - 1);
	*buff_ind = 0;
	*buff_len = 1;
}
