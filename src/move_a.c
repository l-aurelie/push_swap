/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:56:34 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 15:03:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_b;
	swap(*stack_a);
	if (print)
		printf("sa\n");
}

void	push_a(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	push(stack_b, stack_a);
	if (print)
		printf("pa\n");
}

void	rotate_a(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_b;
	rotate(stack_a);
	if (print)
		printf("ra\n");
}

void	reverse_rotate_a(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_b;
	reverse_rotate(stack_a);
	if (print)
		printf("rra\n");
}
