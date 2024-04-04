# PUSH_SWAP

## Projet 42

The Push swap project is a simple and effective algorithmic exercise: you have to sort data. We have a set of integers, two stacks and a set of instructions for manipulating them. We must write a C program called push_swap that calculates and displays on standard output the smallest program, made up of instructions from the Push swap language, for sorting the integers passed as parameters.
The following instructions are available for this purpose:
- sa (swap a): swaps the first 2 elements at the top of stack a.
Does nothing if there is only one or none.
- sb (swap b ): Swaps the first 2 elements at the top of stack b.
Does nothing if there is only one or none.
- ss : sa and sb at the same time.
- pa (push a): Takes the first element at the top of b and puts it on a.
Does nothing if b is empty.
- pb (push b): Takes the first element on top of a and sets it to b.
Does nothing if a is empty.
- ra (rotate a): Shifts all elements in stack a upwards by one position.
The first element becomes the last.
- rb (rotate b): Shifts all elements in stack b up one position.
The first element becomes the last.
- rr: ra and rb at the same time.
- rra (reverse rotate a): Shifts all stack elements down one position.
a stack. The last element becomes the first.
- rrb (reverse rotate b): Shifts all elements in stack b downwards by one position. The last element becomes the first.
- rrr: rra and rrb at the same time.

  To have 100%, we must to have less than 7500 instructions for 500.

  
