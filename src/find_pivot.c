/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:14:49 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 20:11:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*find_pivot(t_dlist *stack)
{
	t_dlist	*pivot;
	t_pivot	piv;

	piv.max = calculate_medium(stack);
	piv.min = *(int *)(find_sorting_min(stack)->data);
	pivot = search_elem_bt_two_val(stack, piv.min, piv.max);
	piv.intervall = calculate_medium_intervall(stack);
	while (!pivot || (pivot && lower_greater_midline(stack, pivot)))
	{
		while ((!pivot || (pivot && lower_greater_midline(stack, pivot) == 1)))
		{
			search_midline(&piv, stack, &pivot, '>');
		}
		piv.min = *(int *)(find_sorting_min(stack)->data);
		while ((!pivot || (pivot && lower_greater_midline(stack, pivot) == -1)))
		{
			search_midline(&piv, stack, &pivot, '<');
		}
		piv.intervall = piv.intervall / 2;
	}
	pivot->e_type = PIVOT;
	return (pivot);
}

void	search_midline(t_pivot *piv, t_dlist *stack, t_dlist **pivot, char c)
{
	if (c == '>')
	{
		piv->min = piv->max;
		piv->max += piv->intervall;
		if (piv->max >= *(int *)(find_sorting_max(stack)->data) ||
			piv->max <= *(int *)(find_sorting_min(stack)->data))
		{
			piv->min -= piv->intervall;
			piv->max -= piv->intervall;
			piv->intervall = piv->intervall / 2;
		}
		*pivot = search_elem_bt_two_val(stack, piv->min, piv->max);
	}
	if (c == '<')
	{
		piv->max -= piv->intervall;
		piv->intervall = piv->intervall;
		if (piv->max <= piv->min)
		{
			piv->max += piv->intervall;
			piv->intervall = piv->intervall / 2;
		}
		*pivot = search_elem_bt_two_val(stack, piv->min, piv->max);
	}
}

int	calculate_medium_intervall(t_dlist *stack)
{
	long long	intervall_sum;
	int			intervall;
	int			size;

	intervall_sum = 0;
	size = 0;
	while (stack && stack->next && (stack->e_type != SORTED
			&& stack->e_type != PIVOT))
	{
		intervall = ft_abs(*(int *)(stack->data) - *(int *)(stack->next->data));
		intervall_sum += intervall;
		size++;
		stack = stack->next;
	}
	intervall_sum = intervall_sum / size;
	return (intervall_sum);
}

int	lower_greater_midline(t_dlist *stack, t_dlist *pivot_tested)
{
	int	lower;
	int	greater;

	lower = 0;
	greater = 0;
	while (stack && stack->e_type == RANDOM)
	{
		if (*(int *)(stack->data) > *(int *)(pivot_tested->data))
			greater += 1;
		else if (*(int *)(stack->data) < *(int *)(pivot_tested->data))
			lower += 1;
		stack = stack->next;
	}
	if (ft_abs(greater - lower) < 2)
		return (0);
	else if (greater - lower > 0)
		return (1);
	else if (greater - lower < 0)
		return (-1);
	return (0);
}

t_dlist	*search_elem_bt_two_val(t_dlist *stack, long min, long max)
{
	t_dlist	*elem;

	elem = NULL;
	while (stack && (stack->e_type == RANDOM))
	{
		if (*(int *)(stack->data) <= max && *(int *)(stack->data) >= min)
		{
			elem = stack;
			min = *(int *)(elem->data);
		}
		stack = stack->next;
	}
	return (elem);
}
