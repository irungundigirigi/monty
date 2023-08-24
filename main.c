#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, was_push = 0;
	unsigned int line = 1;
	ssize_t bytes_r;
	char *buff, *cmd_tkn;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: No file argument\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't find file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
		return (0);

	bytes_r = read(fd, buff, 10000);
	if (bytes_r == -1)
	{
		free(buff);
		close(fd);
		exit(EXIT_FAILURE);
	}
	cmd_tkn = strtok(buff, "\n\t\a\r ;:");
	while (cmd_tkn != NULL)
	{
		if (was_push == 1)
		{
			push(&head, line, cmd_tkn);
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
            if (get_op_fn(cmd_tkn) != 0)
			{
				get_op_fn(cmd_tkn)(&head, line);
			}
			else
			{
				free_dlist(&head);
				printf("L%d: unknown instruction %s\n", line, cmd_tkn);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		cmd_tkn = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&head); free(buff);
	close(fd);
	return (0);
}
