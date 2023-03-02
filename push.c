/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:29:26 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/02 11:55:51 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from_head, t_list **to_head, char *print)
{
	t_list	*to_temp;
	t_list	*from_temp;

	from_temp = *from_head;
	to_temp = *to_head;
	if (!from_temp)
		return ;
	if (from_temp && !to_temp)
	{
		*from_head = from_temp->next;
		from_temp->next = NULL;
		*to_head = from_temp;
	}
	else
	{
		*from_head = from_temp->next;
		from_temp->next = to_temp;
		*to_head = from_temp;
	}
	if (print)
		ft_printf("%s", print);
}
