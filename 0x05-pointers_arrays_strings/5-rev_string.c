#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: The string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, j;
	char temp;

	/* Finding the length of the string */
	for (j = 0; s[j] != '\0'; j++)
		;

	/* Reversing the string using two pointers */
	for (i = 0, j = j - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

