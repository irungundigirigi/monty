#include "monty.h"
/**
 * add_end_node - add node to front of doubly linked list
 *@head: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_end_node(stack_t **head, int n)
{
	stack_t *new;

	if (!head)
		return (-1);

	/* malloc and set new node data */
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
};
/**
 * delete_end_node - deletes node at end of doubly linked list
 *@head: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **head)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(del);
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(del);
	}
};
/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 *@head: pointer to head of list
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
};
