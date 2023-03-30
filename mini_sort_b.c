/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:07:51 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/30 13:51:58 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort_b(t_list **stack, int chunk_flag)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	head = *stack;
	if (chunk_flag == 0)
		len = list_length(*stack);
	if (chunk_flag > 0)
		len = chunk_flag;
	second = (*stack)->next;
	ft_printf("befor minisort of b:\n");
	ft_printf("list len %i\n", len);
	print_stack(*stack);
	check = if_sorted(*stack);
	ft_printf("head->dta %i\n", head->data);
	ft_printf("second->dta %i\n", second->data);
	if (len == 2 && (head->data < second->data))
		swap(&head, "sb");
	if (len == 3)
		head = rev_sort_3(stack, &second, check);
	return (head);
}

t_list	*rev_sort_3(t_list **stack_b, t_list **second, int check)
{
	t_list	*head;

	head = NULL;
	if (check == 0)
		{
			swap(stack_b, "sb");
			rev_rotate(stack_b, "rrb");
			head = (*stack_b);
			return (head);
		}
	if ((*stack_b)->data < (*second)->data && \
		(*stack_b)->data > (*second)->next->data)
			swap(stack_b, "sb");
	else if ((*stack_b)->data < (*second)->data && \
		(*second)->data > (*second)->next->data)
			rotate(stack_b, "rb");
	else if ((*stack_b)->data > (*second)->data && \
	 	(*stack_b)->data > (*second)->next->data && \
		(*second)->data < (*second)->next->data)
	{
	 	swap(stack_b, "sb");
		rotate(stack_b, "rb");
	}
	else if ((*stack_b)->data > (*second)->data && \
		(*stack_b)->data < (*second)->next->data && \
		(*second)->data < (*second)->next->data)
		rev_rotate(stack_b, "rrb");
	head = (*stack_b);
	return (head);
}
