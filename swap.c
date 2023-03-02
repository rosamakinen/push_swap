/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:11 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/02 12:08:14 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, char *print)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*head) == NULL)
		return ;
	temp = *head;
	temp2 = temp->next;
	if (temp->next)
	{
		// temp = list->next;
		// list->next = list->next->next; //temp->next;
		// temp->next = list;

		// 	temp_list = stack_a->next;
		// 	stack_a->next = stack_a->next->next;
		// 	temp_list->next = stack_a;

		// temp = (*head)->next;
		// (*head)->next = (*head)->next->next;
		// temp->next = *head;
		*head = (*head)->next;
		temp->next = temp2->next;
		temp2->next = temp;


	}
	ft_printf("%s\n", print);
}

void swap_both(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(&stack_a, NULL);
		swap(&stack_b, NULL);
		ft_printf("ss\n");
	}
}
//-------------------
// t_list	*temp;
// 	t_list	*list;

// 	if ((*head) == NULL)
// 		return ;
// 	list = *head;
// 	if (list->next)
// 	{
// 		ft_printf("can we get here\n");
// 		temp = list->next;
// 		list = list->next->next; //temp->next;
// 		temp->next = list;
// ------------------
//
// t_list	*swap_b2(t_list *stack_b, int print)
// {
// 	int len;
// 	//int	temp;
// 	t_list *temp_list;

// 	len = list_length(stack_b);
// 	temp_list = 0;
// 	//ft_printf("len is %i\n", len);
// 	if (len > 1)
// 	{
// 		// temp = stack_a->data;
// 		// stack_a->data = stack_a->next->data;
// 		// stack_a->next->data = temp;

// 		temp_list = stack_b->next;
// 		stack_b->next = stack_b->next->next;
// 		temp_list->next = stack_b;
// 		ft_printf("sb\n");
// 	}
// 	if (print == 0)
// 	{
// 		ft_printf("sa\n");
// 	}
// 	return(temp_list);
// }

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

// t_list	*swap_a2(t_list *stack_a, int print)
// {
// 	int len;
// 	t_list *temp_list;

// 	len = list_length(stack_a);
// 	temp_list = 0;
// 	//ft_printf("len is %i\n", len);
// 	if (len > 1)
// 	{
// 		// temp = stack_a->data;
// 		// stack_a->data = stack_a->next->data;
// 		// stack_a->next->data = temp;

// 		temp_list = stack_a->next;
// 		stack_a->next = stack_a->next->next;
// 		temp_list->next = stack_a;
// 	}
// 	if (print == 0)
// 	{
// 		ft_printf("sa\n");
// 	}
// 	return(temp_list);
// }

