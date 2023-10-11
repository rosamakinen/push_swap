# push_swap
Push_swap is a program to find the least moves to sort a stack of integers and explore sorting algorithms. It has three different algorithms to sort to sort under 3, 100 and 500 integers. 

The main objective of push_swap is to return the least moves to sort a stack_a. The lowest number should be at the top and you can only use two stacks for this process. Each move should be followed by a newline.

For this project I wanted to learn and use linked lists and I ended up implementing four different sorting algorithms. 
- Hardcoded sort for 3 integers and less.
- Quicksort -insprired sort for more than 3 and less than 150 integers.
- Bubblesort for comparing the values in spesific positions of the sorted list in the quicksort.
- Radix sorting to sort over 150 integers efficiently using bitshifting.

The moves we were allowed to use were either rotating the stacks, swapping the top two integers or pushing integers from one stack to the other. 
-ra, rb, rr (rotate a, rotate b, rotate both at the same time)
-rra, rrb, rrr (reverse rotate a, reverse rotate b, reverse rotate both)
-sa, sb, ss (swap a, swap b, swap both)
-pa, pb (push a, push b)

Run the program by calling make and running ./push_swap with the integers you want to sort. If there are no parameters or the stack is already sorted the program will just return the prompt. 

If there are double integers, non-integers or the input is outside INT range the program will return an error message.
