
#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list *temp;

	//ft_printf("free_stack pls\n");
	temp = (*stack);
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}

void	free_array(char ***array)
{
	int		i;
	char	**temp;

	//ft_printf("free_array pls\n");
	temp = *array;
	i = 0;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(*array);
}

void	exit_and_free(char **array, t_list *stack)
{
	//ft_printf("exit and free\n");
	write(2, "Error\n", 6);
	free_array(&array);
	free_stack(&stack);
	exit (1);
}
