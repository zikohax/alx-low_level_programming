#include <stdio.h>


/**
  * main - Prints 3 combination of numbers
  *
  * Return: Always (Success)
  */
int main(void) 
{
int i, j;
for (i = 0; i < 100; i++) 
{
for (j = i; j < 100; j++) 
{
int first_digit_i = i / 10;
int second_digit_i = i % 10;
int first_digit_j = j / 10;
int second_digit_j = j % 10;
putchar(first_digit_i + '0');
putchar(second_digit_i + '0');
putchar(' ');
putchar(first_digit_j + '0');
putchar(second_digit_j + '0');
if (i != 99 || j != 99) 
{
putchar(',');
putchar(' ');
}
}
}
return 0;
}

