#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *head;
	char *buff;
	int fd;

	head = NULL;
	if (argc != 2)
		usage_error();

	fd = open_file(argv[1]);
	buff = read_file(fd);

	parse_and_execute(buff, &head);

	free_resources(&head, buff, fd);

	return (0);
}
