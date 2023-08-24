#include "monty.h"

 /**
 * pint - print top node in stack
 * @head: head of list
 * @line_no: line number
 */
void pint(stack_t **head, unsigned int line_no)
{
	if (!*head || !head)
	{
		printf("L%u: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pall - print all nodes in stack
 * @head: head of list
 * @line_no: line number
 */
void pall(stack_t **head, unsigned int line_no)
{
	stack_t *tmp = NULL;
	(void) line_no;

	if (!*head || !head)
		return;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pchar - print top node in stack as ascii letter
 * @head: head of list
 * @line_no: line number
 */
void pchar(stack_t **head, unsigned int line_no)
{
	if (!*head || !head)
	{
		printf("L%u: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (((*head)->n) >= 0 && ((*head)->n) <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}

}
/**
 * pstr - print top nodes in stack as ascii letter
 * and stop only if end of stack, node is 0, or not in ascii table
 * @head: head of list
 * @line_no: line number
 */
void pstr(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;

	if (!*head || !head)
	{
		printf("L%u: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	while ((tmp != NULL) && (tmp->n != 0) &&
	       (tmp->n >= 0) && (tmp->n <= 127))
	{
		printf("%c", (tmp)->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * nop - do nothing
 * @head: head of list
 * @line_no: line number
 */
void nop(stack_t **head, unsigned int line_no)
{
	(void) head;
	(void) line_no;
}
