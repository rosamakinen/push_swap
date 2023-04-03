/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:56:07 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/03 15:25:52 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_bottom(t_list *list, int new_data)
{
	t_list	*node;
	t_list	*top;
	int		position;

	position = 1;
	top = list;
	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = new_data;
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = node;
			node->position = position;
			node->previous = list;
			node->next = NULL;
		}
		list = list->next;
		position++;
	}
	return (top);
}

t_list	*add_new(int new_data)
{
	t_list	*new_node;
	int		position;

	position = 1;
	new_node = (t_list *) malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = new_data;
	new_node->position = position;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

t_list	*fill_stack(t_list *stack, char *argument)
{
	int		data;
	char	**array;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	array = ft_split(argument, ' ');
	flag = check_for_nonint(argument, flag);
	while (array[i] != NULL)
	{
		data = ft_atoi(array[i]);
		flag = check_for_range(data, array[i], flag);
		flag = check_for_duplicates(data, stack, flag);
		if (flag == 1)
			exit_and_free(array, stack);
		else if (!stack && flag == 0)
			stack = add_new(data);
		else if (flag == 0)
			stack = add_bottom(stack, data);
		i++;
	}
	free_array(&array);
	return (stack);
}

void	print_stack(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%i\n", temp->data);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit (1);
	while (i < argc)
	{
		stack_a = fill_stack(stack_a, argv[i]);
		i++;
	}
	stack_a = sort(stack_a, stack_b);
	free_stack(&stack_a);
	return (0);
}
