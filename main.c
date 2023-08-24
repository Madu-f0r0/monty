#include "monty.h"
#include <string.h>

int n;

int main(int argc, char **argv)
{
	/* Variable Declarations */
	char str[1024], *fRet = NULL, **op_tokens;
	FILE *monty_byte;
	size_t size = 1024, i;
	int line_number = 0, op_code_found;
	stack_t *stack = NULL;
	instruction_t stack_fxns[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}
		, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}
	};

	/* Confirm the number of CL arguments */
	confirm_arg_count(argc);

	/* Open the Monty bytecode file */
	monty_byte = open_file(argv[1]);

	/* Read from the opened file line by line */
	do
	{
		fRet = fgets(str, size, monty_byte);
		line_number++;
		op_code_found = 0;

		op_tokens = op_tokenizer(str);
		for (i = 0; op_tokens[i]; i++)
		{
			;
		}

		if (op_tokens[0])
		{
			/* printf("OP_CODE: %s\n", op_tokens[0]); */
			if (i > 1 && check_if_digit(op_tokens[1]) == 0)
			{
				n = atoi(op_tokens[1]);
			}

			for (i = 0; i < sizeof(stack_fxns) / sizeof(stack_fxns[0]); i++)
			{
				if (strcmp(op_tokens[0], (stack_fxns[i]).opcode) == 0)
				{
					(stack_fxns[i]).f(&stack, line_number);
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
		set_me_free(op_tokens);
	} while (fRet);

	return (0);
}
