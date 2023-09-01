#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to an unsigned long int.
 * @index: Index of the bit.
 *
 * Return: 1 if the operation was successful, -1 otherwise.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	/* Create a mask with the target bit set to 1 */
	m = 1 << index;

	/* Set the bit at the specified index to 1 */
	*n = (*n | m);

	return (1);
}

