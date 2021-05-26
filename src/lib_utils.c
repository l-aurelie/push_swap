/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:37:49 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 12:29:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_intlist(t_dlist *begin, char c)//#
{
	printf("stack %c\n", c);
	if (!begin)
		return ;
	while (begin)
	{
		printf("%d (%d)\n", *((int *)(begin->data)), begin->e_type);
		begin = begin->next;
	}
}*/

int	dlist_size(t_dlist *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_free_stack(t_dlist *begin_list)
{
	t_dlist	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = tmp;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
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
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}
