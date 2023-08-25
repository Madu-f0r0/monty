#include "monty.h"

/**
 * read_from_stream - reads a line from a file stream
 * @stream: the file stream to read from
 *
 * Return: str
 */
char *read_from_stream(FILE *stream)
{
	char *str, *str2;

	str = malloc(sizeof(char) * 120);
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str2 = fgets(str, 120, stream);
	if (str2 == NULL)
	{
		free(str);
	}

	return (str2);
}
