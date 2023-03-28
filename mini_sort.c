/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 07:59:31 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/28 09:23:48 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*mini_sort(t_list **stack)
{
	t_list	*second;
	t_list	*head;
	int		len;
	int		check;

	head = *stack;
	len = list_length(*stack);
	check = if_rev_sorted(*stack);
	second = (*stack)->next;
	if (len == 2 && (head->data > second->data))
		swap(&head, "sa");
	//print_stack(*stack);
	if (len == 3)
		head = sort_3(stack, &second, check);
	// ft_printf("\n");
	//ft_printf("result of minisort is:\n");
	//print_stack(head);
	return (head);
}

t_list	*sort_3(t_list **stack_a, t_list **second, int check)
{
	t_list	*head;

	head = NULL;
	// ft_printf("this is from minisort3\n");
	//ft_printf("check is %i\n", check);
	if (check == 1)
		{
			//ft_printf("we enter the check\n");
			swap(stack_a, "sa");
			rev_rotate(stack_a, "rra");
			head = (*stack_a);
			return (head);
		}
	else if ((*stack_a)->data > (*second)->data && \
		(*stack_a)->data < (*second)->next->data)
			swap(stack_a, "sa");
	else if ((*stack_a)->data > (*second)->data && \
		(*second)->data < (*second)->next->data)
			rotate(stack_a, "ra");
	else if ((*stack_a)->data < (*second)->data && \
	 	(*stack_a)->data < (*second)->next->data && \
		(*second)->data > (*second)->next->data)
	{
	 	swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	else if ((*stack_a)->data < (*second)->data && \
		(*stack_a)->data > (*second)->next->data && \
		(*second)->data > (*second)->next->data)
		rev_rotate(stack_a, "rra");
	head = (*stack_a);
	// ft_printf("stack_a after minisort\n");
	// print_stack(head);
	return (head);
}

