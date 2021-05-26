/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:27:35 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 13:07:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_size(t_dlist *lst)
{
	int	i;

	i = 0;
	while (lst && lst->e_type == RANDOM)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_dlist	*find_max(t_dlist *stack)
{
	t_dlist	*max;

	max = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (*(int *)(stack->data) > *(int *)(max->data))
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_dlist	*find_sorting_max(t_dlist *stack)
{
	t_dlist	*max;

	max = stack;
	if (!stack)
		return (NULL);
	while (stack && stack->e_type == RANDOM)
	{
		if (*(int *)(stack->data) > *(int *)(max->data))
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_dlist	*find_min(t_dlist *stack)
{
	t_dlist	*min;

	min = stack;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (*(int *)(stack->data) < *(int *)(min->data))
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_dlist	*find_sorting_min(t_dlist *stack)
{
	t_dlist	*min;

	min = stack;
	if (!stack)
		return (NULL);
	while (stack && stack->e_type == RANDOM)
	{
		if (*(int *)(stack->data) < *(int *)(min->data))
			min = stack;
		stack = stack->next;
	}
	return (min);
}
