/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:48:48 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 20:18:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elem_front(t_dlist **stack_a, t_dlist **stack_b, t_dlist *elem,
			char c)
{
	if (c == 'A')
	{
		if (pivot_placed_low(*stack_a, elem))
			while (*stack_a != elem)
				reverse_rotate_a(stack_a, stack_b, 1);
		else
			while (*stack_a != elem)
				rotate_a(stack_a, stack_b, 1);
	}
	else if (c == 'B')
	{
		if (pivot_placed_low(*stack_b, elem))
			while ((*stack_b) != elem)
				reverse_rotate_b(stack_a, stack_b, 1);
		else
			while ((*stack_b) != elem)
				rotate_b(stack_a, stack_b, 1);
	}
}

int	optimisation(t_dlist **stack_a, t_dlist **stack_b, char c)
{
	if (c == 'a')
	{
		if (ascending_part(*stack_a))
		{
			while ((*stack_a) && (*stack_a)->e_type != PIVOT)
			{
				push_b(stack_a, stack_b, 1);
				(*stack_b)->e_type = SORTED;
			}
			return (1);
		}
	}
	if (c == 'b')
	{
		if (descending_part(*stack_b))
		{
			(*stack_b)->e_type = SORTED;
			return (1);
		}
	}
	return (0);
}

void	insertion_sort_b(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_b && ((*stack_b)->e_type != SORTED || ((*stack_b)->e_type
				== SORTED && (*stack_b) != find_max(*stack_b))))
	{
		while ((*stack_b != find_max(*stack_b) && ((*stack_b)->e_type
					!= SORTED)) || ((*stack_b)->e_type == SORTED && (*stack_b)
				!= find_max(*stack_b)))
		{
			if (*stack_b && (*stack_b)->next && (*stack_b)->next
				== find_max(*stack_b))
				swap_b(stack_a, stack_b, 1);
			else
				push_elem_front(stack_a, stack_b, find_max(*stack_b), 'B');
		}
		push_a(stack_a, stack_b, 1);
	}
	(*stack_a)->e_type = PIVOT;
}

void	insertion_sort_a(t_dlist **stack_a, t_dlist **stack_b)
{
	while (*stack_a && ((*stack_a)->e_type != PIVOT || ((*stack_a)->e_type
				== PIVOT && (*stack_a) != find_min(*stack_a))))
	{
		while ((*stack_a != find_min(*stack_a) && ((*stack_a)->e_type != PIVOT))
			|| ((*stack_a)->e_type == PIVOT && (*stack_a)
				!= find_min(*stack_a)))
		{
			if (*stack_a && (*stack_a)->next && (*stack_a)->next
				== find_min(*stack_a))
				swap_a(stack_a, stack_b, 1);
			else
				push_elem_front(stack_a, stack_b, find_min(*stack_a), 'A');
		}
		push_b(stack_a, stack_b, 1);
	}
	(*stack_b)->e_type = SORTED;
}

int	pivot_placed_low(t_dlist *stack, t_dlist *elem)
{
	int	size_middle;
	int	i;

	i = 0;
	size_middle = dlist_size(stack) / 2;
	while (stack)
	{
		if (stack == elem)
			break ;
		stack = stack->next;
		i++;
	}
	if (i > size_middle)
		return (1);
	return (0);
}
