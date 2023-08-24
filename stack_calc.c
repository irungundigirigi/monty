#include "monty.h"
/**
 * _add - adds the top two elements in stack
 * @head: pointer to top of the node 
 * @line_no: command line
 */
void _add(stack_t **head, unsigned int line_no)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * _sub - subtract second top node from top node
 * @head: pointer to top of the node
 * @line_no: command line
 */
void _sub(stack_t **head, unsigned int line_no)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * _mul - multiply second top node and top node
 * @head: pointer to top of the node
 * @line_no: command line
 */
void _mul(stack_t **head, unsigned int line_no)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * _div - divide second top node from top node
 * @head: pointer to top of the node
 * @line_no: command line
 */
void _div(stack_t **head, unsigned int line_no)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0 || (*head)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_no);
	}
	(*head)->next->n /= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * _mod - modulus of second top node from top node
 * @head: pointer to top of the node 
 * @line_no: command line
 */
void _mod(stack_t **head, unsigned int line_no)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0 || (*head)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_no);
	}
	(*head)->next->n %= (*head)->n;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
