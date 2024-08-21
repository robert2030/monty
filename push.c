#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the push opcode is encountered.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *value_str = strtok(NULL, " \n\t");

	if (!value_str || !is_number(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * is_number - Checks if a string represents a valid number.
 * @str: String to be checked.
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(char *str)
{
	if (!str)
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
