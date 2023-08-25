#include "monty.h"

/**
 * add - adds the top two elements in a stack_t stack,
 * pops the top element, and replaces the new top element
 * with the sum calculated
 *
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}

/**
 * swap - swaps the top two elements in a stack_t stack,
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->prev = *stack;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

/**
 * pint - prints the top element of a stack_t stack
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
