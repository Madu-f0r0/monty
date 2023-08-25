#include "monty.h"

/**
 * set_me_free - frees lineptr and op_tokens in the main function
 * @op_tokens: array of tokens from lineptr tokenizing
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

/**
 * free_stack - frees a stack_t stack
 * @stack: a pointer to the top location of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack)
	{
		while (stack)
		{
			temp = stack;
			stack = stack->next;
			free(temp);
		}
	}
}
