/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:56:07 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/03 11:56:35 by rmakinen         ###   ########.fr       */
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
	static int		position;

	position = 1;
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
			node->position = position;
			node->next = NULL;
		}
		list = list->next;
		position++;
	}
	return (top);
}

t_list	*add_new(int new_data)
{
	t_list *new_node;
	int		position;

	position = 1;
	new_node = (t_list *) malloc(sizeof(t_list));
		if (new_node == NULL)
			return (NULL);
	new_node->data = new_data;
	new_node->position = position;
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
		i++;
	}
	return (stack);
}

void	print_stack(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%i\n", temp->data);
		//ft_printf("pos: %i\n", temp->position);
		temp = temp->next;
	}
}


int	main(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*print_temp;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	print_temp = NULL;

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
	// 	ft_printf("%i\n", stack_a->data);
	// 	stack_a = stack_a->next;
	// }
	//stack_a = push_swap(stack_a, stack_b);
	//stack_a = sort(stack_a, stack_b);
	print_temp = stack_a;
	print_stack(stack_a);
	sort(stack_a, stack_b);
	return (0);
}
