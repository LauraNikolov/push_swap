# PUSH_SWAP

## Projet 42

The Push_swap project is a simple yet effective algorithmic exercise focused on sorting data. You are given a set of integers, two stacks, and a set of instructions to manipulate them. The goal is to write a C program called push_swap that calculates and displays, on standard output, the shortest possible sequence of instructions from the Push_swap language needed to sort the integers passed as parameters

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

 ## My Approach for Push_swap
My approach to the Push_swap project is based on efficiently using the two stacks and the allowed operations to minimize the number of moves needed to sort the list.
First, I push all elements from stack A to stack B in a controlled order. By doing this, I prepare stack B so that it holds elements in an order that will make it easier to rebuild the sorted stack A later.
Both stacks are managed as circular linked lists, which allows me to rotate elements efficiently, moving the top and bottom elements without costly rearrangements.
While pushing elements to stack B, I keep track of the minimum and maximum values in stack B. This helps me decide where to place new elements in B so that the overall order is easier to maintain and restore.
For small sets of elements (like three), I apply a dedicated sorting method that uses the minimal number of instructions to handle those quickly.
This approach balances simplicity and efficiency, minimizing operations by carefully planning the movement of elements between the two stacks.


  
