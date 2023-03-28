/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:07:51 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/28 16:32:21 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort_b(t_list **stack)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	head = *stack;
	len = list_length(*stack);
	check = if_sorted(*stack);
	second = (*stack)->next;
	// ft_printf("befor minisort of b:\n");
	// ft_printf("list len %i :\n", len);
	// print_stack(*stack);
	if (len == 2 && (head->data < second->data))
		swap(&head, "sb");
	// ft_printf("after minisort of b:\n");
	// print_stack(*stack);
	if (len == 3)
		head = rev_sort_3(stack, &second, check);
	// ft_printf("\n");
	// ft_printf("result of minisort b is:\n");
	// print_stack(head);
	return (head);
}

t_list	*rev_sort_3(t_list **stack_b, t_list **second, int check)
{
	t_list	*head;

	head = NULL;
	// ft_printf("this is from minisortreverse\n");
	//ft_printf("check is %i\n", check);
	if (check == 0)
		{
			//ft_printf("we enter the check\n");
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
	//ft_printf("segcheck\n");
	return (head);
}
