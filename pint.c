#include <stdio.h>
#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack.
 * @head: Double pointer to the stack`s head.
 * @line_number: Line number of the file.
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
