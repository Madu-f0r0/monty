#include "monty.h"
#include <string.h>

/**
 * main - wrapper for monty interpreter program
 * @argc: the number of command line arguments including the program name
 * @argv: a null-terminated array of CLAs including the program name
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	char *str = NULL, **op_tokens;
	FILE *monty_byte;
	int tok_count, line_number = 0;
	stack_t *stack = NULL;

	confirm_arg_count(argc);

	monty_byte = open_file(argv[1]);

	do {
		if (str)
		{
			free(str);
			str = NULL;
		}
		str = read_from_stream(monty_byte);
		line_number++;

		op_tokens = op_tokenizer(str);
		if (op_tokens)
		{
			tok_count = token_counter(op_tokens);

			if (op_tokens[0])
			{
				if (tok_count > 1 && check_if_digit(op_tokens[1]) == 0)
					n = atoi(op_tokens[1]);

				select_fxn(&stack, op_tokens, line_number);
			}
			set_me_free(op_tokens);
		}
	} while (str);

	free_stack(stack);
	fclose(monty_byte);
	return (0);
}
