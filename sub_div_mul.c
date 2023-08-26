#include "monty.h"

/**
 * sub - subtracts the top element in a stack_t stack from the second element,
 * pops the top element, and replaces the new top element
 * with the result calculated
 *
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * divide - divides the second element in a stack_t stack by the top element,
 * pops the top element, and replaces the new top element
 * with the result calculated
 *
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * mul - multiplies the top two element in a stack_t stack,
 * pops the top element, and replaces the new top element
 * with the result calculated
 *
 * @stack: a double pointer to the top element of the stack
 * @line_number: the line number of the calling command in the monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
