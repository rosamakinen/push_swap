/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:01:43 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/03 11:47:54 by rmakinen         ###   ########.fr       */
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
			write(2, "Error\n", 7);
			exit (1);
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
		write(2, "Error\n", 7);
		exit (1);
	}
	return(flag);
}

int	check_for_range(int data)
{
	int flag;
	flag= 0;
	//ft_printf("atoi returns %i\n", data); //
		if (data == -1 || data == -2)
			{
				write(2, "Error\n", 7);
				exit (1);
			}
	return (flag);
}

int	list_length(t_list *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	chunk_length(t_list *stack, int chunk)
{
	int	len;

	len = 0;
	while (stack->chunk == chunk)
	{
		len++;
		stack = stack->next;
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
