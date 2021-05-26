/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:56:51 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 21:41:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	swap(*stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	push_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		write(1, "pb\n", 3);
}

void	rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	rotate(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}
