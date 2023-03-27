
#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list *temp;

	temp = (*stack);
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array)
	{
		free(array[i]);
		i++;
	}
	free(array);
}