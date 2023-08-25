#include "monty.h"
#include <string.h>

/**
 * op_tokenizer - tokenizes the input string
 * @str: a pointer to the input string in the main function
 *
 * Return: the array containing the tokens created
 */

char **op_tokenizer(char *str)
{
	char **op_tokens, *token, *delim = " \n";

	if (str == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for char pointers in op_tokens */
	op_tokens = malloc(sizeof(char *) * 3);
	if (op_tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	/* Create the first token (the opcode, if valid) */
	token = strtok(str, delim);
	op_tokens[0] = _strdup(token);

	/* Create the second token (the argument to push, if valid) */
	token = strtok(NULL, delim);
	op_tokens[1] = _strdup(token);

	/* Terminate the array with a void pointer */
	op_tokens[2] = NULL;

	return (op_tokens);
}
