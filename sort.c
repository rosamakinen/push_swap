/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:18:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/30 15:22:28 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if we return 0 from the functions, the lists are sorted, otherwise we know they are not.
int	if_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	if_rev_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (1);
}


t_list	*sort(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int	check;
	t_list *head;

	stack_b = NULL;
	head = NULL;
	len = list_length(stack_a);
	if (len == 1)
		exit (0);
	check = if_sorted(stack_a);
	if (check == 0)
	{
		free_stack(&stack_a);
		exit (0);
	}
	check = if_rev_sorted(stack_a);
	if (check == 1 && len > 3)
	{
		while(list_length(stack_a) > 3)
		{
			rev_rotate(&stack_a, "rra");
			push(&stack_a, &stack_b, "pb");
		}
		if (list_length(stack_a) == 3)
			mini_sort(&stack_a);
		while(stack_b)
			push(&stack_b, &stack_a, "pa");
		if (if_sorted(stack_a) == 0)
		{
			exit (0);
		}
	}
	if (len <= 3)
		head = mini_sort(&stack_a);
	if (len > 3 && len <= 110)
		head = big_sort_initializer(stack_a, stack_b);
	if(len > 110)
		head = deal_with_it(&stack_a, &stack_b);
	return (head);
}
