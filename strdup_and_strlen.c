#include "monty.h"

/**
 * _strdup - duplicates a string with dynamically allocated memory space
 * @str: the string to be duplicated
 *
 * Return: a pointer to the duplicated string in the memory heap
 */

char *_strdup(char *str)
{
	unsigned int i, length;
	char *dupStr;

	if (str == NULL)
	{
		return (NULL);
	}

	length = _strlen(str) + 1;

	dupStr = malloc(length * sizeof(char));
	if (dupStr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < length; i++)
	{
		dupStr[i] = str[i];
	}
	return (dupStr);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
