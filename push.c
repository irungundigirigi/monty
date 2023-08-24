#include "monty.h"

/**
 * is_number - checks each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_num(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * add_end_node - add node to front of doubly linked list
 * @h: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **head, int n)
{
	stack_t *new;

	if (!head)
		return (-1);

	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	/* account for empty linked list */
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else /* insert to front */
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (0);
}

/**
 * push - adds node to the start of doubly linked list (stack)
 * @head: head of linked list 
 * @line_no: line number
 * @n: integer
 */
void push(stack_t **head, unsigned int line_no, const char *n)
{
	if (!head)
		return;
	if (is_num(n) == -1)
	{
		printf("L%u: usage: Push int only\n", line_no);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(head, atoi(n)) == -1)
		{
			free_dlist(head);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @h: pointer to head of list
 */
void free_dlist(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}