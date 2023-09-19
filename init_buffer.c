#include "main.h"

/**
 * init_buffer - Fill the buffer with null chars
 * @buffer: The buffer to be initialized
 */

void init_buffer(char buffer[])
{
	int i;

	i = 0;
	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}
