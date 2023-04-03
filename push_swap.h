/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:26:21 by rmakinen          #+#    #+#             */
/*   Updated: 2023/04/01 15:36:19 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include "./libft/includes/get_next_line.h"
# include <stdlib.h> //for malloc & free etc
# include <unistd.h> //for read & write

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
t_list	*add_bottom(t_list *list, int new_data);
t_list	*sort(t_list *stack_a, t_list *stack_b);
t_list	*mini_sort(t_list **stack);
t_list	*mini_sort_b(t_list **stack, int chunk_flag);
t_list	*rev_sort_3(t_list **stack_a, t_list **second, int check);
t_list	*big_sort_initializer(t_list *stack_a, t_list *stack_b);
t_list	*sort_3(t_list **stack_a, t_list **second, int check);
t_list	*preprocess(t_list **stack_a, t_list **stack_b, int limit, int len);
t_list	*rotate_and_add(t_list **stack_a, t_list **stack_b, int target_pos);
t_list	*deal_with_it(t_list **stack_a, t_list **stack_b);
t_list	*get_pos_radix(t_list **stack);
t_list	*search_from_top(t_list **s_a, t_list **s_b, int limit, int len);
t_list	*shift(t_list **stack_a, t_list **stack_b, int bit, int len);

int		check_for_nonint(char *argument, int flag);
int		check_for_duplicates(int data, t_list *stack, int flag);
int		check_for_range(int data, char *str, int flag);
int		list_length(t_list *stack);
int		if_sorted(t_list *stack);
int		if_rev_sorted(t_list *stack);
int		bubblesort(t_list **stack, int len, char *str);
int		chunk_length(t_list *stack, int chunk);
int		find_end_position(t_list **stack_a, t_list **top_at_b, int target);
int		reorder_a(t_list **stack_a);
int		find_lowest_position(t_list **stack_a, int lowest_value);
int		*do_bubble_swap(int *array, int len);

void	pushback(t_list **stack_b, t_list **stack_a);
void	is_rev_sorted(t_list *stack_a, t_list *stack_b);
void	positions_for_radix(int *array, int len, t_list **stack);
void	setting_(int array, int len, t_list **stack);
void	process_a(int push_back, int limit, t_list **stack_a, t_list **stack_b);
void	do_operations(int len, t_list **stack_b);
void	print_stack(t_list *head); // PRINT STACK!!! REMOVE??
void	stack_reposition(t_list **head);
void	swap(t_list **head, char *print);
void	swap_both(t_list *stack_a, t_list *stack_b);
void	rotate(t_list **head, char *print);
void	rotate_both(t_list **head_a, t_list **head_b);
void	rev_rotate(t_list **head, char *print);
void	rev_rotate_both(t_list **head_a, t_list **head_b);
void	push(t_list **from_head, t_list **to_head, char *print);
void	free_stack(t_list **stack);
void	free_array(char ***array);
void	exit_and_free(char **array, t_list *stack);

#endif
