/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:45:54 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/03 15:44:29 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*deal_with_it(t_list **stack_a, t_list **stack_b)
{
	int		bit;
	int		len;

	bit = 0;
	len = list_length(*stack_a);
	get_pos_radix(stack_a);
	while (bit < 32)
	{
		shift(stack_a, stack_b, bit, len);
		while (*stack_b)
			push(stack_b, stack_a, "pa");
		bit++;
		if_sorted(*stack_a);
	}
	return (*stack_a);
}

t_list	*shift(t_list **stack_a, t_list **stack_b, int bit, int len)
{
	t_list	*temp;
	int		j;

	temp = *stack_a;
	j = 0;
	while (j < len)
	{
		if (((temp->position >> bit) & 1) == 0)
			push(stack_a, stack_b, "pb");
		else
			rotate(stack_a, "ra");
		temp = *stack_a;
		j++;
	}
	return (*stack_a);
}

void	do_operations(int len, t_list **stack_b)
{
	if ((len == 2 || len == 3))
	{
		if (len == 2 && (*stack_b)->data < (*stack_b)->next->data)
		{
			swap(stack_b, "sb");
		}
		else if (len == 3)
			rev_sort_3(stack_b, &(*stack_b)->next, 1);
	}
}

int	find_lowest_position(t_list **stack_a, int lowest_value)
{
	t_list	*temp;
	int		lowest_position;

	lowest_position = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->data == lowest_value)
			lowest_position = temp->position;
		temp = temp->next;
	}
	return (lowest_position);
}

int	reorder_a(t_list **stack_a)
{
	int	lowest_value;
	int	lowest_position;
	int	mid;
	int	len;

	lowest_position = 0;
	mid = (list_length(*stack_a) / 2);
	len = list_length(*stack_a);
	stack_reposition(stack_a);
	lowest_value = bubblesort(stack_a, len, "smallest");
	lowest_position = find_lowest_position(stack_a, lowest_value);
	if (mid >= lowest_position)
		while ((*stack_a)->data != lowest_value)
			rotate(stack_a, "ra");
	if (mid < lowest_position)
		while ((*stack_a)->data != lowest_value)
			rev_rotate(stack_a, "rra");
	return (lowest_value);
}
