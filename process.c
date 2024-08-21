#include "monty.h"
/**
 * process_instruction - Processes the instruction of the Monty bytecode.
 * @stack: Double pointer to the head of the stack.
 * @instruct: Instruction to be processed.
 * @line_num: Line number where the instruction is encountered.
 * Return: 1t on success, 0 on failure.
 */
int process_instruction(stack_t **stack, char *instruct, unsigned int line_num)
{
	char *opcode = strtok(instruct, " \n\t");
	char *argument = strtok(NULL, " \n\t");

	if (!opcode)
	{
		fprintf(stderr, "L%u: invalid instruction\n", line_num);
		return (0);
	}

	if (strcmp(opcode, "push") == 0)
	{
		if (!argument)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			return (0);
		}

		push(stack, line_num);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		if (!*stack)
		{
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
			return (0);
		}
		f_pop(stack);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_num);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		return (0);
	}

	return (1);
}
