#include "monty.h"

/**
 * main - Entry point for Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char line[MAX_LEN];
	FILE *file;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		if (strcmp(line, "") == 0 || line[0] == ' ')
			continue;

		if (!process_instruction(&stack, line, line_number))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
