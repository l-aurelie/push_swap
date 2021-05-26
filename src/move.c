/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:12:29 by user42            #+#    #+#             */
/*   Updated: 2021/05/25 21:05:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *stack)
{
	void	*tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	push(t_dlist **stack_from, t_dlist **stack_to)
{
	void	*tmp;

	if (!*stack_from)
		return ;
	tmp = *stack_from;
	if ((*stack_from)->next)
		*stack_from = (*stack_from)->next;
	else
		*stack_from = NULL;
	ft_dlstadd_front(stack_to, tmp);
}

void	rotate(t_dlist **stack)
{
	void	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_dlstadd_back(stack, tmp);
}

void	reverse_rotate(t_dlist **stack)
{
	void	*tmp;
	t_dlist	*elem;

	if (!*stack || !(*stack)->next)
		return ;
	elem = *stack;
	if (!elem->next->next)
	{
		swap(*stack);
		return ;
	}
	while (elem->next->next)
		elem = elem->next;
	tmp = elem->next;
	elem->next = NULL;
	ft_dlstadd_front(stack, tmp);
}
