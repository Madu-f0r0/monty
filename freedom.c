#include "monty.h"
#include <stdlib.h>

/**
 * set_me_free - frees lineptr and op_tokens in the main function
 * @op_tokens: array of tokens from lineptr tokenizing
 * @lineptr: variable containing the line read from the monty bytecde file
 */
void set_me_free(char **op_tokens)
{
	int i;

	if (op_tokens)
	{
		for (i = 0; op_tokens[i]; i++)
		{
			free(op_tokens[i]);
		}

		free(op_tokens);
	}
}
