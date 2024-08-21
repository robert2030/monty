#include "monty.h"

/**
 * free_stack - Frees a doubly linked list representing a stack.
 * @stack: A pointer to the head of the stack.
 *
 * This function iterates through the doubly linked list starting from
 * the head (top) and frees the memory for each node.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
