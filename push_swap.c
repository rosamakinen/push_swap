/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:56:07 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/06 16:05:33 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_top(t_list *top, int new_data)
{
	t_list *node;

	node = (t_list *) malloc(sizeof(t_list));
		if (node == NULL)
			return (NULL);
	node->data = new_data;
	node->next = top;

	return (node);
}

t_list	*add_new(int new_data)
{
	t_list *new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
		if (new_node == NULL)
			return (NULL);
	new_node->data = new_data;
	new_node->next = NULL;

	return (new_node);
}

t_list	*fill_stack(t_list *stack, char *argument)
{
	int	data;
	char **array;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	array = ft_split(argument, ' ');
	flag = check_for_nonint(argument);
	while (array[i] != '\0')
	{
		data = ft_atoi(array[i]);
		check_for_range(data);
		//ft_printf("data from array %d is %i\n", i, data); //remove !!
		flag = check_for_duplicates(data, stack);
		if (!stack && flag == 0)
			stack = add_new(data);
		else
		{
			if (flag == 0)
			stack = add_top(stack, data);
		}
		//ft_printf("data of the node is: %i\n", stack->data);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int	i;
	t_list *stack;

	i = 1;
	stack = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		// ft_printf("[argv %d] %s\n", i, argv[i]); //remove !!
		stack = fill_stack(stack, argv[i]);
		i++;
	}
	// while (stack) //remove !!
	// {
	// 	ft_printf("stack data %i\n", stack->data);
	// 	stack = stack->next;
	// }
	return (0);
}
