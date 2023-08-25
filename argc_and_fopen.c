#include "monty.h"

/**
 * confirm_arg_count - confirms that one CLA was passed to the program
 * @argc: a reference to the argc in the main function
 */
void confirm_arg_count(int argc)
{
	printf("argc is: %d\n", argc);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_file - opens a given file in read mode
 * @filename: the pathname of the file to be opened
 *
 * Return: the file stream opened in read mode
 */
FILE *open_file(char *filename)
{
	FILE *monty_byte;

	monty_byte = fopen(filename, "r");
	if (monty_byte == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (monty_byte);
}
