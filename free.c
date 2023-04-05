/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:28:18 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/04 11:32:40 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;

	temp = (*stack);
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
}

void	free_array(char ***array)
{
	int		i;
	char	**temp;

	temp = *array;
	i = 0;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(*array);
}

void	exit_and_free(char **array, t_list *stack)
{
	write(2, "Error\n", 6);
	free_array(&array);
	free_stack(&stack);
	exit (1);
}
