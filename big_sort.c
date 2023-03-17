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
	//t_list *temp;

	if (!stack_a)
		return (0);
	stack_b = 0;
	//temp = stack_b;
	chunk = 1;
	len = list_length(stack_a);
	limit = bubblesort(stack_a, len);
	//mid = bubblesort(stack_a, len);
	preprocess(&stack_a, &stack_b, limit, len, chunk);
	process_b(&stack_b, &stack_a, limit, len, chunk);
	// while(if_sorted(stack_a) != 0)
	// {
	// 	//process_a(stack_a, stack_b, limit, len, chunk);
	// 	process_b(stack_b, stack_a, limit, len, chunk);
	// }
	ft_printf("2. security check for stack_a\n");
	print_stack(stack_a);
	while(stack_b)
	{
		ft_printf("chunk %i\n", stack_b->chunk);
		stack_b = stack_b->next;
	}
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
	int push_back;
	t_list *temp;

	temp = *stack_a;
	push_back = 0;
	if (stack_len > 3)
	{
		while (push_back < stack_len / 2) // && stack_len > 4
		{
			if ((*stack_a)->data < limit)
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
	if (stack_len >= 3)
	{
		if (stack_len == 3)
			mini_sort(*stack_a);
		if (stack_len == 2)
		{
			if ((*stack_a)->data > (*stack_a)->next->data)
				swap(stack_a, "sa");
		}
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

// t_list *process_a(t_list **stack_a, t_list **stack_b, int limit, int stack_len, int chunk)
// {
// 	int push_back;
// 	t_list	*temp;

// 	temp = *stack_a;
// 	push_back = 0;
// 	if (stack_len > 3)
// 	{
// 		while (push_back < stack_len / 2) // && stack_len > 4
// 		{
// 			if ((*stack_b)->data < limit)
// 			{
// 				(*stack_b)->chunk = chunk;
// 				push(stack_b, stack_a, "pa");
// 				push_back++;
// 			}
// 			else
// 			{
// 				rotate(stack_a, "ra");
// 			}
// 		}
// 	}	
// 	ft_printf("_____ STACK A IS LIKE THIS: _____\n");
// 	print_stack(*stack_a);
// 	ft_printf("\n");
// 	ft_printf("_____ STACK B IS LIKE THIS: _____\n");
// 	print_stack(*stack_b);
// 	ft_printf("\n");
// 	if (stack_len > 0)
// 	{
// 		ft_printf("\n");
// 		ft_printf("___ NEW SORTCYCLE FOR A ___\n");
// 		ft_printf("\n");
// 		chunk++;
// 		ft_printf("chunk to process is %i\n", chunk);
// 		ft_printf("\n");
// 		stack_len = chunk_length(*stack_a, chunk);
// 		limit = bubblesort(*stack_a, stack_len);
// 		process_a(stack_a, stack_b, limit, stack_len, chunk);
// 	}
// 	ft_printf("loopcheck\n");
// 	//print_stack(*stack_a);
// 	//ft_printf("cleared process??\n");
// 	return(temp);
// }

t_list *process_b(t_list **stack_a, t_list **stack_b, int limit, int chunk_len, int chunk)
{
	int push_back;
	int rot_back;
	t_list	*temp;

	temp = *stack_b;
	push_back = 0;
	rot_back = 0;
	ft_printf("seg check\n");
	while (push_back < chunk_len / 2) // && stack_len > 4
	{
		ft_printf("limit for this chunk is %i\n", limit);
		if ((*stack_b)->data > limit)
		{
			ft_printf("seg check2\n");
			//(*stack_b)->chunk = chunk;
			push(stack_b, stack_a, "pa");
			push_back++;
			//ft_printf("___ stack_a updated is: _____\n");
			//print_stack(*stack_a);
		}
		else
		{
			ft_printf("seg check3\n");
			rotate(stack_b, "rb");
			rot_back++;
		}
	}
	ft_printf("rot_back is %i\n", rot_back);

	while (rot_back > 0)
	{
		rev_rotate(stack_b, "rra");
	}
	ft_printf("_____ STACK A IS LIKE THIS: _____\n");
	print_stack(*stack_a);
	ft_printf("\n");
	ft_printf("_____ STACK B IS LIKE THIS: _____\n");
	print_stack(*stack_b);
	ft_printf("\n");
	if (stack_b)
	{
		ft_printf("\n");
		ft_printf("___ NEW SORTCYCLE FOR B ___\n");
		ft_printf("\n");
		chunk--;
		ft_printf("chunk to process is %i\n", chunk);
		ft_printf("\n");
		chunk_len = chunk_length(*stack_a, chunk);
		limit = bubblesort(*stack_b, chunk_len);
		ft_printf("limit is %i\n", limit);
		process_b(stack_a, stack_b, limit, chunk_len, chunk);
	}
	//ft_printf("loopcheck\n");
	//print_stack(*stack_a);
	//ft_printf("cleared process??\n");
	return(temp);
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
