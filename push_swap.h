/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:26:21 by rmakinen          #+#    #+#             */
/*   Updated: 2023/02/06 10:18:37 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"
#include "./libft/includes/get_next_line.h"
#include <stdlib.h> //for malloc & free etc
#include <unistd.h> //for read & write

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list	*fill_stack(t_list *stack, char *argument);
t_list	*add_new(int new_data);
t_list	*add_top(t_list *top, int new_data);
int	check_for_nonint(char *argument);
int	check_for_duplicates(int data, t_list *stack);

#endif
