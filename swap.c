/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:25:11 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/01 09:33:24 by rmakinen         ###   ########.fr       */
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
		*head = (*head)->next;
		temp->next = temp2->next;
		temp2->next = temp;
	}
	ft_printf("%s\n", print);
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_b)
	{
		swap(&stack_a, NULL);
		swap(&stack_b, NULL);
		ft_printf("ss\n");
	}
}
