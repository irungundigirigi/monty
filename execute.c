#include "monty.h"

/**
 * execute_instruction - executes an instruction based on opcode
 * @head: pointer to the head of the stack
 * @cmd_tkn: opcode token
 * @line: current line number
 */
void execute_instruction(stack_t **head, char *cmd_tkn, unsigned int line)
{
	void (*op_func)(stack_t **, unsigned int) = get_op_fn(cmd_tkn);

	if (op_func != NULL)
		op_func(head, line);
	else
	{
		free_dlist(head);
		printf("L%d: unknown instruction %s\n", line, cmd_tkn);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_resources - frees allocated memory and closes file descriptor
 * @head: pointer to the head of the stack
 * @buff: pointer to the buffer
 * @fd: file descriptor
 */
void free_resources(stack_t **head, char *buff, int fd)
{
	free_dlist(head);
	free(buff);
	close(fd);
}
