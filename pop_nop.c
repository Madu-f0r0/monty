#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - frees the top element of the stack
 * @stack: a double pointer to the top of a stack_t stack
 * @line_number: the line numder of the command in the monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack)
	{
		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			exit(EXIT_FAILURE);
		}

		else
		{
			top = *stack;
			if ((*stack)->next)
			{
				(*stack)->next->prev = NULL;
			}
			*stack = (*stack)->next;
			free(top);
		}
	}
}

/**
 * nop - does nothing
 * @stack: a double pointer to the top of a stack_t stack
 * @line_number: the line numder of the command in the monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
