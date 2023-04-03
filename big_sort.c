/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:12:01 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/03 14:09:23 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int	limit;
	int	flag;
	int	target_position;

	stack_b = 0;
	flag = 1;
	target_position = 0;
	limit = bubblesort(&stack_a, (list_length(stack_a)-1), "limit");
	preprocess(&stack_a, &stack_b, limit, list_length(stack_a));
	while (stack_b)
	{
		len = list_length(stack_b);
		if ((len == 2 || len == 3) && flag != 0)
		{
			do_operations(len, &stack_b);
			flag = 0;
		}
		target_position = find_end_position(&stack_a, &stack_b, 2147483647);
		rotate_and_add(&stack_a, &stack_b, target_position);
	}
	free_stack(&stack_b);
	reorder_a(&stack_a);
	return (stack_a);
}

t_list	*preprocess(t_list **stack_a, t_list **stack_b,	int limit, int len)
{
	if (len > 3)
	{
		search_from_top(stack_a, stack_b, limit, len);
		if (len > 3)
		{
			len = list_length(*stack_a);
			limit = bubblesort(stack_a, len, "limit");
			preprocess(stack_a, stack_b, limit, len);
		}
		if (len <= 3)
			mini_sort(stack_a);
	}
	return (*stack_a);
}

t_list	*search_from_top(t_list **st_a, t_list **st_b, int limit, int len)
{
	int		pushed;
	t_list	*temp;

	pushed = 0;
	temp = *st_a;
	while (pushed <= (len / 2) && len >= 4)
	{
		if ((*st_a)->data <= limit)
		{
			push(st_a, st_b, "pb");
			pushed++;
		}
		else if ((*st_a)->data > limit)
			rotate(st_a, "ra");
		else
		{
			while (temp->next != NULL)
				temp = temp->next;
			if (temp->data <= limit)
				rev_rotate(st_a, "rra");
		}
		len = list_length(*st_a);
	}
	return (*st_a);
}

int	find_end_position(t_list **stack_a, t_list **top_at_b, int target)
{
	t_list	*temp_a;
	int		from_b;
	int		target_pos;

	target_pos = 0;
	temp_a = (*stack_a);
	from_b = (*top_at_b)->data;
	stack_reposition(stack_a);
	while (temp_a)
	{
		if (temp_a->data > from_b && temp_a->data < target)
		{
			target_pos = temp_a->position;
			target = temp_a->data;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

t_list	*rotate_and_add(t_list **stack_a, t_list **stack_b, int target_pos)
{
	int	mid;

	mid = (list_length(*stack_a) / 2);
	if (mid >= target_pos)
		while ((*stack_a)->position != target_pos)
			rotate(stack_a, "ra");
	if (mid < target_pos)
		while ((*stack_a)->position != target_pos)
			rev_rotate(stack_a, "rra");
	if ((*stack_a)->position == target_pos)
		push(stack_b, stack_a, "pa");
	return (*stack_a);
}
