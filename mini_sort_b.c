/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:07:51 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/01 10:18:56 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort_b(t_list **stack, int chunk_flag)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	head = *stack;
	if (chunk_flag == 0)
		len = list_length(*stack);
	if (chunk_flag > 0)
		len = chunk_flag;
	second = (*stack)->next;
	check = if_sorted(*stack);
	if (len == 2 && (head->data < second->data))
		swap(&head, "sb");
	if (len == 3)
		head = rev_sort_3(stack, &second, check);
	return (head);
}

t_list	*rev_sort_3(t_list **stack_b, t_list **second, int check)
{
	if (check == 0)
	{
		swap(stack_b, "sb");
		rev_rotate(stack_b, "rrb");
	}
	if ((*stack_b)->data < (*second)->data && \
		(*stack_b)->data > (*second)->next->data)
		swap(stack_b, "sb");
	else if ((*stack_b)->data < (*second)->data && \
		(*second)->data > (*second)->next->data)
		rotate(stack_b, "rb");
	else if ((*stack_b)->data > (*second)->data && \
		(*stack_b)->data > (*second)->next->data && \
		(*second)->data < (*second)->next->data)
	{
		swap(stack_b, "sb");
		rotate(stack_b, "rb");
	}
	else if ((*stack_b)->data > (*second)->data && \
		(*stack_b)->data < (*second)->next->data && \
		(*second)->data < (*second)->next->data)
		rev_rotate(stack_b, "rrb");
	return (*stack_b);
}
