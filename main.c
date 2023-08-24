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

	if (argc != 2) //Check for correct no of command line args
	{
		printf("USAGE: No file argument\n");
		exit(EXIT_FAILURE);
	}    
	fd = open(argv[1], O_RDONLY); //Open specified file for reading
	if (fd == -1)
	{
		printf("Error: Can't find file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000); //Allocate memory for reading file contents
	if (!buff)
		return (0);

	bytes_r = read(fd, buff, 10000); //Read the files content into buff
	if (bytes_r == -1)
	{
		free(buff);
		close(fd);
		exit(EXIT_FAILURE);
	}
	cmd_tkn = strtok(buff, "\n\t\a\r ;:"); //cmd_tknize buff to read individual commands
	while (cmd_tkn != NULL)
	{
		if (was_push == 1)
		{           
			push(&head, line, cmd_tkn); //Process was_push command - adds value to stack
			was_push = 0;
			cmd_tkn = strtok(NULL, "\n\t\a\r ;:"); //returns next token
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
