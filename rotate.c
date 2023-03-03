/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:28 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/03 14:06:02 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head, char *print)
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
	if (print)
		ft_printf("%s\n", print);
}

void	rev_rotate(t_list **head, char *print)
{
	t_list	*temp;
	t_list	*last;
	t_list	*second_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	last = *head;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = temp;
	*head = last;
	if (print)
		ft_printf("%s\n", print);
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate(head_a, NULL);
	rotate(head_b, NULL);
	ft_printf("rr\n");
}

void	rev_rotate_both(t_list **head_a, t_list **head_b)
{
	rev_rotate(head_a, NULL);
	rev_rotate(head_b, NULL);
	ft_printf("rrr\n");
}
