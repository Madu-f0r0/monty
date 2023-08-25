#include "monty.h"
#include <string.h>

/**
 * op_tokenizer - tokenizes the input string
 * @lineptr: a pointer to the input string in the shell wrapper function
 *
 * Return: the array containing the tokens created
 */

char **op_tokenizer(char *lineptr)
{
	char **op_tokens, *token, *lineptrCpy = NULL, *delim = " \n";
	int i = 0, tokenCount = 0;

	if (lineptr == NULL)
	{
		return (NULL);
	}
	/* Duplicate the input string */
	lineptrCpy = _strdup(lineptr);

	/* Count the number of tokens */
	token = strtok(lineptr, delim);

	while (token)
	{
		tokenCount++;
		token = strtok(NULL, delim);
	}

	/* Allocate memory for char pointers in op_tokens */
	op_tokens = malloc(sizeof(char *) * (tokenCount + 1));
	if (op_tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	/* Parse the input string */
	token = strtok(lineptrCpy, delim);

	while (token)
	{
		op_tokens[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	op_tokens[i] = NULL;
	free(lineptrCpy);
	return (op_tokens);
}
