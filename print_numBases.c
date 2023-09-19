#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * octConverter - represents a decimal number greater than 7 to octal
 * @n: number to be converted
 * Return: pointer to a char
 */

char *octConverter(unsigned int n)
{
	char *nums,  num[1024];
	int i, j, remn;

	i = 0;
	while (n != 0)
	{
		remn = (n % 8) + '0';
		num[i] = remn;
		n /= 8;
		i++;
	}
	num[i] = '\0';

	nums = malloc(sizeof(char) * i);
	if (nums == NULL)
		return (NULL);
	i--;
	j = 0;
	while (i >= 0)
	{
		nums[j] = num[i];
		j++, i--;
	}
	nums[j] = '\0';
	return (nums);
}

/**
 * hexConverter - represents decimal number greater than 9 to hex
 * @type: char for uppercase or lowercase letter conversion
 * @n: number to be converted
 * Return: pointer to a char
 */

char *hexConverter(char type, unsigned int n)
{
	char *hexN, hexn[1024];
	int i, j, remn;

	i = 0;
	while (n != 0)
	{
		remn = n % 16;
		if (remn > 9)
		{
			if (type == 'X')
				hexn[i] = remn + 55;
			else
				hexn[i] = remn + 87;
		}
		else
			hexn[i] = remn + 48;
		n /= 16;
		i++;
	}
	hexn[i] = '\0';

	hexN = malloc(sizeof(char) * i);
	if (hexN == NULL)
		return (NULL);
	i--;
	for (j = 0; i >= 0; j++, i--)
		hexN[j] = hexn[i];
	hexN[j] = '\0';
	return (hexN);
}

/**
 * size_tHex - represents decimal number greater than 9 to hex
 * @type: char for uppercase or lowercase letter conversion
 * @n: based on size of a number it gets converetd in hex
 * Return: pointer to a char
 */

char *size_tHex(char type, size_t n)
{
	char *hexN, hexn[1024];
	int i, j;
	long remn;

	i = 0;
	while (n != 0)
	{
		remn = n % 16;
		if (remn > 9)
		{
			if (type == 'X')
				hexn[i] = remn + 55;
			else
				hexn[i] = remn + 87;
		}
		else
			hexn[i] = remn + 48;
		n /= 16;
		i++;
	}
	hexn[i] = '\0';

	hexN = malloc(sizeof(char) * i);
	if (hexN == NULL)
		return (NULL);
	i--;
	for (j = 0; i >= 0; j++, i--)
		hexN[j] = hexn[i];
	hexN[j] = '\0';
	return (hexN);
}

/**
 * unsignedIntConverter - represents a signed number into unsigned
 * @n: number to be converted
 * Return: an unsigned int
 */

unsigned int unsignedIntConverter(int n)
{
	unsigned int c;

	c = UINT_MAX + 1 + n;
	return (c);
}
