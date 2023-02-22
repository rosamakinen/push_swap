/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:18:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/22 11:58:16 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort(t_list *stack_a, t_list *stack_b)
{
	int	len;
	t_list *head;

	head = 0;
	stack_b = 0;
	len = list_length(stack_a);
	if(len < 4)
	{
		head = mini_sort(stack_a);
	}
	return (head);
}

t_list	*mini_sort(t_list *head_a)
{
	t_list	*temp;
	int	print;

	print = 1;
	temp = head_a;

	if(head_a->data > head_a->next->data)
	{
		print = 0;
		swap_a(&head_a, print);
	}
	return (head_a);
}
