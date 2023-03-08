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

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b, int check)
{
	int	len;
	int idx;
	int i;
	t_list *temp;

	if (!stack_a)
		return (0);
	check = 0;
	stack_b = 0;
	i = 0;
	temp = 0;
	len = list_length(stack_a);
	idx = bubblesort(stack_a, len);
	//mid = bubblesort(stack_a, len);
	if (idx)
	{
		temp = process_a(stack_a, stack_b, idx, len);
	}
	//print_stack(stack_b);
	//print_stack(temp);
	//i = 0;
	// while(div > i)
	// {
	// 	mid = bubblesort(stack_b, len);
	// 	process_b
	// }
	return (stack_a);
}

t_list *process_a(t_list *stack_a, t_list *stack_b, int idx, int stack_len)
{
		int count;
	int len;
	int push_back;

	count = 0;
	push_back = 0;
	while (count < stack_len)
	{
		if (stack_a->data < idx)
		{
			push(&stack_a, &stack_b, "pb");
			push_back++;
			count++;
		}
		len = list_length(stack_a);
		if (stack_a->data >= idx && len > 3)
		{
			rotate(&stack_a, "ra");
			count++;
		}
		else
			break ;
	}
	ft_printf("_____ STACK A IS LIKE THIS: _____\n");
	print_stack(stack_a);
	ft_printf("\n");
	ft_printf("_____ STACK B IS LIKE THIS: _____\n");
	print_stack(stack_b);
	ft_printf("\n");
	ft_printf("cleared process??\n");
	if (len <= 3)
		mini_sort(stack_a);
	while (push_back > 0)
	{
		push(&stack_b, &stack_a, "pa");
		push_back--;
	}
	return(stack_a);
}

int	get_idx(int len)
{
	int idx;
	ft_printf("get indexx??\n");
	idx = 0;
	if (len == 4)
		idx = 3;
	if (len == 5)
		idx = 3;
	else if (len < 11)
		idx = (len / 2);
	else if (len < 101)
		idx = (len / 4);
	else if (len < 501)
		idx = (len / 10);
	ft_printf("%i\n", idx);
	return(idx - 1);
}

int	bubblesort(t_list *stack, int len)
{
	int array[len];
	int i;
	int j;
	int idx;

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
	idx = get_idx(len);
	ft_printf("index is at %i as %i\n", idx, array[idx]);
	i = 0;
	while(i < len)
	{
		ft_printf("sorted array: %i is %i\n", i, array[i]);
		i++;
	}
	return (array[idx]);
}
