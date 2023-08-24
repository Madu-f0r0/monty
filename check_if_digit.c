#include "monty.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_if_digit - checks if a string contains only digit characters
 * @num: the string to be accessed
 *
 * Return: 0 if the string contains only digits; 1 if not
 */
int check_if_digit(char *num)
{
	int i;
	
	for (i = 0; num[i]; i++)
	{
		if (isdigit(num[i]) == 0)
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
