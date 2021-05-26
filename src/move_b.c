/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:56:51 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 15:02:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	swap(*stack_b);
	if (print)
		printf("sb\n");
}

void	push_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	push(stack_a, stack_b);
	if (print)
		printf("pb\n");
}

void	rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	rotate(stack_b);
	if (print)
		printf("rb\n");
}

void	reverse_rotate_b(t_dlist **stack_a, t_dlist **stack_b, int print)
{
	(void)stack_a;
	reverse_rotate(stack_b);
	if (print)
		printf("rrb\n");
}
