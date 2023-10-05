# Monty Bytecode interpreter
Python code, just like Monty 0.98, is compiled to bytecode first. This C program opens a bytecode file (provided as argument) and reads and executes the commands line by line. 
[See more about bytecode](https://opensource.com/article/18/4/introduction-python-bytecode)

## Compilation
To compile the program, use:
```
$ make
```

## Opcodes function
|opcode | function |
| --- | --- |
| push | add element to the 'top' of stack and 'end' of queue  |
| pop  | remove element from 'top' of stack and 'end' of queue |
|pall  |print every member of the structure|
| pint | prints the member value at the top of stack |
| swap | swaps the order  of the 1st and 2nd elements in stack |
| add | add top two member values |
| sub | subtract the top element from the 2nd top element |
| div | divide the 2nd element by the top element |
| mul | multiply the top two elements of the stack |
| mod | the remainder when the 2nd element is divided by the top element |
| comment | there is the ability to parse comments found in bytecode ->'#'|
| pchar | print character at the top of the stack |
| pstr | print the character at the top of the stack|
| rotl | moves element at the top to the bottom of the stack |
| rotr | the bottom of the stack becomes the top |
| queue, stack | toggles the doubly link list implementation style |
| nop | opcode should do nothing |


Examples:
`$ cat file.m`

`push 1`

`push 2`

`push 3`

`pall`

`$ ./montyfile file.m`

`3`

`2`

`1`

`$`

---

`$ cat file.m`

`push 1`

`push 2`

`push 3`

`pall`

`rotl`

`pall`

`$ ./montyfile file.m`

`3`

`2`

`1`

`2`

`1`

`3`
