#include "monty.h"

/**
 * get_op_fn - gets correspondng operator function
 * @token1: 1st bytecode input 
 * Return: pointer to the correct operation function
 */
void (*get_op_fn(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

    int i;
	
	for (i = 0; instruction_s[i].op != NULL; i++)
	{
		if (strcmp(token1, instruction_s[i].op) == 0)
			return instruction_s[i].f;
	}
	
	return NULL;
}
