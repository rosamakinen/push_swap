/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:59:31 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/08 14:30:08 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort(t_list *stack_a)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	len = list_length(stack_a);
	check = if_rev_sorted(stack_a);
	second = stack_a->next;
	head = sort_3(stack_a, second, check);
	if (len == 2 && (head->data > second->data))
			swap(&head, "sa");
	//ft_printf("final result:\n");
	//print_stack(head);
	return (head);
}

t_list	*sort_3(t_list *stack_a, t_list *second, int check)
{
	t_list	*head;

	if (check == 0)
		{
			swap(&stack_a, "sa");
			rev_rotate(&stack_a, "ra");
		}
	if (stack_a->data > second->data && \
		stack_a->data < second->next->data)
			swap(&stack_a, "sa");
	if (stack_a->data > second->data && \
		stack_a->data > second->next->data)
			rotate(&stack_a, "ra");
	if (stack_a->data < second->data && \
		second->data > second->next->data)
	{
		rev_rotate(&stack_a, "rra");
	}
	head = stack_a;
	return (head);
}

