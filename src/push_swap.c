/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:21:04 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 20:20:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_is_number(char *str)
{
	int			i;
	int			sign;
	long		nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	nb = nb * sign;
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	has_double(t_dlist *list)
{
	t_dlist	*cmp;

	cmp = list;
	while (cmp->next)
	{
		list = cmp;
		while (list->next)
		{
			list = list->next;
			if (*(int *)(cmp->data) == *(int *)(list->data))
				return (1);
		}
		cmp = cmp->next;
	}
	return (0);
}

void	create_stack(t_dlist **stack_a, int argc, char **argv)
{
	int		i;
	int		*nb;

	i = 1;
	while (i < argc)
	{
		if (!str_is_number(argv[i]))
		{
			printf("Error\n");
			ft_free_stack(*stack_a);
			exit(1);
		}
		nb = malloc(sizeof(int) * 1);
		*nb = ft_atoi(argv[i]);
		ft_list_push_back(stack_a, (void *)nb);
		i++;
	}
	if (has_double(*stack_a))
	{
		printf("Error\n");
		ft_free_stack(*stack_a);
		exit(1);
	}
}

void	push_swap(t_dlist **stack_a, t_dlist **stack_b)
{
	if (is_ascending_sort(*stack_a))
		return ;
	if (dlist_size(*stack_a) <= 3)
	{
		sort_three(stack_a, stack_b);
		return ;
	}
	if (sorting_size(*stack_a) <= 6)
	{
		little_sort(stack_a, stack_b);
		return ;
	}
	while (*stack_a && (*stack_a)->e_type != SORTED)
		sort_a(stack_a, stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b, 1);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	create_stack(&stack_a, argc, argv);
	push_swap(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	return (0);
}
