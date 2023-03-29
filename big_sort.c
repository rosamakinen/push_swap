/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:12:01 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/29 16:00:27 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int limit;
	int chunk;
	int target_position;
	//int test;

	if (!stack_a)
		return (0);
	stack_b = 0;
	len = list_length(stack_a);
	chunk = 1;
	limit = bubblesort(stack_a, len);
	//test = len;
	target_position = 0;
	preprocess(&stack_a, &stack_b, limit, len, chunk);
	// ft_printf("\n");
	// ft_printf("**_______ PREPROCESS OK _______**\n");
	// ft_printf("\n");
	//print_stack(stack_b);
	while (stack_b)
	{
		len = list_length(stack_b);
		// ft_printf("len is %i\n", len);
		// ft_printf("data is %i\n", stack_b->data);
		// ft_printf("next->data is %i\n", stack_b->next->data);
		if ((len == 2 || len == 3) && chunk != 999)
		{
		// 	ft_printf("ENTRY");
			if (len == 2 && stack_b->data < stack_b->next->data)
			{
				swap(&stack_b, "sb");
			}
			else if (len == 3)
				rev_sort_3(&stack_b, &stack_b->next, 1);
			chunk = 999;
		}
		// ft_printf("segcheck\n");
		// print_stack(stack_b);
		// ft_printf("**_______ STACK A IS: _______**\n");
		// print_stack(stack_a);
		// ft_printf("**_______ END OF STACK A _______**\n");
		// ft_printf("**_______ STACK B IS: _______**\n");
		// print_stack(stack_b);
		// ft_printf("**_______ END OF STACK B _______**\n");
		target_position = find_end_position(&stack_a, &stack_b, 2147483647);
		rotate_and_add(&stack_a, &stack_b, target_position);
		// ft_printf("do we ever ever get here??\n");
	}
	free_stack(&stack_b);
	reorder_a(&stack_a);
	// ft_printf("2. security check for stack_a\n");
	// print_stack(stack_a);
	//print_stack(stack_b);
	//print_stack(temp);
	return (stack_a);
}

t_list *preprocess(t_list **stack_a, t_list **stack_b, int limit, int stack_len, int chunk)
{
	int		push_back;
	int		flag;
	t_list *temp;

	temp = *stack_a;
	push_back = 0;
	flag = 0;
	// ft_printf("limit is: %i\n", limit);
	if (stack_len > 3)
	{
		while (push_back <= (stack_len / 2) && stack_len >= 4) // && stack_len > 4
		{
			if ((*stack_a)->data <= limit)
			{
				(*stack_a)->chunk = chunk;
				push(stack_a, stack_b, "pb");
				push_back++;
			}
			else if ((*stack_a)->data > limit) //&& flag == 1)
				rotate(stack_a, "ra");
			else // ((*stack_a)->data > limit)
			{
				while (temp->next != NULL)
					temp = temp->next;
				if (temp->data <= limit)
				{
					rev_rotate(stack_a, "rra");
					//flag = 1;
				}
			}
			// ft_printf("_____ TEST TEST TEST _____\n");
			stack_len = list_length(*stack_a);
		// 	ft_printf("stack_len is %i\n", stack_len);
		// 	ft_printf("limit is %i\n", limit);
		// 	ft_printf("push_back is %i\n", push_back);
		// }
	}
	if (stack_len <= 3)
	{
			mini_sort(stack_a);
	}
	// ft_printf("_____ STACK A IS LIKE THIS: _____\n");
	// print_stack(*stack_a);
	// ft_printf("\n");
	// ft_printf("_____ STACK B IS LIKE THIS: _____\n");
	// print_stack(*stack_b);
	// ft_printf("\n");
	if (stack_len > 3)
	{
		// ft_printf("\n");
		// ft_printf("___ NEW SORTCYCLE FOR A ___\n");
		// ft_printf("\n");
		chunk++;
		// ft_printf("___ NEW CHUNK DIVISION FOR A, chunk %i ___\n", chunk);
		stack_len = list_length(*stack_a);
		limit = bubblesort(*stack_a, stack_len);
		preprocess(stack_a, stack_b, limit, stack_len, chunk);
	}
	//ft_printf("loopcheck\n");
	//print_stack(*stack_a);
	//ft_printf("cleared process??\n");
	}
	return(temp);
}

int	find_end_position(t_list **stack_a, t_list **top_at_b, int target_value)
{
	t_list *temp_a;
	int 	from_b;
	int		target_pos;

	target_pos = 0;
	temp_a = (*stack_a);
	from_b = (*top_at_b)->data;
	stack_reposition(stack_a);
	//ft_printf("before target pos is: %i\n", target_pos);
	while (temp_a)
	{
		if (temp_a->data > from_b && temp_a->data < target_value)
		{
			target_pos = temp_a->position;
			target_value = temp_a->data;
			//ft_printf("within loop target pos is %i\n", temp_a->position);
		}
		temp_a = temp_a->next;
	}
	// ft_printf("target pos is: %i\n", target_pos);
	// ft_printf("target value is: %i\n", target_value);
	// ft_printf("value at the top og b is: %i\n", from_b);
	return (target_pos);
}

t_list	*rotate_and_add(t_list **stack_a, t_list **stack_b, int target_position)
{
	int mid;

	mid = (list_length(*stack_a) / 2);
	//ft_printf("target position is: %i\n", target_position);
	// ft_printf("mid value is: %i\n", mid);
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
	// ft_printf("stack_a position is: %i\n", (*stack_a)->position);
	// ft_printf("target position is:%i\n", target_position);
	if ((*stack_a)->position == target_position)
	{
		push(stack_b, stack_a, "pa");
	}
		// ft_printf("**_______ AFTER R&A STACK A IS: _______**\n");
		// print_stack(*stack_a);
		// ft_printf("**_______ END OF STACK A _______**\n");
	return(*stack_a);
}

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
	//ft_printf("lowest value is: %i\n", lowest_value);
//	ft_printf("lowest position is: %i\n", lowest_position);
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
// int	get_idx(int len)
// {
// 	int idx;
// 	ft_printf("get indexx??\n");
// 	idx = 0;
// 	if (len == 4)
// 		idx = 3;
// 	if (len == 5)
// 		idx = 3;
// 	else if (len < 11)
// 		idx = (len / 2);
// 	else if (len < 101)
// 		idx = (len / 4);
// 	else if (len < 501)
// 		idx = (len / 10);
// 	ft_printf("%i\n", idx);
// 	return(idx - 1);
// }

int	bubblesort(t_list *stack, int len)
{
	int array[len];
	int i;
	int j;
	int temp;
	//int idx;

	i = 0;
	while(stack)
	{
		array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	j = 0;
	//ft_printf("*** list len is : %i ***\n", len);
	while (j < len)
	{
		//ft_printf("array %i is %i\n", j, array[j]);
		j++;
	}
	j = 0;
	while (j < (len-1))
	{
		i = 0;
		while (i < (len-1))
		{
			if(array[i] > array[i+1])
			{
				ft_swap(&array[i], &array[i+1]);
				//ft_printf("we swapped %i + %i\n", array[i], array[i+1]);
			}
			i++;
		}
		j++;
	}
	//idx = len / 2;
	//ft_printf("index is at %i as %i\n", idx, array[idx]);
	// i = 0;
	//ft_printf("\n");
	// while(i < len)
	// {
	// 	ft_printf("sorted array: %i\n", array[i]);
	// 	i++;
	// }
	i = len / 2;
	temp = array[i];
	// ft_printf("\n");
	// ft_printf("*** sort limit for quicksort is %i ***\n", array[i]);
	return (temp);
}
