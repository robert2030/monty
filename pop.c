#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 *
 * Return: 0 if the stack is empty, 1 on success
 */
int f_pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return (0);
	}

	if ((*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}

	return (1);
}
