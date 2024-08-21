#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *top;
	 stack_t *second_top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	top = *head;
	second_top = top->next;

	second_top->n += top->n;
	*head = second_top;
	second_top->prev = NULL;

	free(top);
}
