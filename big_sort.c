/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:12:01 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/07 07:54:07 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b, int check)
{
	int	mid;
	int	len;

	if (!stack_a)
		return (0);
	stack_b = 0;
	check = 0;
	len = list_length(stack_a);
	mid = bubblesort(stack_a, len);
	ft_printf("mid number is: %i", mid);
	return (stack_a);
}

int	bubblesort(t_list *stack, int len)
{
	int	mid;
	int array[len];
	int i;

	i = 0;
	while(stack)
	{
		array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	while (array[i])
	{
		if(array[i] > array[i+1])
		{
			ft_swap(&array[i], &array[i+1]);
			i++;
		}
		i++;
	}
	i = len / 2;
	mid = array[i];
	i = 0;
	while(array[i])
	{
		ft_printf("sorted array: %i\n", array[i]);
		i++;
	}
	return (mid);
}
