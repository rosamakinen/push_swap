/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:12:01 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/08 15:20:03 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int limit;
	int chunk;
	int target_position;
	int test;

	if (!stack_a)
		return (0);
	stack_b = 0;
	chunk = 1;
	len = list_length(stack_a);
	limit = bubblesort(stack_a, len);
	test = len;
	preprocess(&stack_a, &stack_b, limit, len, chunk);
	ft_printf("\n");
	ft_printf("**_______ PREPROCESS OK _______**\n");
	ft_printf("\n");
	while (test)
	{
		ft_printf("segcheck\n");
		target_position = find_end_position(&stack_a, &stack_b);
		rotate_and_add(&stack_a, &stack_b, target_position);
		test--;
	}
	//process_b(&stack_a, &stack_b, limit, len, chunk);
	// while(if_sorted(stack_a) != 0)
	// {
	// 	//process_a(stack_a, stack_b, limit, len, chunk);
	// 	process_b(stack_b, stack_a, limit, len, chunk);
	// }
	ft_printf("2. security check for stack_a\n");
	print_stack(stack_a);
	// while(stack_b)
	// {
	// 	ft_printf("chunk %i\n", stack_b->chunk);
	// 	stack_b = stack_b->next;
	// }
	//mini_sort(stack_a);
	// while(stack_b)
	// {


	// }

	//print_stack(stack_b);
	//print_stack(temp);
	return (stack_a);
}

t_list *preprocess(t_list **stack_a, t_list **stack_b, int limit, int stack_len, int chunk)
{
	int		push_back;
	t_list *temp;

	temp = *stack_a;
	push_back = 0;
	if (stack_len > 3)
	{
		while (push_back < (stack_len / 2) && stack_len >= 4) // && stack_len > 4
		{
			if ((*stack_a)->data <= limit)
			{
				(*stack_a)->chunk = chunk;
				push(stack_a, stack_b, "pb");
				push_back++;
			}
			else
			{
				rotate(stack_a, "ra");
			}
		}
	}	
	if (stack_len <= 3)
	{
			mini_sort(stack_a);
	}
	ft_printf("_____ STACK A IS LIKE THIS: _____\n");
	print_stack(*stack_a);
	ft_printf("\n");
	ft_printf("_____ STACK B IS LIKE THIS: _____\n");
	print_stack(*stack_b);
	ft_printf("\n");
	if (stack_len > 3)
	{
		ft_printf("\n");
		ft_printf("___ NEW SORTCYCLE FOR A ___\n");
		ft_printf("\n");
		chunk++;
		ft_printf("___ NEW CHUNK DIVISION FOR A, chunk %i ___\n", chunk);
		stack_len = list_length(*stack_a);
		limit = bubblesort(*stack_a, stack_len);
		preprocess(stack_a, stack_b, limit, stack_len, chunk);
	}
	//ft_printf("loopcheck\n");
	//print_stack(*stack_a);
	//ft_printf("cleared process??\n");
	return(temp);
}

int	find_end_position(t_list **stack_a, t_list **top_at_b)
{
	t_list *temp_a;
	int 	from_b;
	int		target_pos;


	temp_a = (*stack_a);
	from_b = (*top_at_b)->data;
	target_pos = 2147483647;
	stack_reposition(stack_a);
	ft_printf("target pos is: %i\n", target_pos);
	while (temp_a->next != NULL)
	{
		if (temp_a->data > from_b && temp_a->data < target_pos)
		{
			target_pos = temp_a->position;
			ft_printf("segcheck2\n");
			temp_a = temp_a->next;
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
	if (mid < target_position)
	{
		while ((*stack_a)->position != target_position)
			rev_rotate(stack_a, "rra");
	}
	if ((*stack_a)->position == target_position)
	{
		push(stack_b, stack_a, "pa rotate && add");
	}
	return(*stack_a);
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
	//int idx;

	i = 0;
	while(stack)
	{
		array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	j = 0;
	ft_printf("*** list len is : %i ***\n", len);
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
	i = 0;
	ft_printf("\n");
	while(i < len)
	{
		ft_printf("sorted array: %i\n", array[i]);
		i++;
	}
	i = len / 2;
	ft_printf("\n");
	ft_printf("*** sort limit for quicksort is %i ***\n", array[i]);
	return (array[i]);
}
