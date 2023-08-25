#include "monty.h"

/**
 * token_counter - counts the number of tokens present in array op_tokens
 * @op_tokens: the array whose tokens are to be counted
 *
 * Return: the number of tokens present
 */
int token_counter(char **op_tokens)
{
	int i = 0;

	while (op_tokens[i])
	{
		i++;
	}
	return (i);
}
