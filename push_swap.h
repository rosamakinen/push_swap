/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:26:21 by rmakinen          #+#    #+#             */
/*   Updated: 2023/03/06 12:33:39 by rmakinen         ###   ########.fr       */
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
	int				position;
	int				chunk;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list	*fill_stack(t_list *stack, char *argument);
t_list	*add_new(int new_data);
//t_list	*add_top(t_list *top, int new_data);
t_list	*sort(t_list *stack_a, t_list *stack_b);
t_list	*mini_sort(t_list *stack_a, t_list *stack_b);
t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b, int check);
t_list	*sort_3(t_list *stack_a, t_list *second, int check);
int	check_for_nonint(char *argument);
int	check_for_duplicates(int data, t_list *stack);
int	check_for_range(int data);
int	list_length(t_list *stack);
int	if_sorted(t_list *stack);
int	if_rev_sorted(t_list *stack);
int	bubblesort(t_list *stack, int len);

void	print_stack(t_list *head); // PRINT STACK!!! REMOVE??
void	stack_reposition(t_list **head);
void	swap(t_list **head, char *print);
void	swap_both(t_list *stack_a, t_list *stack_b);
void	rotate(t_list **head, char *print);
void	rotate_both(t_list **head_a, t_list **head_b);
void	rev_rotate(t_list **head, char *print);
void	rev_rotate_both(t_list **head_a, t_list **head_b);
void	push(t_list **from_head, t_list **to_head, char *print);
t_list	*sort_3(t_list *stack_a, t_list *second, int check);
//t_list	*sort_test(t_list *head_a);

#endif
