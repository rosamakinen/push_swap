/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:18:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/01 14:43:22 by rmakinen         ###   ########.fr       */
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
	// if (len == 2)
	// 	head = sort_2(stack_a);
	if (len == 3)
		head = mini_sort(stack_a);
	// if (len < 6)
	// 	head = fucking_sort(stack_a);
	// if (len > 5)
	// 	head = big_sort();
	return (head);
}

t_list	*mini_sort(t_list *head_a)
{
	t_list *temp;

	temp = 0;
	if (head_a->data > head_a->next->data)
	{
		//swap(&head_a, "sa");
		// rotate(&head_a, "ra");
		rev_rotate(&head_a, "rra");
	}
	return (head_a);
}
