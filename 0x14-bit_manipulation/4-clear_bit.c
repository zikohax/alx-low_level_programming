#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to an unsigned long int.
 * @index: Index of the bit.
 *
 * Return: 1 if the operation was successful, -1 otherwise.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	/* Create a mask with the target bit set to 1 */
	m = 1 << index;

	/* If the target bit is already 1, XOR it to set it to 0 */
	if (*n & m)
		*n ^= m;

	return (1);
}

