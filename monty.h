#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *op;
        void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

void usage_error(void);
int open_file(const char *filename);
char *read_file(int fd);
void execute_instruction(stack_t **head, char *cmd_tkn, unsigned int line);
void free_resources(stack_t **head, char *buff, int fd);
void parse_and_execute(char *buff, stack_t **head);

void (*get_op_fn(char *token1))(stack_t **stack, unsigned int line_no);
void _add(stack_t **head, unsigned int line_no);
void _sub(stack_t **head, unsigned int line_no);
void _mul(stack_t **head, unsigned int line_no);
void _div(stack_t **head, unsigned int line_no);
void _mod(stack_t **head, unsigned int line_no);
void push(stack_t **head, unsigned int line_no, const char *n);
void pop(stack_t **head, unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void pall(stack_t **head, unsigned int line_no);
void swap(stack_t **head, unsigned int line_no);
void nop(stack_t **head, unsigned int line_no);
void pchar(stack_t **head, unsigned int line_no);
void pstr(stack_t **head, unsigned int line_no);
void rotl(stack_t **head, unsigned int line_no);
void rotr(stack_t **head, unsigned int line_no);

int add_end_node(stack_t **head, int n);
void delete_end_node(stack_t **head);
void free_dlist(stack_t **head);
#endif