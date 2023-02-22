/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:11 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/22 11:59:18 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// t_list	*push_swap(t_list *stack_a, t_list *stack_b)
// {
// 	int	print;

// 	print = 1;
// 	stack_b = 0;
// 	if(stack_a)
// 	{
// 		print = 0;
// 		swap_a(&stack_a, print);
// 	}
// 	// if(stack_b)
// 	// {
// 	// 	print = 0;
// 	// 	swap_b(&stack_b, print)
// 	// }
// 	//ft_printf("is this not okay\n");
// 	swap_both(&stack_a, &stack_b)
// 	return(head);
// }

// t_list	*swap_a2(t_list *stack_a)
// {
// 	int len;
// 	//int	temp;
// 	t_list *temp_list;

// 	len = list_length(stack_a);
// 	temp_list = 0;
// 	ft_printf("len is %i\n", len);
// 	if (len > 1)
// 	{
// 		// temp = stack_a->data;
// 		// stack_a->data = stack_a->next->data;
// 		// stack_a->next->data = temp;

// 		temp_list = stack_a->next;
// 		stack_a->next = stack_a->next->next;
// 		temp_list->next = stack_a;
// 		ft_printf("sa");
// 	}
// 	return(temp_list);
// }

void	swap_a(t_list **head, int print)
{
	t_list	*temp;
	t_list	*list;

	if (!*head || !print)
		return (0);
	list = *head;
	if (list->next)
	{
		temp = list->next;
		list = list->next->next; //temp->next;
		temp->next = list;
	}
	if (print == 0)
	{
		ft_printf("sa\n");
	}
	// while (list->next)
	// {
	// 	// ft_printf("issue not getting here?\n");
	// 	ft_printf("data %i\n", list->data);
	// 	list = list->next;
	// }
	//ft_printf("list node is: %i\n", list->data);
}

// t_list	*swap_b2(t_list *stack_a)
// {
// 	int len;
// 	//int	temp;
// 	t_list *temp_list;

// 	len = list_length(stack_a);
// 	temp_list = 0;
// 	ft_printf("len is %i\n", len);
// 	if (len > 1)
// 	{
// 		// temp = stack_a->data;
// 		// stack_a->data = stack_a->next->data;
// 		// stack_a->next->data = temp;

// 		temp_list = stack_a->next;
// 		stack_a->next = stack_a->next->next;
// 		temp_list->next = stack_a;
// 		ft_printf("sb");
// 	}
// 	return(temp_list);
// }

void	swap_b(t_list **head, int print)
{
	t_list	*temp;
	t_list	*list;

	if (!*head || !print)
		return (0);
	list = *head;
	if (list->next)
	{
		temp = list->next;
		list = list->next->next; //temp->next;
		temp->next = list;
	}
	if (print == 0)
	{
		ft_printf("sb");
	}
}

void swap_both(t_list *stack_a, t_list *stack_b)
{
	int print;

	print = 1;
	if (stack_a && stack_b)
	{
		swap_a(&stack_a, print);
		swap_b(&stack_b, print);
		ft_printf("ss");
	}
}
