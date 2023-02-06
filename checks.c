/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:01:43 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/06 16:08:29 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(int data, t_list *stack)
{
	int	flag;
	flag = 0;
	while (stack)
	{
		if (stack->data == data)
		{
			flag = 1;
			write(2, "Error with dupliacets\n", 23);
			exit (0);
		}
		stack = stack->next;
	}
	return (flag);
}

int	check_for_nonint(char *argument)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (argument[i] != '\0')
	{
		if ((argument[i] >= 48 && argument[i] <= 57) || argument[i] == ' ' || argument[i] == '\t')
			flag = 0;
		i++;
	}
	if (flag == 1)
	{
		write(2, "Error with non int\n", 20);
		exit (0);
	}
	return(flag);
}

int	check_for_bigger(int data);
{
	int flag;
	flag= 0;
		if (data == -1 || data == 0)
			{
				write(2, "Error with too big int\n", 24);
				exit (0);
			}
	return (flag)
}
