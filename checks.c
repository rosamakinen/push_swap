/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:01:43 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/29 13:55:25 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(int data, t_list *stack, int flag)
{
	while (stack)
	{
		if (stack->data == data)
		{
			flag = 1;
		}
		stack = stack->next;
	}
	return (flag);
}

int	check_for_nonint(char *argument, int flag)
{
	int	i;

	i = 0;
	while (argument[i] != '\0')
	{
		if ((argument[i] >= 48 && argument[i] <= 57) || argument[i] == ' ' || argument[i] == '\t')
			flag = 0;
		i++;
	}
	return(flag);
}

int	check_for_range(int data, char *str, int flag)
{
	char	*check;

	check = ft_itoa(data);
	if (flag == 0 && (ft_strcmp(str, check) == 0))
	{
		flag = 0;
		free(check);
		return (flag);
	}
	else
		flag = 1;
	free(check);
	return (flag);
}

int	list_length(t_list *stack)
{
	int	len;
	t_list *temp;

	len = 0;
	temp = stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	stack_reposition(t_list **head)
{
	t_list	*temp;
	int	pos;

	temp = *head;
	pos = 1;
	while(temp)
	{
		temp->position = pos;
		temp = temp->next;
		pos++;
	}
}
