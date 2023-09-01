#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The input unsigned long int.
 * @index: The index of the bit.
 *
 * Return: The value of the bit at the specified index,
 *         or -1 if the index is out of bounds.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (index >= 64)
		return (-1);

	/* Shift n to the right by index positions */
	for (i = 0; i <= 63; n >>= 1, i++)
	{
		if (index == i)
		{
			return (n & 1);
		}
	}

	return (-1);
}

