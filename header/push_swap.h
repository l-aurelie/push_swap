/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:33:41 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 20:11:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dlist
{
	void			*data;
	enum
	{
		RANDOM = 0,
		PIVOT,
		SORTED,
	}	e_type;
	int				bottom;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

typedef struct s_pivot
{
	long	min;
	long	max;
	long	intervall;
}				t_pivot;

/*
** PUSH_SWAP
*/
int		main(int argc, char **argv);
void	push_swap(t_dlist **stack_a, t_dlist **stack_b);
void	create_stack(t_dlist **stack_a, int argc, char **argv);
int		has_double(t_dlist *list);
int		str_is_number(char *str);
/*
** SORT
*/
void	little_sort(t_dlist **stack_a, t_dlist **stack_b);
void	sort_three(t_dlist **stack_a, t_dlist **stack_b);
void	sort_a(t_dlist **stack_a, t_dlist **stack_b);
void	sort_b(t_dlist **stack_a, t_dlist **stack_b);
/*
** QUICK SORT
*/
int		pivot_dispatch_finished(t_dlist *stack, t_dlist *pivot, char c);
void	dispatch_a(t_dlist **stack_a, t_dlist **stack_b, int pivot_treat,
			int need_clean);
void	dispatch_b(t_dlist **stack_a, t_dlist **stack_b, int pivot_treat,
			int need_clean);
int		should_clean(t_dlist *stack);
void	clean_after_sort(t_dlist **stack_a, t_dlist **stack_b, int need_clear,
			char c);
/*
** FIND PIVOT
*/
t_dlist	*find_pivot(t_dlist *stack);
void	search_midline(t_pivot *piv, t_dlist *stack, t_dlist **pivot, char c);
int		lower_greater_midline(t_dlist *stack, t_dlist *pivot_tested);
int		calculate_medium_intervall(t_dlist *stack);
t_dlist	*search_elem_bt_two_val(t_dlist *stack, long min, long max);
/*
** OPTI
*/
void	push_elem_front(t_dlist **stack_a, t_dlist **stack_b, t_dlist *elem,
			char c);
int		optimisation(t_dlist **stack_a, t_dlist **stack_b, char c);
void	insertion_sort_b(t_dlist **stack_a, t_dlist **stack_b);
void	insertion_sort_a(t_dlist **stack_a, t_dlist **stack_b);
int		pivot_placed_low(t_dlist *stack, t_dlist *elem);
/*
** MOVE
*/
void	swap(t_dlist *stack);
void	push(t_dlist **stack_from, t_dlist **stack_to);
void	rotate(t_dlist **stack);
void	reverse_rotate(t_dlist **stack);
/*
** MOVE A
*/
void	reverse_rotate_a(t_dlist **stack_a, t_dlist **stack_b, int print);
void	rotate_a(t_dlist **stack_a, t_dlist **sstack_b, int print);
void	push_a(t_dlist **stack_a, t_dlist **stack_b, int print);
void	swap_a(t_dlist **stack_a, t_dlist **stack_b, int print);
/*
** MOVE B
*/
void	swap_b(t_dlist **stack_a, t_dlist **stack_b, int print);
void	push_b(t_dlist **stack_a, t_dlist **stack_b, int print);
void	rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print);
void	reverse_rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print);
/*
** SORT UTILS 1
*/
int		sorting_size(t_dlist *lst);
t_dlist	*find_max(t_dlist *stack);
t_dlist	*find_sorting_max(t_dlist *stack);
t_dlist	*find_min(t_dlist *stack);
t_dlist	*find_sorting_min(t_dlist *stack);
/*
** SORT UTILS 2
*/
int		calculate_medium(t_dlist *stack);
int		is_ascending_sort(t_dlist *list);
int		ascending_part(t_dlist *list);
int		is_descending_sort(t_dlist *list);
int		descending_part(t_dlist *list);
/*
** LIST UTILS
*/
void	ft_list_push_back(t_dlist **begin_list, void *data);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **alst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **alst, t_dlist *new);
t_dlist	*ft_create_elem(void *data);
/*
** LIB UTILS
*/
int		dlist_size(t_dlist *lst);
void	ft_free_stack(t_dlist *begin_list);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_abs(int x);
#endif
