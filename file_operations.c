#include "monty.h"

/**
 * open_file - Opens a file for reading.
 * @filename: Name of the file to open.
 * Return: File descriptor on success, exits with failure on error.
 */
int open_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't find file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * read_file - Reads the contents of a file into a buffer.
 * @fd: File descriptor.
 * Return: Pointer to the buffer containing file contents.
 */
char *read_file(int fd)
{
	char *buff;
	ssize_t bytes_r;

	buff = malloc(sizeof(char) * 10000);
	if (!buff)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	bytes_r = read(fd, buff, 10000);
	if (bytes_r == -1)
	{
		perror("read");
		free(buff);
		close(fd);
		exit(EXIT_FAILURE);
	}

	return (buff);
}

