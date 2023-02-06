/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:33:51 by rmakinen          #+#    #+#             */
/*   Updated: 2023/01/30 08:18:40 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*add_new(int new_data)
// {
// 	t_list *new_node;

// 	new_node = (t_list *) malloc(sizeof(t_list));
// 		if (new_node == NULL)
// 			return (NULL);
// 	new_node->data = new_data;
// 	new_node->next = NULL;

// 	return (new_node);
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*node;

// 	node = (t_list *) malloc(sizeof(t_list));
// 	if (node == NULL)
// 		return (NULL);
// 	if (node)
// 	{
// 		node->content = content;
// 	}
// 	node->next = NULL;
// 	return (node);
// }

void	fill_stack(char *argument)
{
	char **array = NULL;
	int	i;

	i = 0;
	array = ft_split(argument, ' ');
	while (array[i] != '\0')
	{
		ft_atoi(array[i]);
		ft_printf("array %d is %s\n", i, array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		ft_printf("[argv %d] %s\n", i, argv[i]);
		fill_stack(argv[i]);
		i++;
	}
	return (0);
}
