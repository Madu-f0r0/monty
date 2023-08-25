#include "monty.h"
#include <string.h>

/**
 * select_fxn - selects one of the stack functions to be executed
 * @stack: a pointer to the top location of the stack
 * @op_tokens: an array of the tokenizrd input
 * @line_number: the line number of the op_code being executed
 */
void select_fxn(stack_t **stack, char **op_tokens, int line_number)
{
	unsigned int i, op_code_found = 0;
	instruction_t stack_fxns[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}
		, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}
	};

	for (i = 0; i < sizeof(stack_fxns) / sizeof(stack_fxns[0]); i++)
	{
		if (strcmp(op_tokens[0], (stack_fxns[i]).opcode) == 0)
		{
			(stack_fxns[i]).f(stack, line_number);
			op_code_found = 1;
			break;
		}
	}
	if (op_code_found == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n"
				, line_number, op_tokens[0]);
		exit(EXIT_FAILURE);
	}
}
