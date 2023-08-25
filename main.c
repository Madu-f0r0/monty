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
	int line_number = 0;
	stack_t *stack = NULL;

	/* Confirm that the number of CL arguments is 1*/
	confirm_arg_count(argc);

	/* Open the filename passed as argument in read mode */
	monty_byte = open_file(argv[1]);

	/* Iterate till all the content of the opened file has been read */
	do {
		if (str)
		{
			free(str);
			str = NULL;
		}

		/* Read line by line from the opened file */ 
		str = read_from_stream(monty_byte);
		line_number++;

		/* Tokenize the line read from the opened file */
		op_tokens = op_tokenizer(str);

		/* Execute a valid opdoce on the line read from the file */
		exec_opcode(op_tokens, &stack, line_number);
	} while (str);

	/* After interpreting, free the memory used by the stack */
	free_stack(stack);

	/* Close the opened file stream */
	fclose(monty_byte);
	return (0);
}
