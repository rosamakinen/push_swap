/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:18:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/08 14:01:24 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


t_list	*sort(t_list *stack_a, t_list *stack_b)
{
	int	len;
	int	check;
	t_list *head;

	stack_b = NULL;
	head = NULL;
	len = list_length(stack_a);
	check = if_sorted(stack_a);
	if (len == 1)
		return (0);
	if (check == 0)
	{
		ft_printf("is sorted\n");
		//do something, exit with success??
	}
	// check = if_rev_sorted(stack_a);
	// if (check == 0)
	// {
	// 	ft_printf("is rev sorted\n");
	// 	//do reversal??
	// 	//&& exit with success??
	// }
	if (len <= 3)
	{
		head = mini_sort(&stack_a);
	}
	//ft_printf("--- final result after mini sort ---\n");
	print_stack(head);
	if (len > 3)
	{
		head = big_sort_initializer(stack_a, stack_b);
	}
	//ft_printf("______FINAL RESULT OF STACK_A______\n");
	//print_stack(head);
	return (head);
}

// t_list	*sort_test(t_list *head_a)
// {
// 	t_list *temp;
// 	int check;

// 	check = 0;
// 	temp = 0;
// 	check = if_sorted(head_a);
// 	ft_printf("check is: %i\n", check);
// 	if (check == 0)
// 		ft_printf("is sorted\n");
// 	check = if_rev_sorted(head_a);
// 	if (check == 0)
// 		ft_printf("is rev sorted\n");
// 	if (head_a->data > head_a->next->data)
// 	{
// 		swap(&head_a, "sa");
// 		// rotate(&head_a, "ra");
// 		// rev_rotate(&head_a, "rra");
// 	}
// 	print_stack(head_a);
// 	return (head_a);
// }
