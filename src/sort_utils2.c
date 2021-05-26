/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:01:22 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 13:02:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_medium(t_dlist *stack)
{
	t_dlist		*index;
	long long	all;
	int			size;

	index = stack;
	all = 0;
	size = 0;
	while (index && (index->e_type != SORTED && index->e_type != PIVOT))
	{
		all += *(int *)(index->data);
		size++;
		index = index->next;
	}
	all = all / size;
	return (all);
}

int	is_ascending_sort(t_dlist *list)
{
	while (list->next)
	{
		if (*(int *)(list->data) > *(int *)(list->next->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int	ascending_part(t_dlist *list)
{
	while (list->next && list->next->e_type != PIVOT)
	{
		if (*(int *)(list->data) > *(int *)(list->next->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_descending_sort(t_dlist *list)
{
	while (list->next)
	{
		if (*(int *)(list->data) < *(int *)(list->next->data))
			return (0);
		list = list->next;
	}
	return (1);
}

int	descending_part(t_dlist *list)
{
	while (list->next && list->next->e_type != SORTED)
	{
		if (*(int *)(list->data) < *(int *)(list->next->data))
			return (0);
		list = list->next;
	}
	return (1);
}
