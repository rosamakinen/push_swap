/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:56:07 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/22 11:00:19 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*add_top(t_list *top, int new_data) // remove maybe!!
// {
// 	t_list	*node;

// 	node = (t_list *) malloc(sizeof(t_list));
// 		if (node == NULL)
// 			return (NULL);
// 	node->data = new_data;
// 	node->next = top;

// 	return (node);
// }

t_list *add_bottom(t_list *list, int new_data)
{
	t_list	*node;
	t_list	*top;

	top = list;
	node = (t_list *) malloc(sizeof(t_list));
		if (node == NULL)
			return (NULL);
	node->data = new_data;
	while(list)
	{
		if (list->next == NULL)
		{
			list->next = node;
			node->next = NULL;
		}
		list = list->next;
	}
	return (top);
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
		flag = check_for_duplicates(data, stack);
		if (!stack && flag == 0)
			stack = add_new(data);
		else
		{
			if (flag == 0)
			stack = add_bottom(stack, data);
		}
		//ft_printf("what happens here %i\n", stack->data);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		//ft_printf("we get here??\n");
		stack_a = fill_stack(stack_a, argv[i]);
		i++;
	}
	// while (stack_a)
	// {
	// 	//ft_printf("issue not getting here?\n");
	// 	ft_printf("%i\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	//stack_a = push_swap(stack_a, stack_b);
	//stack_a = sort(stack_a, stack_b);
	sort(stack_a, stack_b);
	while (stack_a)
	{
		// ft_printf("issue not getting here?\n");
		ft_printf("%i\n", stack_a->data);
		stack_a = stack_a->next;
	}
	return (0);
}
