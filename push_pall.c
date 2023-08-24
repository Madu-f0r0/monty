#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - adds an element to a stack
 * @stack: a double pointer to the top of a stack_t stack
 * @line_number: the line number of the command from the monty bytecode file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_top;

	if (stack)
	{
		new_top = malloc(sizeof(stack_t));
		if (new_top == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		new_top->n = n;

		if (*stack == NULL)
		{
			new_top->prev = NULL;
			new_top->next = NULL;
			*stack = new_top;
		}

		else
		{
			new_top->prev = NULL;
			new_top->next = *stack;
			(*stack)->prev = new_top;
			*stack = new_top;
		}
	}
}

/**
 * pall - prints all the elements of a stack
 * @stack: a double pointer to the top of the stack
 * @line_number: the line number of the command from the monty bytecode file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node_ptr;

	if (stack && *stack)
	{
		node_ptr = *stack;

		while (node_ptr)
		{
			printf("%d\n", node_ptr->n);
			node_ptr = node_ptr->next;
		}
	}
}
