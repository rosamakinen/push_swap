/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:12:01 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/30 17:36:36 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int	limit;
	int	chunk;
	int	target_position;

	stack_b = 0;
	chunk = 1;
	target_position = 0;
	limit = bubblesort(&stack_a, (list_length(stack_a)-1), "limit");
	preprocess(&stack_a, &stack_b, limit, list_length(stack_a));
	while (stack_b)
	{
		len = list_length(stack_b);
		if ((len == 2 || len == 3) && chunk != 999)
		{
			do_operations(len, &stack_b, chunk);
			chunk = 999;
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
	int		push_back;
	int		flag;
	t_list	*temp;

	temp = *stack_a;
	push_back = 0;
	flag = 0;

	if (len > 3)
	{
		while (push_back <= (len / 2) && len >= 4)
		{
			if ((*stack_a)->data <= limit)
			{
				push(stack_a, stack_b, "pb");
				push_back++;
			}
			else if ((*stack_a)->data > limit)
				rotate(stack_a, "ra");
			else
			{
				while (temp->next != NULL)
					temp = temp->next;
				if (temp->data <= limit)
					rev_rotate(stack_a, "rra");
			}
			len = list_length(*stack_a);
	}
		if (len <= 3)
				mini_sort(stack_a);
		if (len > 3)
		{
			len = list_length(*stack_a);
			limit = bubblesort(stack_a, len, "limit");
			preprocess(stack_a, stack_b, limit, len);
		}
	}
	return(temp);
}

int	find_end_position(t_list **stack_a, t_list **top_at_b, int target_value)
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
		if (temp_a->data > from_b && temp_a->data < target_value)
		{
			target_pos = temp_a->position;
			target_value = temp_a->data;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

t_list	*rotate_and_add(t_list **stack_a, t_list **stack_b, int target_position)
{
	int mid;

	mid = (list_length(*stack_a) / 2);
	if (mid > target_position)
	{
		while ((*stack_a)->position != target_position)
			rotate(stack_a, "ra");
	}
	if (mid <= target_position)
	{
		while ((*stack_a)->position != target_position)
			rev_rotate(stack_a, "rra");
	}
	if ((*stack_a)->position == target_position)
	{
		push(stack_b, stack_a, "pa");
	}
	return(*stack_a);
}

// too long

int	reorder_a(t_list **stack_a)
{
	int	lowest_value;
	int	lowest_position;
	int mid;
	t_list	*temp;

	lowest_value = 2147483647;
	lowest_position = 0;
	mid = (list_length(*stack_a) / 2);
	temp = (*stack_a);
	stack_reposition(stack_a);
	while(temp)
	{
		if (temp->data < lowest_value)
		{
			lowest_value = temp->data;
			lowest_position = temp->position;
		}
		temp = temp->next;
	}
	if (mid > lowest_position)
	{
		while ((*stack_a)->data != lowest_value)
			rotate(stack_a, "ra");
	}
	if (mid <= lowest_position)
	{
		while ((*stack_a)->data != lowest_value)
			rev_rotate(stack_a, "rra");
	}
	return (lowest_value);
}

// too long

int	bubblesort(t_list **stack, int len, char *str)
{
	int		array[len];
	int		i;
	int		j;
	int		temp;
	t_list	*temp_s;

	i = 0;
	temp_s = *stack;
	while(temp_s)
	{
		array[i] = temp_s->data;
		temp_s = temp_s->next;
		i++;
	}
	j = 0;
	while (j < (len-1))
	{
		i = 0;
		while (i < (len-1))
		{
			if(array[i] > array[i+1])
				ft_swap(&array[i], &array[i+1]);
			i++;
		}
		j++;
	}
	temp_s = *stack;
	if (ft_strcmp(str, "limit") == 0)
		i = len / 2;
	else if (ft_strcmp(str, "order") == 0)
	{
		j = 0;
		while (array[j])
		{
			while (temp_s && j < len)
			{
				if (array[j] == temp_s->data)
					temp_s->position = j;
				temp_s = temp_s->next;
			}
			temp_s = *stack;
			j++;
		}
	}
	temp = array[i];
	return (temp);
}
