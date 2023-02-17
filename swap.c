/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:11 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/17 13:28:04 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

t_list	*push_swap(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	head = 0;
	stack_b = 0;
	if(stack_a)
		head = swap_a(stack_a);
	ft_printf("is this not okay\n");
	return(head);
}


t_list	*swap_a(t_list *stack_a)
{
	int len;
	//int	temp;
	t_list *temp_list;

	len = list_length(stack_a);
	temp_list = 0;
	ft_printf("len is %i\n", len);
	if (len > 1)
	{
		// temp = stack_a->data;
		// stack_a->data = stack_a->next->data;
		// stack_a->next->data = temp;

		temp_list = stack_a->next;
		stack_a->next = stack_a->next->next;
		temp_list->next = stack_a;
		ft_printf("sa");
	}
	return(temp_list);
}

// void	swap_a2(t_list **head)
// {
// 	t_list	*temp;
// 	t_list	*list;

// 	list = *head;
// 	if (list->next)
// 	{
// 		temp = list->next;
// 		list = temp->next; //list->next->next;
// 		temp->next = list;
// 	}
// }

t_list	*swap_b(t_list *stack_a)
{
	int len;
	//int	temp;
	t_list *temp_list;

	len = list_length(stack_a);
	temp_list = 0;
	ft_printf("len is %i\n", len);
	if (len > 1)
	{
		// temp = stack_a->data;
		// stack_a->data = stack_a->next->data;
		// stack_a->next->data = temp;

		temp_list = stack_a->next;
		stack_a->next = stack_a->next->next;
		temp_list->next = stack_a;
		ft_printf("sb");
	}
	return(temp_list);
}

// void	swap_b2(t_list **head)
// {
// 	t_list	*temp;
// 	t_list	*list;

// 	list = *head;
// 	if (list->next)
// 	{
// 		temp = list->next;
// 		list = temp->next; //list->next->next;
// 		temp->next = list;
// 	}
// }

// void *swap_both(t_list *stack_a, t_list *stack_b)
// {
// 	if (stack_a && stack_b)
// 	{
// 		stack_a = swap_a(stack_a);
// 		stack_b = swap_b(stack_b);
// 	}
// 	return(stack_a);
// }
