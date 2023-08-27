#include "monty.h"
#include <string.h>

/**
 * exec_opcode - executes the specified Monty opcode
 * @op_tokens: an array of valid op_codes with corresponding functions
 * @stack: a pointer to the top location of a stack_t stack
 * @line_number: the line_number of the opcode in the monty bytecode file
 */
void exec_opcode(char **op_tokens, stack_t **stack, int line_number)
{
	int tok_count;

	if (op_tokens)
	{
		/* Count the number of tokens from the line read */
		tok_count = token_counter(op_tokens);

		if (op_tokens[0])
		{
			/* Skip line if the line is a comment */
			if (op_tokens[0][0] == '#')
			{
				set_me_free(op_tokens);
				return;
			}
			/* Return error if push opcode has no valid integer argument */
			if (strcmp(op_tokens[0], "push") == 0)
			{
				if (tok_count < 2 || check_if_digit(op_tokens[1]))
				{
					set_me_free(op_tokens);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}

			/* Convert argument to int and assign to global n if arg is valid */
			if (tok_count > 1 && check_if_digit(op_tokens[1]) == 0)
			{
				n = atoi(op_tokens[1]);
			}

			/* Select the matching opcode function and execute */
			select_fxn(stack, op_tokens, line_number);
		}
		/* Free memory allocated for the op_tokens array */
		set_me_free(op_tokens);
	}
}
