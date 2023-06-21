#include <limits.h>
#include "main.h"
/**
 * print_last_digit - prints the last digit of a numer.
 * @n: digit to find the last place of.
 * Return: The last digit.
 */
int print_last_digit(int number)
{
int last_digit;

if (number == INT_MIN)
{
last_digit = 8;
}
else
{
if (number < 0)
	number = -number; 

	last_digit = number % 10;
}

_putchar('0' + last_digit);
return last_digit;
}
