/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:28 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/22 15:07:01 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **head, int print)
{
	t_list	*temp;
	t_list	*last;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = temp->next;
	temp->next = NULL;
	last->next = temp;
	if (print == 0)
		ft_printf("ra")
}

void	rotate_b(t_list **head, int print)
{
	t_list	*temp;
	t_list	*last;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = temp->next;
	temp->next = NULL;
	last->next = temp;
	if (print == 0)
		ft_printf("rb");
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	int print;

	print = 1;
	rotate_a(&head_a, print);
	rotate_b(&head_b, print);
}

