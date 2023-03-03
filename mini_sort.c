/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:59:31 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/03 14:06:03 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort(t_list *stack_a, t_list *stack_b)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	stack_b = NULL;
	len = list_length(stack_a);
	check = if_rev_sorted(stack_a);
	second = stack_a->next;
	//stack_reposition(stack_a);
	if (len > 3)
	{
		//find two smallest numbers, push to b, sort a, push back???

	}
	if (len <= 3)
	{
		if (check == 0)
		{
			swap(&stack_a, "sa");
			rev_rotate(&stack_a, "ra");
		}
		if (stack_a->data > second->data && \
		stack_a->data < second->next->data)
			swap(&stack_a, "sa");
		if (stack_a->data > second->data && \
		stack_a->data > second->next->data)
			rotate(&stack_a, "ra");
		if (stack_a->data < second->data && \
		second->data > second->next->data)
			rev_rotate(&stack_a, "rra");
	}
	head = stack_a;
	print_stack(head);
	return (head);
}
