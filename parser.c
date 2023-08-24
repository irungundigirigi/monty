#include "monty.h"

/**
 * parse_and_execute - parses and executes the instructions in the buffer
 * @buff: input buffer containing instructions
 * @head: pointer to the head of the stack
 */
void parse_and_execute(char *buff, stack_t **head)
{
	char *cmd_tkn;
	unsigned int line = 1;
	int was_push = 0;

	cmd_tkn = strtok(buff, "\n\t\a\r ;:");
	while (cmd_tkn != NULL)
	{
		if (was_push == 1)
		{
			push(head, line, cmd_tkn);
			was_push = 0;
			cmd_tkn = strtok(NULL, "\n\t\a\r ;:");
			line++;
			continue;
		}
		else if (strcmp(cmd_tkn, "push") == 0)
		{
			was_push = 1;
			cmd_tkn = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			execute_instruction(head, cmd_tkn, line);
		}
		line++;
		cmd_tkn = strtok(NULL, "\n\t\a\r ;:");
	}
}
