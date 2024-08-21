#ifndef __MONTY_H
#define __MONTY_H

#define  MAX_LEN 1024
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

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


void push(stack_t **stack, unsigned int line_number);
int  f_pop(stack_t **stack);
void pall(stack_t **stack, unsigned int line_number);
int main(int argc, char *argv[]);
int process_instruction(stack_t **stack, char *instruct, unsigned int line_num);
void free_stack(stack_t *stack);
void add(stack_t **head, unsigned int line_number);
int is_number(char *str);
void nop(stack_t **stack, unsigned int line_number);

#endif
