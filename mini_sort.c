/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:59:31 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/04 11:32:43 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort(t_list **stack)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	head = *stack;
	len = list_length(*stack);
	check = if_rev_sorted(*stack);
	second = (*stack)->next;
	if (len == 2 && (head->data > second->data))
		swap(&head, "sa");
	if (len == 3)
		head = sort_3(stack, &second, check);
	return (head);
}

t_list	*sort_3(t_list **stack_a, t_list **second, int check)
{
	if (check == 1)
	{
		swap(stack_a, "sa");
		rev_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->data > (*second)->data && \
		(*stack_a)->data < (*second)->next->data)
		swap(stack_a, "sa");
	else if ((*stack_a)->data > (*second)->data && \
		(*second)->data < (*second)->next->data)
		rotate(stack_a, "ra");
	else if ((*stack_a)->data < (*second)->data && \
		(*stack_a)->data < (*second)->next->data && \
		(*second)->data > (*second)->next->data)
	{
		swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	else if ((*stack_a)->data < (*second)->data && \
		(*stack_a)->data > (*second)->next->data && \
		(*second)->data > (*second)->next->data)
		rev_rotate(stack_a, "rra");
	return (*stack_a);
}
