/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:18:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/02 12:09:53 by rmakinen         ###   ########.fr       */
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
	if (len < 10)
	{
		head = mini_sort(stack_a);
		// push(&stack_a, &stack_b, "pa\n");
		// ft_printf("a after pa is\n");
		// print_stack(stack_a);
		// ft_printf("b after pa is\n");
		// print_stack(stack_b);
		// push(&stack_a, &stack_b, "pa2\n");
		// ft_printf("a after pa2 is\n");
		// print_stack(stack_a);
		// ft_printf("b after pa2 is\n");
		// print_stack(stack_b);
	}
	return (head);
}

// if we return 0 from the functions, the lists are sorted, otherwise we know they are not.
int	if_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

int	if_rev_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

t_list	*mini_sort(t_list *head_a)
{
	t_list *temp;
	int check;

	check = 0;
	temp = 0;
	check = if_sorted(head_a);
	ft_printf("check is: %i\n", check);
	if (check == 0)
		ft_printf("is sorted\n");
	check = if_rev_sorted(head_a);
	if (check == 0)
		ft_printf("is rev sorted\n");
	if (head_a->data > head_a->next->data)
	{
		swap(&head_a, "sa");
		// rotate(&head_a, "ra");
		// rev_rotate(&head_a, "rra");
	}
	print_stack(head_a);
	return (head_a);
}
