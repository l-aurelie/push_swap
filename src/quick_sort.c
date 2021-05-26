/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:45:14 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 15:06:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_after_sort(t_dlist **stack_a, t_dlist **stack_b, int need_clear,
			char c)
{
	if (c == 'A')
	{
		while (need_clear)
		{
			reverse_rotate_a(stack_a, stack_b, 1);
			if ((*stack_a)->e_type == PIVOT)
				push_b(stack_a, stack_b, 1);
			need_clear--;
		}
		if ((*stack_b)->e_type == PIVOT)
			push_a(stack_a, stack_b, 1);
	}
	if (c == 'B')
	{
		while (need_clear)
		{
			reverse_rotate_b(stack_a, stack_b, 1);
			if ((*stack_b)->e_type == PIVOT)
				push_a(stack_a, stack_b, 1);
			need_clear--;
		}
	}
}

int	should_clean(t_dlist *stack)
{
	int	count_pivot;

	count_pivot = 0;
	while (stack)
	{
		if (stack->e_type == SORTED)
			return (1);
		if (stack->e_type == PIVOT)
			count_pivot++;
		if (count_pivot > 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	dispatch_b(t_dlist **stack_a, t_dlist **stack_b, int pivot_treat,
			int need_clean)
{	
	t_dlist	*pivot;

	pivot = find_pivot(*stack_b);
	while (!pivot_dispatch_finished(*stack_b, pivot, 'B') || !pivot_treat)
	{
		if ((*stack_b)->e_type == PIVOT)
			pivot_treat = 1;
		if (*(int *)(*stack_b)->data > *(int *)pivot->data)
			push_a(stack_a, stack_b, 1);
		else
		{
			rotate_b(stack_a, stack_b, 1);
			need_clean++;
		}
	}
	if ((*stack_b)->next)
	{
		if (should_clean(*stack_b))
			clean_after_sort(stack_a, stack_b, need_clean, 'B');
		else
		{
			push_elem_front(stack_a, stack_b, pivot, 'B');
			push_a(stack_a, stack_b, 1);
		}
	}
}

void	dispatch_a(t_dlist **stack_a, t_dlist **stack_b, int pivot_treat,
			int need_clean)
{	
	t_dlist	*pivot;

	pivot = find_pivot(*stack_a);
	while (!pivot_dispatch_finished(*stack_a, pivot, 'A') || !pivot_treat)
	{
		if ((*stack_a)->e_type == PIVOT)
			pivot_treat = 1;
		if (*(int *)(*stack_a)->data < *(int *)pivot->data)
			push_b(stack_a, stack_b, 1);
		else
		{
			rotate_a(stack_a, stack_b, 1);
			need_clean++;
		}
	}
	if (should_clean(*stack_a))
		clean_after_sort(stack_a, stack_b, need_clean, 'A');
	else
		push_elem_front(stack_a, stack_b, pivot, 'A');
}

int	pivot_dispatch_finished(t_dlist *stack, t_dlist *pivot, char c)
{
	if (c == 'A')
	{
		while (stack)
		{
			if (*(int *)(stack->data) < *(int *)(pivot->data))
				return (0);
			stack = stack->next;
		}
	}
	else if (c == 'B')
	{
		while (stack)
		{
			if (*(int *)(stack->data) > *(int *)(pivot->data))
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}
