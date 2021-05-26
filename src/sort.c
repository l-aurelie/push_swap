/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:45:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 20:20:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_dlist **stack_a, t_dlist **stack_b)
{
	int		need_clean;
	int		pivot_treat;

	need_clean = 0;
	pivot_treat = 0;
	if (optimisation(stack_a, stack_b, 'b'))
		return ;
	if (sorting_size(*stack_b) <= 10)
		return (insertion_sort_b(stack_a, stack_b));
	dispatch_b(stack_a, stack_b, pivot_treat, need_clean);
	if (!(*stack_b)->next || ((*stack_b)->next && (*stack_b)->next->e_type
			== SORTED))
		(*stack_b)->e_type = SORTED;
}

void	sort_a(t_dlist **stack_a, t_dlist **stack_b)
{
	int	need_clean;
	int	pivot_treat;

	need_clean = 0;
	pivot_treat = 0;
	while (*stack_a && (*stack_a)->e_type == PIVOT)
	{
		push_b(stack_a, stack_b, 1);
		(*stack_b)->e_type = SORTED;
	}
	if (!*stack_a)
		return ;
	if (optimisation(stack_a, stack_b, 'a'))
		return ;
	if (sorting_size(*stack_a) <= 20)
		return (insertion_sort_a(stack_a, stack_b));
	dispatch_a(stack_a, stack_b, pivot_treat, need_clean);
	while ((*stack_b) && (*stack_b)->e_type != SORTED)
		sort_b(stack_a, stack_b);
}

void	sort_three(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*max;

	max = find_max(*stack_a);
	if (max->next && max->next->next)
		rotate_a(stack_a, stack_b, 1);
	else if (max->next && !max->next->next)
		reverse_rotate_a(stack_a, stack_b, 1);
	if (!is_ascending_sort(*stack_a))
		swap_a(stack_a, stack_b, 1);
	(*stack_a)->e_type = SORTED;
}

void	little_sort(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*min;

	while (sorting_size(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		while ((*stack_a) != min)
		{
			if (!min->next || !min->next->next)
				reverse_rotate_a(stack_a, stack_b, 1);
			else if ((*stack_a)->next == min)
				swap_a(stack_a, stack_b, 1);
			else
				rotate_a(stack_a, stack_b, 1);
			min = find_min(*stack_a);
		}
		push_b(stack_a, stack_b, 1);
	}
	sort_three(stack_a, stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b, 1);
}
