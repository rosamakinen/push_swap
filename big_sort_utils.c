/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:45:54 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/30 17:30:26 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*deal_with_it(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int	bit;
	int	len;
	int	j;

	bit = 0;
	len = (list_length(*stack_a));
	get_pos_radix(stack_a);
	while (bit < 32)
	{
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
		while (*stack_b)
			push(stack_b, stack_a, "pa");
		bit++;
		if (if_sorted(*stack_a) == 0)
		{
			free_stack(stack_a);
			exit (0);
		}
	}
	return (*stack_a);
}

t_list *get_pos_radix(t_list **stack)
{
	int		len;

	len = list_length(*stack);
	bubblesort(stack, len, "order");
	return (*stack);
}

void	do_operations(int len, t_list **stack_b, int flag)
{
	if ((len == 2 || len == 3) && flag != 1)
	{
		if (len == 2 && (*stack_b)->data < (*stack_b)->next->data)
			swap(stack_b, "sb");
		else if (len == 3)
			rev_sort_3(stack_b, &(*stack_b)->next, 1);
		}
}
