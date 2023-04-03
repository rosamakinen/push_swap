/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:36:09 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/03 09:20:42 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bubblesort(t_list **stack, int len, char *str)
{
	t_list	*temp_s;
	int		*array;
	int		*temp;
	int		i;

	i = 0;
	temp_s = *stack;
	temp = NULL;
	array = (int*)calloc(len, sizeof(int));
	if (array == NULL)
	{
		free(array);
		return (0);
	}
	while (temp_s)
	{
		array[i] = temp_s->data;
		temp_s = temp_s->next;
		i++;
	}
	temp = do_bubble_swap(array, len);
	if (ft_strcmp(str, "limit") == 0)
		i = len / 2;
	else if (ft_strcmp(str, "order") == 0)
		positions_for_radix(array, len, stack);
	else if (ft_strcmp(str, "smallest") == 0)
		i = 0;
	free(array);
	return (temp[i]);
}

int	*do_bubble_swap(int *array, int len)
{
	int	j;
	int	i;

	j = 0;
	while (j < (len - 1))
	{
		i = 0;
		while (i < (len - 1))
		{
			if (array[i] > array[i + 1])
				ft_swap(&array[i], &array[i + 1]);
			i++;
		}
		j++;
	}
	return (array);
}

t_list	*get_pos_radix(t_list **stack)
{
	int	len;

	len = list_length(*stack);
	bubblesort(stack, len, "order");
	return (*stack);
}

void	positions_for_radix(int *array, int len, t_list **stack)
{
	int		j;
	t_list	*temp_s;

	j = 0;
	temp_s = *stack;
	while (array[j])
	{
		while (temp_s && j < len)
		{
			if (array[j] == temp_s->data)
				temp_s->position = j;
			temp_s = temp_s->next;
		}
		temp_s = *stack;
		j++;
	}
}
