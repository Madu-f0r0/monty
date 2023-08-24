#ifndef MONTY_H
#define MONTY_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* The integer to be manipulated by the stack functions */
extern int n;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Stack Functions */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* Helper Functions */
char *_strdup(char *str);
int _strlen(char *s);
int check_if_digit(char *num);
void confirm_arg_count(int argc);
char **op_tokenizer(char *lineptr);
FILE *open_file(char *filename);
void set_me_free(char **op_tokens);

#endif /* MONTY_H */